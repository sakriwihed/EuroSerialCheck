#include <iostream>
#include <string>

// TODO Aufgabe 3:
//  Inkludiert die Funktionen aus den `euroCheck.h/cpp`-Dateien.

#include "euroCheck.h"

// TODO Aufgabe 1:
//  Definiert die Funktion `inputNextSerialNumber()` so, dass sie eine Seriennummer als `string` auf der Konsole einliest und diese zurückgibt.
using namespace std; //damit man nicht jedes mal std:: vor strings schreibt

string inputNextSerialNumber() {
  string serialNumber;
  cout << "Geben sie eine Seriennummer ein:";
  cin >>serialNumber;
  return serialNumber;
}

// TODO Aufgabe 3:
//  Implementiert die Funktion `checkSerialNumberAndPrintResult(serialNumber)`.
//  Sie soll mithilfe der Funktion `getEuroSerialNumberVersion(serialNumber)` ermitteln, um welche Version einer Euro-Banknote es sich handelt, und die entsprechende Jahreszahl in der Konsole ausgeben.
//  Anschliessend soll in einer Fallunterscheidung (switch) anhand der Jahreszahl die entsprechende Funktion `checkEuroSerialNumber2013/2002(serialNumber)` aufgerufen und das Ergebnis (Gueltig/Ungueltig) auf der Konsole ausgeben werden.
void checkSerialNumberAndPrintResult(string & serialNumber) {
 switch (getEuroSerialNumberVersion(serialNumber)) {
   case 2002:
    if (checkEuroSerialNumber2002(serialNumber)) {
     cout << "Gueltig" << endl;
     }
    else {
     cout << "Ungueltig" << endl;
    }
    break;

   case 2013:
    if (checkEuroSerialNumber2013(serialNumber)) {
     cout << "Gueltig" << endl;
    }
    else {
     cout << "Ungueltig" <<endl;
    }
    break;

  default:
   cout << "Oops Ungueltige Seriennummer" <<endl;
    break;
  }
}

int main() {
 string serialNumber;

    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.
    do {

     // TODO Aufgabe 1:
     //  Ruft `inputNextSerialNumber()` auf, um eine Seriennummer einzugeben.

     serialNumber = inputNextSerialNumber();
     if (serialNumber =="fertig") { // damit ,der string "fertig" wurde nicht auf den konsole ausgegeben
      break;
     }
     checkSerialNumberAndPrintResult(serialNumber);
     cout <<"deine Seriennummer lautet:"<< serialNumber << endl;

     // TODO Aufgabe 4:
     //  Das Programm soll beendet werden, wenn statt einer Seriennummer "fertig" eingegeben wurde.
    } while (serialNumber !="fertig");

    return 0;
}
