# Epson TM-T88II Library
A Library to control an Epson TM-T88II thermal printer (microprinter) by an arduino via serial connection.

# Requirements
To get Arduino work together with the thermal priner on RS232 (serial) you need a level shifter. From Maxim you can get MAX2XX chips for 5 Volt and MAX32XX for 3.3 volt powered arduinos. The library works with SoftSerial so you are still able to send Data to Arduino with the standard serial line. The SoftSerial works at 9600 baud.

# Tested
* Epson TM-T88II Model M129B (Serial RS232) & Arduino Uno & Maxim MAX233CPP

## Inspiration 
* http://tomtaylor.co.uk/projects/microprinter
* https://github.com/tomtaylor/microprinter-arduino/tree
* http://rooreynolds.com/2009/02/01/microprinter/
* https://github.com/rooreynolds/microprinter
* http://www.ladyada.net/products/thermalprinter/
* https://github.com/adafruit/Adafruit-Thermal-Printer-Library/

##  Author
Stefan Huber – sh[at]signalwerk[dot]ch. Contributions appreciated.

## License
You may use this work under the terms of either the MIT License or the GNU General Public License (GPL) Version 3

## History
* 2014-11-24 V0.6 - include functionality for reading printer status, printing barcodes and justification (docwisdom contribution)
* 2012-04-13 V0.5 - first public release
* 2012-03-13 V0.1 - first beta of the class extracted of the project
* 2010-06-05      – first show of my thermal printer project on a public lecture at «Der Tag der Schrift» http://www.typo-online.ch/tds/2010/


### Keywords
thermal, micro, receipt, printer, serial, tm-t88, tm88, tmt88, epson
