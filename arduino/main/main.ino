const int EYEBLOWPORT = 8;
const int EYEPORT = 9;
const int NOSEPORT = 10;
const int LEFTMOUTHPORT = 11;
const int RIGHTMOUTHPORT = 12;

const int OUTPUTPORTS[5] = {EYEBLOWPORT, EYEPORT, NOSEPORT, LEFTMOUTHPORT, RIGHTMOUTHPORT};


int output[5] = {0, 0, 0, 0, 0};

void setup() {
  serialSetup();
  buttonSetup();
  for (int i = 0; i < 5; i++)
  {
    pinMode(OUTPUTPORTS[i], OUTPUT);
  }
}

void loop() {
  // serialLoop();
  buttonLoop();
  outputUpdate();
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(OUTPUTPORTS[i], output[i]);
    if (OUTPUTPORTS[i] == 8)
    {
      Serial.print("Eyeblow: ");
      Serial.println(output[i]);
    }
  }
  digitalWrite(EYEBLOWPORT, HIGH);
}


