/** @brief Middle.h class headers
    Used to read acceleration in x, y and z axis, and detect the fall.
    @author Fabio Lameira, Celsio Gil, Luis Duarte Marques.
    @date July 2021
*/
#ifndef _MIDDLE_H
#define _MIDDLE_H 1
#include <Arduino_LSM9DS1.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define FIFO_SIZE 255

#define STATE_IDDLE 1
#define STATE_PRE_FALL 2
#define STATE_FALL 3

#define MIN_THRESHOLD 0.5
#define MAX_THRESHOLD 1.8

class Middle {
private:
	float x, y, z;										/** float values to store the acceleration in x, y, and z axis. */
	float fifoA[FIFO_SIZE];								/** float array to store total accelerations. */
	float fifoM[FIFO_SIZE];								/** float array to store moving median of accelerations. */
	int index;											/** int value to use as index of fifoA and fifoM arrays. */
	char state;											/** char value to store the current state of the device (IDDLE, PRE_FALL, FALL). */
	
	void handleState(float m, char flag2Seconds);		/** private internal function to handle device state. */
public:
	Middle();											/** Default Middle class constructor. */
	char getState(void);								/** Get state attribute. @return state */
	int begin(void);									/** Initializes the IMU library to start acceleration readings. @return successCode */
	void readValues(void);								/** Use IMU library to read and store acceleration values in the different axis. */
	void feedFifos(char flagInterval);					/** Feed acceleration and moving median arrays, and handle device states. @param flagInterval */
};

#endif /* MIDDLE_H_ */

