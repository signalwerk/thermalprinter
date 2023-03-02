# Epson TM-T88II Library

A Library to control an Epson TM-T88II thermal printer (microprinter) by an arduino via serial connection.

## Requirements

To get Arduino work together with the thermal priner on RS232 (serial) you need a level shifter. From Maxim you can get MAX2XX chips for 5 Volt and MAX32XX for 3.3 volt powered arduinos. The library works with SoftSerial so you are still able to send Data to Arduino with the standard serial line. The SoftSerial works at 9600 baud.

## Tested

- Epson TM-T88II Model M129B (Serial RS232) & Arduino Uno & Maxim MAX233CPP

## Functions

The functions available in this class are:

### `Epson::Epson(int rxPin, int txPin)`

Constructor that initializes the `rxPin` and `txPin` used to communicate with the printer and calls the `start()` function.

### `void Epson::start()`

Sets up the communication pins, initializes the `SoftwareSerial` object used for communication with the printer, and sets the baud rate to 9600.

### `int Epson::getStatus()`

Sends a query to the printer to check its status. Returns `22` if the printer is online.

### `int Epson::read()`

Reads a single byte of data from the printer.

### `void Epson::feed(uint8_t n)`

Prints the data in the print buffer and feeds `n` lines of paper.

### `void Epson::feed()`

Equivalent to calling `feed(1)`.

### `void Epson::lineSpacing(uint8_t n)`

Sets the line spacing to `n/180` inch.

### `void Epson::defaultLineSpacing()`

Sets the line spacing to `1/6` inch, which is equivalent to 30 dots.

### `void Epson::characterSet(uint8_t n)`

Selects an international character set based on the value of `n`. See reference for more metails.

Example:

```
 0 = U.S.A.
 1 = France
 2 = Germany
 3 = U.K.
 4 = Denmark I
 5 = Sweden
 6 = Italy
 7 = Spain
 8 = Japan
 9 = Norway
10 = Denmark II
```

### `void Epson::doubleHeightOn()`

Enables double-height text printing.

### `void Epson::doubleHeightOff()`

Disables double-height text printing.

### `void Epson::boldOn()`

Enables bold text printing.

### `void Epson::boldOff()`

Disables bold text printing.

### `void Epson::underlineOn()`

Enables underlined text printing.

### `void Epson::underlineOff()`

Disables underlined text printing.

### `void Epson::reverseOn()`

Enables white/black reverse printing mode.

### `void Epson::reverseOff()`

Disables white/black reverse printing mode.

### `void Epson::justifyLeft()`

Sets text justification to left.

### `void Epson::justifyCenter()`

Sets text justification to center.

### `void Epson::justifyRight()`

Sets text justification to right.

### `void Epson::barcodeHeight(uint8_t n)`

Sets the height of barcodes to `n` dots. Range 1-255.

### `void Epson::barcodeWidth(uint8_t n)`

Sets the width of barcodes to `n` dots. Range 2-6

### `void Epson::barcodeNumberPosition(uint8_t n)`

Sets the position of the barcode number. Range 0-3

### `void Epson::printBarcode(uint8_t m, uint8_t n)`

Prints a barcode of type `m` (range 65-73) with a digit length of `n`.

### `void Epson::cut()`

Performs a full cut of the paper.

### `size_t Epson::write(uint8_t c)`

Writes a single byte of data to the printer.

## Inspiration

- [Tom Taylor · Post Microprinter](https://web.archive.org/web/20130116063826/http://tomtaylor.co.uk/projects/microprinter)
- [Tom Taylor · Code for the microprinter project](https://github.com/tomtaylor/microprinter-arduino)
- [Roo Reynolds · Post Microprinter](http://rooreynolds.com/2009/02/01/microprinter/)
- [Roo Reynolds · Microprinter Arduino library, Java and Ruby API](https://github.com/rooreynolds/microprinter)
- [Adafruit · Mini Thermal Receipt Printers](https://learn.adafruit.com/mini-thermal-receipt-printer)
- [Adafruit · Thermal Printer Library](https://github.com/adafruit/Adafruit-Thermal-Printer-Library/)

## Contributors

- [docwisdom](https://github.com/docwisdom)
- [signalwerk](https://github.com/signalwerk)

Contributions appreciated.

## License

You may use this work under the terms of either the MIT License or the GNU General Public License (GPL) Version 3

## History

- 2023-03-02 - Add a documentation of the class to the readme.md
- 2014-11-24 - include functionality for reading printer status, printing barcodes and justification
- 2012-04-13 - first public release
- 2012-03-13 - first beta of the class extracted for standalone
- 2010-06-05 – first public lecture with the code ([«Der Tag der Schrift»](http://www.typo-online.ch/tds/2010/))

### Keywords

thermal, micro, receipt, printer, serial, tm-t88, tm88, tmt88, epson
