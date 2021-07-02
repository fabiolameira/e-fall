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

void MIDDLE::printValues() {
	Serial.println("==============================");
	Serial.println("X: " + (String) this->getX() + " Y: " + (String) this->getY() + " Z: " + (String) this->getZ());
}

float MIDDLE::getFifoX(int pos) {
	return this->fifoX[pos];
}

float MIDDLE::getFifoY(int pos) {
	return this->fifoY[pos];
}

float MIDDLE::getFifoZ(int pos) {
	return this->fifoZ[pos];
}

float MIDDLE::getFifoA(int pos) {
	return this->fifoA[pos];
}

float MIDDLE::getFifoM(int pos) {
	return this->fifoM[pos];
}

void MIDDLE::feedFifoX(float x) {
	if (indexX == FIFO_SIZE) indexX = 0;
	this->fifoX[indexX] = x;
	indexX++;
}

void MIDDLE::feedFifoY(float y) {
	if (indexY == FIFO_SIZE) indexY = 0;
	this->fifoY[indexY] = y;
	indexY++;
}

void MIDDLE::feedFifoZ(float z) {
	if (indexZ == FIFO_SIZE) indexZ = 0;
	this->fifoZ[indexZ] = z;
	indexZ++;
}

void MIDDLE::feedFifoA(void) {
	if (indexA == FIFO_SIZE) indexA = 0;
	lastA = this->fifoA[indexA];
	float a = sqrt((pow(this->fifoX[indexA], 2) + pow(this->fifoY[indexA], 2) + pow(this->fifoZ[indexA], 2)));
	this->fifoA[indexA] = a;
	indexA++;
}

void MIDDLE::feedFifoM(void) {
	if (indexM == FIFO_SIZE) indexM = 0;
	float lastM = this->fifoM[indexM - 1];
	float newM = lastM - (lastA / FIFO_SIZE) + (this->fifoA[indexA] / FIFO_SIZE);
	this->fifoM[indexM] = newM;
	indexM++;
}

void MIDDLE::printFifos() {
	for (int i = 0; i < FIFO_SIZE; i++) {
		Serial.println("X: " + (String) this->getFifoX(i) + " Y: " + (String) this->getFifoY(i) + " Z: " + (String) this->getFifoZ(i) + " A: " + (String) this->getFifoA(i));
		Serial.println("=================================================");
	}
}

void MIDDLE::printFifoM() {
	for (int i = 0; i < FIFO_SIZE; i++) {
		Serial.println(" M: " + (String) this->getFifoM(i));
		Serial.println("=================================================");
	}
}
