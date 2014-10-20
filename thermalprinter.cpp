/*******************************************
 * see header-file for further informations
 ********************************************/

#include "Arduino.h"
#include "thermalprinter.h"

static const char LF = 0xA; // print buffer and line feed  
    
    
Epson::Epson(int rxPin, int txPin)
{
  this->_rxPin = rxPin;
  this->_txPin = txPin;
  this->start();
}

void Epson::getStatus(){
  this->write(0x1D);    
  this->write(0x72);  
  this->write(1);
}


void Epson::start(){

  pinMode(this->_txPin, OUTPUT);
  pinMode(this->_rxPin, INPUT);  
  this->_printer = new SoftwareSerial (this->_rxPin, this->_txPin);
  this->_printer->begin(9600);
}

// Print and feed n lines
// prints the data in the print buffer and feeds n lines
void Epson::feed(uint8_t n){
  this->write(0x1B);  
  this->write(0x64);
  this->write(n);    
}

// Print one line
void Epson::feed(){
  this->feed(1);    
}


// Set line spacing
// sets the line spacing to n/180-inch
void Epson::lineSpacing(uint8_t n){
  this->write(0x1B);  
  this->write(0x33);
  this->write(n);  
}

// Select default line spacing
// sets the line spacing to 1/6 inch (n=60). This is equivalent to 30 dots.
void Epson::defaultLineSpacing(){
  this->write(0x1B);  
  this->write(0x32);
}

// Select an international character set
//  0 = U.S.A. 
//  1 = France 
//  2 = Germany 
//  3 = U.K. 
//  4 = Denmark I 
//  5 = Sweden 
//  6 = Italy 
//  7 = Spain 
//  8 = Japan 
//  9 = Norway 
// 10 = Denmark II 
// see reference for Details! 
void Epson::characterSet(uint8_t n){
  this->write(0x1B);  
  this->write(0x52);
  this->write(n);  
}


void Epson::doubleHeightOn(){
  this->write(0x1B);    
  this->write(0x21);  
  this->write(16);
}

void Epson::doubleHeightOff(){
  this->write(0x1B);  
  this->write(0x21);    
  this->write(0);
}

void Epson::boldOn(){
  this->write(0x1B);  
  this->write(0x21);    
  this->write(8);
}

void Epson::boldOff(){
  this->write(0x1B);  
  this->write(0x21);    
  this->write(0);
}

void Epson::underlineOff() {
  this->write(0x1B);  
  this->write(0x21);    
  this->write(0);
}
void Epson::underlineOn() {
  this->write(0x1B);  
  this->write(0x21);    
  this->write(128);
}


// Turn white/black reverse printing mode on/off
void Epson::reverseOn() {
  this->write(0x1D);  
  this->write(0x42);    
  this->write(1);
}
  
void Epson::reverseOff() {
  this->write(0x1D);  
  this->write(0x42);    
  this->write(0);
}

void Epson::justifyLeft() {
  this->write(0x1B);  
  this->write(0x61);    
  this->write(0);
}

void Epson::justifyCenter() {
  this->write(0x1B);  
  this->write(0x61);    
  this->write(1);
}

void Epson::justifyRight() {
  this->write(0x1B);  
  this->write(0x61);    
  this->write(2);
}
//n range 1-255
void Epson::barcodeHeight(uint8_t n) {
  this->write(0x1D);  
  this->write(0x68);    
  this->write(n);
}
//n range 2-6
void Epson::barcodeWidth(uint8_t n) {
  this->write(0x1D);  
  this->write(0x77);    
  this->write(n);
}
//n range 0-3
void Epson::barcodeNumberPosition(uint8_t n) {
  this->write(0x1D);  
  this->write(0x48);    
  this->write(n);
}
//m range 65-73 (code type)
//n (digit length)
void Epson::printBarcode(uint8_t m, uint8_t n) {
  this->write(0x1D);  
  this->write(0x6B);    
  this->write(m);
  this->write(n);
}

void Epson::cut() {
  this->write(0x1D);
  this->write('V');
  this->write(66);
  this->write(0xA); // print buffer and line feed
}

size_t Epson::write(uint8_t c) {
  this->_printer->write(c);
  return 1;
}


