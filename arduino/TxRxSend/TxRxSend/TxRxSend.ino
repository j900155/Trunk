#include <SoftwareSerial.h>

#include "SPI.h"
#include "PN532_SPI.h"
#include "PN532.h"
#include "snep.h"
#include "NdefMessage.h"
#include "NfcAdapter.h"

PN532_SPI pn532spi(SPI, 10);
SNEP nfc(pn532spi);
uint8_t ndefBuf[128];
uint8_t recordBuf[128];
String serialString;
NfcAdapter nfc1 = NfcAdapter(pn532spi);


SoftwareSerial mySerial(8, 9); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


 Serial.println("-------NFC Start--------");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("-------NFC Start--------");
}

void loop() { // run over and over
  if (Serial.available()) 
  {
    NfcTag tag=nfc1.read();
    String scanned=tag.getUidString();
    Serial.println(scanned);
    mySerial.write(Serial.read());
    
  }
}
