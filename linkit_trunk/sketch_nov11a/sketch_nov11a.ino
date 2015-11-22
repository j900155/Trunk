#include <UARTClass.h>   


char val;  // 儲存接收資料的變數

void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial1.begin(9600);
  Serial.println("BT is ready!");
}

void loop() {

  if (Serial1.available()) {
    val=Serial1.read();
    Serial.println(val);
  }
  
}
