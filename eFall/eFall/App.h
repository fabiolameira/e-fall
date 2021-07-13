#ifndef _APP_H
#define _APP_H 1
#include <Arduino_LSM9DS1.h>

class App {
private:
public:
	App();
	void notifyFall(void);
};

#endif /* APP_H_ */