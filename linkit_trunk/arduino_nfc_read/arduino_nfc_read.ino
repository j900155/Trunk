#include <Wire.h>
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>
 
PN532_SPI interface(SPI, 10);
NfcAdapter nfc = NfcAdapter(interface);
 
void setup(void) {
    Serial.begin(9600); // begin serial communication
    while(!Serial)
    {
      Serial.println("Please plugin NFC Reader.");
      
      delay(500);  
    }
    nfc.begin(); // begin NFC communication
}
 
void loop(void) 
{
    if (nfc.tagPresent())
    { 
        NfcTag tag = nfc.read();
 
    
    }
    delay(500); 
}

