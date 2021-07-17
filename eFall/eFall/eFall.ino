/** @brief eFall main:
	Used to run the program reading the acceleration valus, and detects a fall.
    @author Fabio Lameira, Celsio Gil, Luis Duarte Marques.
    @date July 2021
*/
#include "App.h"
#include "Middle.h"
#include "NRF52_MBED_TimerInterrupt.h"
#include "NRF52_MBED_ISR_Timer.h"

/** Timer Configurations: */
#define TIMER_INTERVAL_MS 1
#define TIMER_COUNTER_INTERVAL 1000
NRF52_MBED_Timer ITimer(NRF_TIMER_3);
NRF52_MBED_ISR_Timer ISR_Timer;

/** Volatile Variables to use with the timer: */
volatile char flagTimer = FALSE;
volatile char flagInterval = FALSE;
volatile char flagNotify = TRUE;
volatile int timerCounter = FALSE;

/** Instantiate App and Middle classes: */
App app = App();
Middle middle = Middle();

/** setup() method:
	Used to initialize all the configuration we need to run the program.
	Initialize Serial Port.
	Initialize IMU from Arduino library to start reading accelerations.
	Configure Timer to run every X milliseconds.
*/
void setup() {
	// SERIAL Initialization
	Serial.begin(9600);
	delay(100);
	
	// IMU Initialization
	Serial.println("IMU initializing...");
	if (middle.begin()) Serial.println("IMU initialized");
	else Serial.println("IMU Error");
		
	// TIMER Initialization
	if (ITimer.attachInterruptInterval(1000, timerHandler)) {
		Serial.print(F("Starting ITimer OK, millis() = ")); 
		Serial.println(millis());
	} else {
		Serial.println(F("Can't set Timer. Select another freq. or timer"));
	}

	// TIMER interval configuration
	ISR_Timer.setInterval(TIMER_INTERVAL_MS,  changeFlagTimer);
}

/** loop() method:
	This method is the program cycle. Used to run the actual program.
	Call the Middle to read acceleration values and store them.
	Call the Middle to feed fifos with the total acceleration and moving median.
	Check if the device state is FALL and call the App to notify a fall through Serial Port.
*/
void loop() {
	if (flagTimer == TRUE) {
		middle.readValues();
		middle.feedFifos(flagInterval);
		
		if (middle.getState() == STATE_FALL && flagNotify == TRUE) {
			app.notifyFall();
			flagNotify = FALSE;
		}
		
		flagTimer = FALSE;
	}
}

/** timerHandler() method:
	Call the Timer library to run the method configured to this timer.
*/
void timerHandler() {
	ISR_Timer.run();
}

/** changeFlagTimer() method:
	Change the timer flags to run the code every time the timer hits.
	Every time the timer is called, changes the flagTimer to TRUE.
	When device state is PRE_FALL or FALL, the timer starts to count until X timer interval (ex: 1 second)
	Then, when the counter is equals to interval, changes the flagInterval and flagNotify to TRUE.
*/
void changeFlagTimer() {
	if (middle.getState() == STATE_PRE_FALL || middle.getState() == STATE_FALL) {
		if (timerCounter == TIMER_COUNTER_INTERVAL) {
			flagInterval = TRUE;
			flagNotify = TRUE;
			timerCounter = FALSE;
		} else {
			timerCounter++;	
		}
	} else {
		flagInterval = FALSE;
	}
	flagTimer = TRUE;
}