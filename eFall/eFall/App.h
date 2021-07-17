/** @brief App.h class headers
    Used to notify a fall via Serial Port.
    @author Fabio Lameira, Celsio Gil, Luis Duarte Marques.
    @date July 2021
*/
#ifndef _APP_H
#define _APP_H 1
#include <Arduino_LSM9DS1.h>

class App {
private:
public:
	App();								/** Default App class constructor. */
	void notifyFall(void);				/** Send a message through the Serial Port, notifying a fall. */
};

#endif /* APP_H_ */