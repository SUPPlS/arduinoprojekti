#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <DHT.h>

void initDHT();
float readTemperature();
float readHumidity();

#endif // TEMPERATURESENSOR_H
