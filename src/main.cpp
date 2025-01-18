#include <Arduino.h>
#include <Adafruit_Fingerprint.h>

class Finger {
private:
	int status;
	HardwareSerial& mySerial;
	Adafruit_Fingerprint finger;
public:
	Finger(HardwareSerial& serialPort) : mySerial(serialPort), finger(&mySerial) {}

	void begin() {
		mySerial.begin(57600, SERIAL_8N1, 16, 17);
		if (finger.verifyPassword()) Serial.println("Fingerprint sensor ready!");
		else {
			Serial.println("Fingerprint sensor not found!");
			while (1);
		}
	}
};

Finger finger(Serial2);

void setup() {
	Serial.begin(115200);
	finger.begin();
}

void loop() {
}

