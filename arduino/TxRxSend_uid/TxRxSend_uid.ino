#include <SPI.h>
#include <Arduino.h>
#include "PN532_SPI.h"
#include "PN532.h"
#include "NfcAdapter.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX


PN532_SPI interface(SPI, 10); // create a SPI interface for the shield with the SPI CS terminal at digital pin 10
NfcAdapter nfc = NfcAdapter(interface); // create an NFC adapter object

void setup(void) {
   
  Serial.begin(115200); // start serial comm
    Serial.println("NDEF Reader");
    nfc.begin(); // begin NFC comm
     mySerial.begin(9600);
     Serial.println("TxRx ready");
     
}

void loop(void) {

    
    if (nfc.tagPresent()) // check if an NFC tag is present on the antenna area
    {
        NfcTag tag = nfc.read(); // read the NFC tag
        String scannedUID = tag.getUidString(); // get the NFC tag's UID
        Serial.println(scannedUID);
        
          char CharString[11];
          char Cuid[11];
          for(int i=0;i<11;i++)
          {
            CharString[i]=scannedUID[i];  
          }                                    
          sprintf(Cuid,CharString);
          mySerial.write(Cuid);
          Serial.println("2");
          Serial.println();
        
    }
    delay(2000);
}
