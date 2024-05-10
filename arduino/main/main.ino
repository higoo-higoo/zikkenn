const int EYEBLOWPORT = 8;
const int EYEPORT = 9;
const int NOSEPORT = 10;
const int LEFTMOUTHPORT = 11;
const int RIGHTMOUTHPORT = 12;

const int OUTPUTPORTS[5] = {EYEBLOWPORT, EYEPORT, NOSEPORT, LEFTMOUTHPORT, RIGHTMOUTHPORT};

int output[5];
int change[5];


void setup() {
  serialSetup();
  buttonSetup();
  for (int i = 0; i < 5; i++)
  {
    pinMode(OUTPUTPORTS[i], OUTPUT);
    output[i] = 1;
    change[i] = 0;
  }
}

void loop() {
  // serialLoop();
  buttonLoop();
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(OUTPUTPORTS[i], output[i]);
    if (output[i] == 0 && change[i] == 0)
    {
      // Serial.print("change id");
      // Serial.print(i);
      // Serial.print("change");
      // change[i] = 1;
      // Serial.println(change[i]);
    }
  }
  delay(1);
}


