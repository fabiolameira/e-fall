#include "MIDDLE.h"

MIDDLE middle = MIDDLE();

void setup() {
	// SERIAL Comm Init
	Serial.begin(9600);
	delay(100);
	
	Serial.println("Estou vivo.");
	
	// IMU Init
	Serial.println("IMU initializing...");
	int state = middle.begin();
	if (state)
		Serial.println("IMU initialized");
	else
		Serial.println("IMU Error");		
}

void loop() {
	
	middle.begin();
	middle.readValues();
	middle.feedFifoX(middle.getX());
	middle.feedFifoY(middle.getY());
	middle.feedFifoZ(middle.getZ());
	middle.feedFifoA();
	
	if (Serial.available() > 0) {
		switch (Serial.read()) {
		case '1':
			Serial.println("Carregaste no 1");
			middle.printFifos();
			break;
		case '2':
			Serial.println("Carregaste no 2");
			middle.feedFifoM();
			middle.printFifoM();
			break;
		case '3':
			Serial.println("Carregaste no 3");
			break;
		default:
			break;
		}
	}
}
