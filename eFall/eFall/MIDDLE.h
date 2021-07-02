#ifndef _MIDDLE_H
#define _MIDDLE_H 1
#include <Arduino_LSM9DS1.h>
#include <math.h>

#define FIFO_SIZE 255

class MIDDLE {
 private:
	float x, y, z;
	float fifoX[FIFO_SIZE];
	float fifoY[FIFO_SIZE];
	float fifoZ[FIFO_SIZE];
	float fifoA[FIFO_SIZE];
	float fifoM[FIFO_SIZE];
	int indexX = 0;
	int indexY = 0;
	int indexZ = 0;
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
	void printValues(void);
	
	float getFifoX(int pos);
	float getFifoY(int pos);
	float getFifoZ(int pos);
	float getFifoA(int pos);
	float getFifoM(int pos);
	
	void feedFifoX(float x);
	void feedFifoY(float y);
	void feedFifoZ(float z);
	void feedFifoA(void);
	void feedFifoM(void);
	
	void printFifos(void);
	void printFifoM(void);

};

#endif /* MIDDLE_H_ */

