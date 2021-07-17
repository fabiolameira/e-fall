/** @brief Middle.h class implementation
    Used to read acceleration in x, y and z axis, and detect the fall.
    @author Fabio Lameira, Celsio Gil, Luis Duarte Marques.
    @date July 2021
*/

/**
  Code adapted from third-party Arduino library:
  https://www.arduino.cc/en/Reference/ArduinoLSM9DS1
*/

#include "Middle.h"

/** Middle() is a default constructor:
	Initialize index with 0.
	Initialize state with IDDLE.
*/
Middle::Middle() {
	this->index = 0;
	this->state = STATE_IDDLE;
}

/** getState() public method:
	Get value stored in state attribute.
	@return state.
*/
char Middle::getState() {
	return this->state;
}

/** begin() public method:
	Initializes IMU to start reading acceleration in different axis.
	@return succesCode.
*/
int Middle::begin() {
	return IMU.begin();
}

/** readValues() public method:
	Verify if IMU accelerations are available, and store them into x, y, and z attributes.
*/
void Middle::readValues() {
	float x, y, z;
	if (IMU.accelerationAvailable()) {
		IMU.readAcceleration(x, y, z);
		this->x = x;
		this->y = y;
		this->z = z;
	}
}

/** feedFifos() public method:
	Use the x, y, and z accelerations to calculate the total acceleration and put that in fifoA array (FirstInFirstOut).
	Use the total acceleration values in fifoA to calculate the moving median and store that in fifoM array.
	Call handleState() method to change the device state according to the new moving median.
	@param flagInterval (Used to change from PRE_FALL to IDDLE state when some time have passed).
*/
void Middle::feedFifos(char flagInterval) {
	if (index == FIFO_SIZE) index = 0;
	
	float lastA = fifoA[index];
	float a = sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
	fifoA[index] = a;
	
	float lastM = fifoM[index - 1];
	float newM = lastM - (lastA / FIFO_SIZE) + (fifoA[index] / FIFO_SIZE);
	fifoM[index] = newM;
	
	this->handleState(newM, flagInterval);	
	index++;
}

/** handleState() private method:
	When state is IDDLE and new moving median is less then MIN_THRESHOLD, change the state to PRE_FALL.
	When state is PRE_FALL and new moving median is more than MAX_THRESHOLD, change the state to FALL.
	When state is PRE_FALL and flagInterval its TRUE, change the state back to IDDLE.
	When state is FALL and flagInterval its TRUE, change the state back to IDDLE.
	@param m (new moving median).
	@param flagInterval (Used to change from PRE_FALL to IDDLE state when some time have passed).
*/
void Middle::handleState(float m, char flagInterval) {
	if (state == STATE_IDDLE && m < MIN_THRESHOLD) {
		state = STATE_PRE_FALL;
	}
	if (state == STATE_PRE_FALL) {
		if (m > MAX_THRESHOLD) {
			state = STATE_FALL;
		} 
		else if (flagInterval == TRUE) {
			state = STATE_IDDLE;
		}
	}
	if (state == STATE_FALL && flagInterval == TRUE) {
		state = STATE_IDDLE;
	}	
}