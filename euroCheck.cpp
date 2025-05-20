#include "euroCheck.h"
#include <iostream>

using namespace std;
bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(string & serialNumber) {
    int length = serialNumber.length();

    // Prüft auf zwei Buchstaben(2013)
    if (isLetter(serialNumber[0]) && isLetter(serialNumber[1])) {
        for (int i = 2; i < length; ++i) {
            if (!isNumber(serialNumber[i])) {  //pruft ob der rest der Ziffern gultig ist
                return 0;
            }
        }
        return 2013;
    }

    // Prüft auf einen Buchstaben(2002)
    if (isLetter(serialNumber[0])) {
        for (int i = 1; i < length; ++i) {
            if (!isNumber(serialNumber[i])) {
                return 0;
            }
        }
        return 2002;
    }
    return 0; //sonst ergibt die Funktion 0
}


// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.
bool checkEuroSerialNumber2002(string& serialNumber){
    if (serialNumber.length()!=12) {
        return false ;
    }
    int asciicode = serialNumber[0];
    int CodeChar = asciicode-64;// asciicode von character A ist 65 aber wir brauchen den Code 1 fur A usw
    int QsummeChar=(CodeChar%10)+(CodeChar/10);
    int Qsumme1=0;
    for (int i = 1; i < 12; i++) {
        Qsumme1 =Qsumme1+serialNumber[i]-48; //weil asccicode von character 0 ist 48 , damit wir die reelle wert vom char rechnen
    }

    int Qsumme=Qsumme1+QsummeChar;
    int rest= Qsumme%9;
    int Pruefziffer=8-rest;
    if (Pruefziffer==0){
        Pruefziffer=9;
    }
    if (Pruefziffer==serialNumber[11]-48) {
        return true;
    }
        return false;
}



// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N

bool checkEuroSerialNumber2013(string& serialNumber)
{
    if (serialNumber.length()!=12) {
        return false ;
    }
    int CodeChar=0;
    for (int i = 0; i < 2; i++) {
        int asciicode1 = serialNumber[i];
        CodeChar = CodeChar + asciicode1-64; // asciicode von character A ist 65
    }
    int QsummeChar=(CodeChar%10)+(CodeChar/10);
    int Qsumme1=0;
    for (int i = 2; i < 12; i++) {
        Qsumme1 =Qsumme1+serialNumber[i]-48; //weil asccicode von character 0 ist 48 , damit wir die reelle wert von dem character im string rechnen
    }

    int Qsumme=Qsumme1+QsummeChar;
    int rest= Qsumme%9;
    int Pruefziffer=7-rest;
    if (Pruefziffer==0){
        Pruefziffer=9;
    }if (Pruefziffer==-1){
        Pruefziffer=8;
    }
    cout << Pruefziffer << endl;
    if (Pruefziffer==serialNumber[11]-48) { //48 ist der asciicode von character 0,damit man die reelle Werte vergleichen wird
        return true;
    }
    return false;

}

// L
bool isLetter(char c) {
    return 'A' <= c && c <= 'Z';
}
// N
bool isNumber(char c) {
    return '0' <= c && c <= '9';
}
int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        return c - 'A' + 1;
    }
    cout << "Error: toNumber(char): " << c << endl;
    return 0;
}
