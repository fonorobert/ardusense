#include <Wire.h>

#define MASTERID 0
#define SLAVEID 1

#define BYTEA 0x10
#define BYTEB 0x20

int receive_count = 0;

void setup() {
	Wire.begin(SLAVEID);
	Wire.onReceive(receiveEvent);
	Wire.onRequest(requestEvent);
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
}

void loop() {
	delay(50);
}

void receiveEvent(int count) {
	byte indata = Wire.read();
	
	if(indata == BYTEA) {
		receive_count++;
	}
}

void requestEvent() {
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	Wire.write(receive_count);
}
