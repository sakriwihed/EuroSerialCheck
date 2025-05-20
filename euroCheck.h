#ifndef BLATT2_EUROCHECK_H
#define BLATT2_EUROCHECK_H
#include <string>
#include "euroCheck.cpp"
using namespace std;

// TODO Aufgabe 2:
//  Deklariert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
int getEuroSerialNumberVersion(string & serialNumber);
bool checkEuroSerialNumber2002(string & serialNumber);
bool checkEuroSerialNumber2013(string & serialNumber);

#endif //BLATT2_EUROCHECK_H
