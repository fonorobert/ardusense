#include <Wire.h>

#define MASTERID 0
#define SLAVEID 1

#define BYTEA 0x10
#define BYTEB 0x20

int byte_a, byte_b;
void setup() {
	Wire.begin();
	Serial.begin(9600);
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
}

void loop() {
	//Serial.println("starting transmission");
	//Wire.beginTransmission(SLAVEID);

	//Wire.write(BYTEA);
	//Serial.println("sending 0x10");

	//Wire.endTransmission();
	//Serial.println("transmission ended, requesting");
	digitalWrite(13, HIGH);	
	Wire.requestFrom(SLAVEID, 1);
	Serial.println("request sent");
	digitalWrite(13, LOW);
	if(Wire.available()) {
		Serial.println("data received");
		byte_a = Wire.read();
		
		Serial.print("RX data: ");
		Serial.println(byte_a);
	}	
	delay(1000);
}
