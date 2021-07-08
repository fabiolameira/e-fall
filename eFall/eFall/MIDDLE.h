#ifndef _MIDDLE_H
#define _MIDDLE_H 1
#include <Arduino_LSM9DS1.h>
#include <math.h>

#define FIFO_SIZE 255

class MIDDLE {
 private:
	float x, y, z;
	float fifoA[FIFO_SIZE];
	float fifoM[FIFO_SIZE];
	int indexA = 0;
	int indexM = 0;
	float lastA = 0;

 public:
	MIDDLE();
	float getX(void);
	void setX(float x);	
	float getY(void);
	void setY(float y);
	float getZ(void);
	void setZ(float z);
	
	int begin(void);
	int end(void);
	void readValues(void);
	
	float getFifoA(int pos);
	float getFifoM(int pos);

	void feedFifoA(void);
	void feedFifoM(void);
	
	void printFifoA(void);
	void printFifoM(void);
};

#endif /* MIDDLE_H_ */

