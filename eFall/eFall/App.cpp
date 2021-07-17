/** @brief App.h class implementation
    Used to notify a fall via Serial Port.
    @author Fabio Lameira, Celsio Gil, Luis Duarte Marques.
    @date July 2021
*/
#include "App.h"

/** App() is a default constructor:
	Create an App instance.
*/
App::App() {
}

/** notifyFall() public method:
	Send a message through the Serial Port, notifying a fall.
*/
void App::notifyFall() {
	Serial.println("YOU FALL!");
}