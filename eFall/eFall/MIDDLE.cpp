#include "MIDDLE.h"

int indiceX = 0;
int indiceY = 0;
int indiceZ = 0;
int indiceM = 0;

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
	if (indiceX == FIFO_SIZE) indiceX = 0;
	this->fifoX[indiceX] = x;
	indiceX++;
}

void MIDDLE::feedFifoY(float y) {
	if (indiceY == FIFO_SIZE) indiceY = 0;
	this->fifoY[indiceY] = y;
	indiceY++;
}

void MIDDLE::feedFifoZ(float z) {
	if (indiceZ == FIFO_SIZE) indiceZ = 0;
	this->fifoZ[indiceZ] = z;
	indiceZ++;
}

void MIDDLE::feedFifoA(void) {
	for (int i = 0; i < 256; i++) {
		float a = sqrt((pow(this->fifoX[i], 2) + pow(this->fifoY[i], 2) + pow(this->fifoZ[i], 2)));
		fifoA[i] = a;
	}
}

void MIDDLE::feedFifoM(void) {
	if (indiceM == FIFO_SIZE) indiceM = 0;
	float aSum = 0;
	for (int i = 0; i < FIFO_SIZE; i++) {
		aSum += this->fifoA[i];
	}
	this->fifoM[indiceM] = aSum / FIFO_SIZE;
	indiceM++;
	
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
