#include "MIDDLE.h"



MIDDLE::MIDDLE() {
}

float MIDDLE::getX() {
	return this->x;
}

void MIDDLE::setX(float x) {
	this->x = x;
}

float MIDDLE::getY() {
	return this->y;
}

void MIDDLE::setY(float y) {
	this->y = y;
}

float MIDDLE::getZ() {
	return this->z;
}

void MIDDLE::setZ(float z) {
	this->z = z;
}

int MIDDLE::begin() {
	return IMU.begin();
}

int MIDDLE::end() {
	IMU.end();
}

void MIDDLE::readValues() {
	float x, y, z;
	if (IMU.accelerationAvailable()) {
		IMU.readAcceleration(x, y, z);
		this->setX(x);
		this->setY(y);
		this->setZ(z);
	}
}

float MIDDLE::getFifoA(int pos) {
	return this->fifoA[pos];
}

float MIDDLE::getFifoM(int pos) {
	return this->fifoM[pos];
}

void MIDDLE::feedFifoA(void) {
	if (indexA == FIFO_SIZE) indexA = 0;
	lastA = fifoA[indexA];
	float a = sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)));
	fifoA[indexA] = a;
	indexA++;
}

void MIDDLE::feedFifoM(void) {
	if (indexM == FIFO_SIZE) indexM = 0;
	float lastM = fifoM[indexM - 1];
	float newM = lastM - (lastA / FIFO_SIZE) + (fifoA[indexM] / FIFO_SIZE);
	fifoM[indexM] = newM;
	Serial.println((String) newM + ";");
	indexM++;
}

void MIDDLE::printFifoA() {
	for (int i = 0; i < FIFO_SIZE; i++) {
		Serial.println(" A: " + (String) this->getFifoA(i));
	}
}

void MIDDLE::printFifoM() {
	for (int i = 0; i < FIFO_SIZE; i++) {
		Serial.println(" M: " + (String) this->getFifoM(i));
	}
}
