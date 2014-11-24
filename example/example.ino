#include <SoftwareSerial.h>

#include "thermalprinter.h"

#define ledPin 13
#define rxPin 6
#define txPin 7

int printStatus = 0;

Epson TM88 = Epson(rxPin, txPin); // init the Printer with Output-Pin

void setup()
{

  Serial.begin(9600); //open the USB connection too
  

  delay(1000);

  TM88.start();
  TM88.justifyCenter();
  TM88.println("Hello World start");  
  
  TM88.justifyLeft();
  TM88.println("Feed 3 start");  
  TM88.feed(3); 
  TM88.println("Feed 3 end");  
  TM88.feed(2); 
  TM88.lineSpacing(30);  
  TM88.println("line spacing 30 start");  
  TM88.println("line spacing 30 end");  
  TM88.feed(2); 

  TM88.lineSpacing(90);  
  TM88.println("line spacing 90 start");  
  TM88.println("line spacing 90 end");  
  TM88.feed(2);  
  
  TM88.defaultLineSpacing();  
  TM88.println("default line spacing (60) start");  
  TM88.println("default line spacing (60) end");  
  

  TM88.println("Print umlauds with German character set:");    
  
  TM88.println("äöü ÄÖÜ ß");  
  TM88.println("\x7B\x7C\x7D \x5B\x5C\x5D \x7E");  
  TM88.println("start");  
  
  TM88.characterSet(2);
  
  TM88.println("äöü ÄÖÜ ß");  
  TM88.println("\x7B\x7C\x7D \x5B\x5C\x5D \x7E");  

  TM88.doubleHeightOn();
  TM88.println("double height on");  
  
  TM88.doubleHeightOff();
  TM88.println("double height off");  
  
  TM88.boldOn();
  TM88.println("bold on");  
  
  TM88.boldOff();  
  TM88.println("bold off");  
  
  TM88.underlineOn();
  TM88.println("underline on");  
  
  TM88.underlineOff();   
  TM88.println("underline off");  

  TM88.reverseOn();
  TM88.println("reverse on");  
  TM88.println(" Hamburgefonts ");  
  TM88.reverseOff();   
  TM88.println("reverse off");      
  
  TM88.justifyCenter();
  TM88.barcodeHeight(50);
  TM88.barcodeWidth(3);
  TM88.barcodeNumberPosition(2);
  TM88.printBarcode(67,12);
  TM88.println("496595707379");
  
  TM88.justifyRight();
  TM88.println("Hello World end");  
  
  TM88.cut();  


}

void loop()                     // run over and over again
{
  
  printStatus = TM88.getStatus();     // get the current status of the TM88 printer
  if (printStatus == 22) {            // if status is 22 then we are good
    Serial.println("printer online");     // debug that we are online
  } else {
    Serial.print("printer offline: ");    // debug that we are offline
    Serial.println(printStatus);          // debug the returned status code  
  } 
  
  
  if (Serial.available() > 0) {
    TM88.print(Serial.read());
  }

  //digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second
}
