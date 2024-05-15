// const int eyeblowButton = 4;
// const int eyeButton = 2;
// const int noseButton = 3;
// const int leftmouthButton = 5;
// const int rightmouthButton = 6;
//
// const int INPUTPORTS[5] = {eyeblowButton, eyeButton, noseButton, leftmouthButton, rightmouthButton};

const int INPUTPORT = 4;

// ONOFF
int input_count;
int last_input_state;
unsigned long last_debounce_time;
unsigned long debounce_delay = 50; // デバウンスのディレイ時間（ミリ秒）
int phase = 0;
bool interval = false;

void buttonSetup()
{
  pinMode(INPUTPORT, INPUT);
  input_count = 0;
  last_input_state = LOW;
  last_debounce_time = 0;
}

void buttonLoop()
{
  if (interval) {
    delay(800);
    interval = false;
  }
  if (millis() < 1000) {
    // Serial.println("stand by");
    return;
  }
  int reading = digitalRead(INPUTPORT);
  if (reading != last_input_state) {
    last_debounce_time = millis();
  }
  if ((millis() - last_debounce_time) > debounce_delay) {
    if (reading == HIGH) {
      input_count++;
    } else {
      input_count = 0;
    }
  } if (input_count > 20) {
    input_count = 0;
    output[phase] = 0;
    phase++;
    interval = true;
  }
  last_input_state = reading;
}
