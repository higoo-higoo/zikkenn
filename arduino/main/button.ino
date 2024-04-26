const int eyeblowButton = 2;
const int eyeButton = 3;
const int noseButton = 4;
const int leftmouthButton = 5;
const int rightmouthButton = 6;

const int INPUTPORTS[5] = {eyeblowButton, eyeButton, noseButton, leftmouthButton, rightmouthButton};

// ONOFF
int input_count[5] = {0, 0, 0, 0, 0};


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
    if (input) {
      input_count[i]++;
    } else {
      input_count[i] = 0;
    }
    if (input_count[i] > 5) {
      output[i] = 0;
    }
  }
}
