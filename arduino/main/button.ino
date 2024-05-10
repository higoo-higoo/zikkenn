const int eyeblowButton = 4;
const int eyeButton = 2;
const int noseButton = 3;
const int leftmouthButton = 5;
const int rightmouthButton = 6;

const int INPUTPORTS[5] = {eyeblowButton, eyeButton, noseButton, leftmouthButton, rightmouthButton};

// ONOFF
int input_count[5];
int last_input_state[5];
unsigned long last_debounce_time[5];
unsigned long debounce_delay = 50; // デバウンスのディレイ時間（ミリ秒）

void buttonSetup()
{
  for (int i = 0; i < 5; i++)
  {
    pinMode(INPUTPORTS[i], INPUT);
    input_count[i] = 0;
    last_input_state[i] = LOW;
    last_debounce_time[i] = 0;
  }
}

void buttonLoop()
{
  if (millis() < 1000) {
    // Serial.println("stand by");
    return;
  }
  for (int i = 0; i < 5; i++)
  {
    int reading = digitalRead(INPUTPORTS[i]);
    if (reading != last_input_state[i]) {
      last_debounce_time[i] = millis();
    }
    if ((millis() - last_debounce_time[i]) > debounce_delay) {
      if (reading == HIGH) {
        input_count[i]++;
      } else {
        input_count[i] = 0;
      }
    }if (input_count[i] > 20) {
      input_count[i] = 0;
      output[i] = 0;
    }
    last_input_state[i] = reading;
  }
}
