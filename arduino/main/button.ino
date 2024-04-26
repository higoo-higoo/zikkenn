const int eyeblowButton = 2;
const int eyeButton = 3;
const int noseButton = 4;
const int leftmouthButton = 5;
const int rightmouthButton = 6;

const int INPUTPORTS[5] = {eyeblowButton, eyeButton, noseButton, leftmouthButton, rightmouthButton};

// ONOFF
int prev_input[5] = {0, 0, 0, 0, 0};

//
int prev_0_count[5] = {0, 0, 0, 0, 0};

// time_from last change
float time_last_change[5] = {0, 0, 0, 0, 0};

void buttonSetup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(INPUTPORTS[i], INPUT);
  }
}

void buttonLoop()
{
  for (int i = 0; i < 5; i++)
  {
    int input = digitalRead(INPUTPORTS[i]);

    if (i == 0) {
      Serial.print("Eyeblow: ");
      Serial.println(input);
    }
    if (input){
      prev_0_count[i] = 0;
    if (!prev_input[i]){
      time_last_change[i] = millis();
      prev_input[i] = input;
      // Serial.print("Button ");
      // Serial.print(i);
      // Serial.print(" is ");
      // Serial.println(input);
    }
    } else if (prev_input[i]) {
      prev_0_count[i]++;
      if (prev_0_count[i] > 5)
      {
        prev_input[i] = 0;
        time_last_change[i] = millis();
        prev_0_count[i] = 0;
      }
    }
  }
}

void outputUpdate() {
  for (int i = 0; i < 5; i++)
  {
    if (millis() - time_last_change[i] > 1000 / 16)
    {
      output[i] = 0;
    } else {
      output[i] = 1;
    }
    if (i == 0)
    {
      // Serial.print("Eyeblow: ");
      // Serial.println(output[i]);
    }
  }
}

