#include "MIDDLE.h"
#include "NRF52_MBED_TimerInterrupt.h"
#include "NRF52_MBED_ISR_Timer.h"

// Timer Configs
#define TIMER_INTERVAL_MS 10
NRF52_MBED_Timer ITimer(NRF_TIMER_3);
NRF52_MBED_ISR_Timer ISR_Timer;
volatile char flagTimer = 0;

// MIDDLE class instance
MIDDLE middle = MIDDLE();

void setup() {
	// SERIAL Initialization
	Serial.begin(9600);
	delay(100);
	
	// IMU Initialization
	Serial.println("IMU initializing...");
	int state = middle.begin();
	if (state)
		Serial.println("IMU initialized");
	else
		Serial.println("IMU Error");
		
	// TIMER Initialization
	if (ITimer.attachInterruptInterval(1000, timerHandler)) {
		Serial.print(F("Starting ITimer OK, millis() = ")); Serial.println(millis());
	} else
		Serial.println(F("Can't set ITimer. Select another freq. or timer"));
	
	ISR_Timer.setInterval(TIMER_INTERVAL_MS,  changeFlagTimer);
}

void loop() {
	
	if (flagTimer == 1) {	
		middle.readValues();
		middle.feedFifoA();
		middle.feedFifoM();
		flagTimer = 0;
	}
	
	if (Serial.available() > 0) {
		switch (Serial.read()) {
			case '1':
				Serial.println("Carregaste no 1");
				middle.printFifoA();
				break;
			case '2':
				Serial.println("Carregaste no 2");
				middle.printFifoM();
				break;
			default:
				break;
		}
	}
}

void timerHandler() {
	ISR_Timer.run();
}

void changeFlagTimer() {
	flagTimer = 1;
}