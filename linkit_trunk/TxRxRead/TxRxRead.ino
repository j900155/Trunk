#include <UARTClass.h>   


uint8_t RxBuf[11];  // 儲存接收資料的變數
int val;
void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial1.begin(9600);
  Serial.println("BT is ready!");
}

void loop() {
  int i=0;
  while(Serial1.available() && Serial.read()!=0)
   {
    RxBuf[i]=Serial1.read();
    i=i+1;
  }
  String str="";
  for(int i=0;i<11;i++)
  {
     str=str+char(RxBuf[i]);
   }
  if (i!=0)
  {
    Serial.println(str);
  }
}
