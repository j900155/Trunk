#include <SoftwareSerial.h>   // 引用程式庫

SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數

void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
  BT.begin(9600);
}

void loop() {
  
  if (Serial.available()) {
    val=Serial.read();
    BT.write(val);
  }
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    BT.write(val);
   
  }
}
