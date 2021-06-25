/* 
	Editor: https://www.visualmicro.com/
			visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			the contents of the _vm sub folder can be deleted prior to publishing a project
			all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Nano 33 BLE, Platform=mbed_nano, Package=arduino
*/

#define ARDUINO 108013
#define ARDUINO_MAIN
#define printf iprintf
#define __MBED_NANO__
#define ARDUINO_ARCH_NRF52840
#define ARDUINO_ARDUINO_NANO33BLE
#define ARDUINO_ARCH_MBED_NANO
#define ARDUINO_LIBRARY_DISCOVERY_PHASE 0
#include "mbed_config.h" 
#include "pinmode_arduino.h" 
#include "pins_arduino.h" 
#include "arduino.h"
#include "eFall.ino"
