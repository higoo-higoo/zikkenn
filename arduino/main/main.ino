const int EYEBLOWPORT = 8;
const int EYEPORT = 9;
const int NOSEPORT = 10;
const int LEFTMOUTHPORT = 11;
const int RIGHTMOUTHPORT = 12;

int eyeblow = 0;
int eye = 0;
int nose = 0;
int leftmouth = 0;
int rightmouth = 0;

void serialSetup() {
	Serial.begin(9600);
}

void serialLoop() {
	if (Serial.available() > 0) {
		char letter = Serial.read();
		if (letter == 'b') { // eyeblow
      eyeblow = Serial.parseInt();
		} else if (letter == 'e') { // eye
      eye = Serial.parseInt();
    } else if (letter == 'n') { // nose
      nose = Serial.parseInt();
    } else if (letter == 'l') { // left mouth
      leftmouth = Serial.parseInt();
    } else if (letter == 'r') { // right mouth
      rightmouth = Serial.parseInt();
    }
	}
}
void setup() {
  serialSetup();
  pinMode(EYEBLOWPORT, OUTPUT);
  pinMode(EYEPORT, OUTPUT);
  pinMode(NOSEPORT, OUTPUT);
  pinMode(LEFTMOUTHPORT, OUTPUT);
  pinMode(RIGHTMOUTHPORT, OUTPUT);
}

void loop() {
  serialLoop();
  digitalWrite(EYEBLOWPORT, eyeblow);
  digitalWrite(EYEPORT, eye);
  digitalWrite(NOSEPORT, nose);
  digitalWrite(LEFTMOUTHPORT, leftmouth);
  digitalWrite(RIGHTMOUTHPORT, rightmouth);
}


