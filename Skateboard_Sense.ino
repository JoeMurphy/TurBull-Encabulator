#include <Encabulator.h>
#include <Wire.h>
// #include <I2C.h>   // NOTE: For reasons buried in the Encabulator.cpp file, you might want to download and use this library instead. 

// int loopCounter = 0;

int tempR = 0;
int tempG = 0;
int tempB = 0;

float tempX = 0.0;
float tempY = 0.0;

float tempC = 0.0; 

//int tempLength = 64; 

//int palindrome = 0; 

void setup() {               
  
  Encabulator.upUpDownDownLeftRightLeftRightBA();

  // enable some debugging on the serial port

  Encabulator.setVerbose(true);

  // Encabulator.addressable.drawGradient(random() % 255,random() % 255,0,0,random() % 255,random() % 255,64);

  //delay(500);

  //Encabulator.addressable.drawGradient(0,0,0,0,0,0,64);

  delay(500);

  // jump all 12V RGB headers up to white

  for (int i = 1 ; i < 5 ; i++) {  
    Encabulator.stripBankA.jumpHeaderToRGB(i,255,255,255); 
    Encabulator.stripBankB.jumpHeaderToRGB(5-i,255,255,255);
    delay(250);
  }

  delay(250);

  // quickly fade all 12V RGB headers down to black

  for (int i = 1 ; i < 5 ; i++) {  
    Encabulator.stripBankA.fadeHeaderToRGB(i,0,0,0,20); 
    Encabulator.stripBankB.fadeHeaderToRGB(5-i,0,0,0,20);
    delay(250);
  }

  delay(500);  
    
}

void loop() {

  //palindrome = (loopCounter % 510 > 255) ? 255 - (loopCounter % 510) : loopCounter % 510;
  
  //tempX = Encabulator.accelerometer.x() / 1024.0;
  tempY = Encabulator.accelerometer.y() / 1024.0;

  // Set colors variables for R, G, and B
  tempR = 0;
  tempG = 0;
  tempB = abs(tempY * 255.0);
  
  //Serial.print(tempB);
  //Serial.print(" y: ");
  // Serial.print(Encabulator.accelerometer.y()/ 512.0);
  //delay(1000);

  // do a color pattern across the 8 headers based roughly on the X axis

      //  Encabulator.stripBankA.jumpHeaderToRGB((uint8_t) 1, tempR,tempG,tempB); 
      //  Encabulator.stripBankA.jumpHeaderToRGB((uint8_t) 2, tempR,0, tempB); 
      //  Encabulator.stripBankA.jumpHeaderToRGB((uint8_t) 3, tempR,0, tempB); 
      //  Encabulator.stripBankA.jumpHeaderToRGB((uint8_t) 4, tempR,0, tempB); 
      //
      //  Encabulator.stripBankB.jumpHeaderToRGB((uint8_t) 1, tempR,0, tempB); 
      //  Encabulator.stripBankB.jumpHeaderToRGB((uint8_t) 2, tempR,0, tempB); 
      //  Encabulator.stripBankB.jumpHeaderToRGB((uint8_t) 3, tempR,0, tempB); 
      //  Encabulator.stripBankB.jumpHeaderToRGB((uint8_t) 4, tempR,tempG,tempB); 

  //Test if Y axis is tilted left or right
  if (Encabulator.accelerometer.y() < 0.0) {
    Encabulator.stripBankA.jumpHeaderToRGB((uint8_t) 1, tempB,tempG,tempR);
  } else {
    Encabulator.stripBankB.jumpHeaderToRGB((uint8_t) 4, tempR,tempG,tempB);
  }
 
}
