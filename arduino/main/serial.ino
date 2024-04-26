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

