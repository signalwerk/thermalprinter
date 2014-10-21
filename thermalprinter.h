/*******************************************
 *
 * Name.......:  Epson TM-T88II Library
 * Description:  A Library to control an Epson TM-T88II thermal printer (microprinter) 
 *               by an arduino via serial connection
 * Author.....:  Stefan Huber
 * Version....:  0.5
 * Date.......:  2012-04-13
 * Project....:  http://signalwerk.ch
 * Contact....:  sh[at]signalwerk[dot]ch
 * License....:  You may use this work under the terms of either the MIT License or 
                 the GNU General Public License (GPL) Version 3
 * Keywords...:  thermal, micro, receipt, printer, serial, tm-t88, tm88, tmt88, epson
 * Inspiration:  http://tomtaylor.co.uk/projects/microprinter
                 https://github.com/tomtaylor/microprinter-arduino/tree
                 http://rooreynolds.com/2009/02/01/microprinter/
                 https://github.com/rooreynolds/microprinter
                 http://www.ladyada.net/products/thermalprinter/
                 https://github.com/adafruit/Adafruit-Thermal-Printer-Library/
 * History....:  2012-04-13 V0.5 - first public release
 *               2012-03-13 V0.1 - first beta of the class extracted of the project
 *               2010-06-05      – first show of my thermal printer project
 *                                 on a public lecture at «Der Tag der Schrift»
 *                                 http://www.typo-online.ch/tds/2010/
 * ********************************************/

#ifndef thermalprinter_h
#define thermalprinter_h

 #include "Arduino.h"
 #include "SoftwareSerial.h"

class Epson : public Print {
public:
  
  Epson(int rxPin, int txPin);
  

  size_t write(uint8_t c);

  void start();


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
void cut();


private:
  int _rxPin;  
  int _txPin;
  
  SoftwareSerial * _printer;


};

#endif
