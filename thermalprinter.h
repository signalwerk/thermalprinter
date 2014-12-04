/*******************************************
 *
 * Name.......:  Epson TM-T88II Library
 * Version....:  0.6.0
 * Description:  A Library to control an Epson TM-T88II thermal printer (microprinter) 
 *               by an arduino via serial connection
 * Project....:  https://github.com/signalwerk/thermalprinter
 * License....:  You may use this work under the terms of either the MIT License or 
                 the GNU General Public License (GPL) Version 3
 * Keywords...:  thermal, micro, receipt, printer, serial, tm-t88, tm88, tmt88, epson
 * ********************************************/

#ifndef thermalprinter_h
#define thermalprinter_h

 #include "Arduino.h"
 #include "SoftwareSerial.h"

class Epson : public Print {
public:
  
  Epson(int rxPin, int txPin);
  

size_t write(uint8_t c);
int read();


void start();

int getStatus();
void boldOff();
void boldOn();
void characterSet(uint8_t n);
void defaultLineSpacing();
void doubleHeightOff();
void doubleHeightOn();
void feed(uint8_t n);
void feed();
void lineSpacing(uint8_t n);
void reverseOff();
void reverseOn();
void underlineOff();
void underlineOn();
void justifyLeft();
void justifyCenter();
void justifyRight();
void barcodeHeight(uint8_t n);
void barcodeWidth(uint8_t n);
void barcodeNumberPosition(uint8_t n);
void printBarcode(uint8_t m,uint8_t n);
void cut();


private:
  int _rxPin;  
  int _txPin;
  
  SoftwareSerial * _printer;


};

#endif
