#ifndef _MIDDLE_H
#define _MIDDLE_H 1
#include <Arduino_LSM9DS1.h>
#include <math.h>
#include "App.h"

#define FIFO_SIZE 255

#define IDDLE 1
#define PRE_FALL 2
#define FALL 3

class Middle {
private:
	float x, y, z;
	float fifoA[FIFO_SIZE];
	float fifoM[FIFO_SIZE];
	int index;
	char state;
	
	void handleState(float m, char flag2Seconds);
public:
	Middle();
	char getState(void);
	int begin(void);
	int end(void);
	void readValues(void);
	void feedFifos(char flag2Seconds);	
	void printFifoA(void);
	void printFifoM(void);
};

#endif /* MIDDLE_H_ */

