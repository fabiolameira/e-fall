#include "App.h"
#include "Middle.h"
#include "NRF52_MBED_TimerInterrupt.h"
#include "NRF52_MBED_ISR_Timer.h"

// Timer Configs
#define TIMER_INTERVAL_MS 1
NRF52_MBED_Timer ITimer(NRF_TIMER_3);
NRF52_MBED_ISR_Timer ISR_Timer;
volatile char flagTimer = 0;
volatile char flagInterval = 0;
volatile int timerCounter = 0;
char notify = 1;

// APP and MIDDLE class instance
App app = App();
Middle middle = Middle();

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
		middle.feedFifos(flagInterval);
		
		if (middle.getState() == FALL && notify == 1) {
			app.notifyFall();
			notify = 0;
		}
		
		flagTimer = 0;
	}
}

void timerHandler() {
	ISR_Timer.run();
}

void changeFlagTimer() {
	if (middle.getState() == PRE_FALL || middle.getState() == FALL) {
		if (timerCounter == 1000) {
			flagInterval = 1;
			notify = 1;
			timerCounter = 0;
		} else {
			timerCounter++;	
		}
	} else {
		flagInterval = 0;
	}
	flagTimer = 1;
}