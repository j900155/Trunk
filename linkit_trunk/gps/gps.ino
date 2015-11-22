#include <LGPS.h>
#define BAUDRATE 9600

gpsSentenceInfoStruct info; // 儲存GPS資料
// 輔助函式，抓出資料的下一個項目
const char *nextToken(const char *src, char *buf){
  int i = 0;
  while(src[i] != 0 && src[i] != ',')
    i++;

  if(buf){
    strncpy(buf, src, i);
    buf[i] = 0;
  }

  if(src[i]){
    i++;
  }
  return src+i;  
} 
// 解析資料，印出想要的東西
void printGPGGA(const char *str)
{
  const char *p = str;
  char t[10];
  int th, tm, ts;
  char latitude[20];
  char ns[2];
  char longitude[20];
  char ew[2];
  char fixq[2];
  char n_satellite[3];
  
  p = nextToken(p, 0);      // GGA
  p = nextToken(p, t);      // Time
  th = (t[0]-'0') * 10 + (t[1]-'0');
  tm = (t[2]-'0') * 10 + (t[3]-'0');
  ts = (t[4]-'0') * 10 + (t[5]-'0');
  p = nextToken(p, latitude);  // Latitude
  p = nextToken(p, ns);      // N, S
  p = nextToken(p, longitude); // Longitude
  p = nextToken(p, ew);      // E, W
  p = nextToken(p, fixq);       // fix quality
  p = nextToken(p, n_satellite);       // number of satellites
  
  if(fixq[0] == '1'){
    Serial.print("UTC time: ");
    Serial.print(th); Serial.print(":");
    Serial.print(tm); Serial.print(":");
    Serial.println(ts);
    Serial.print("Satellite(s): ");
    Serial.println(atoi(n_satellite));
    Serial.print("Latitude: ");
    Serial.print(ns);
    Serial.println(latitude);
    Serial.print("Longitude: ");
    Serial.print(ew);
    Serial.println(longitude);
  }
  else{
    Serial.println("GPS is not fixed yet.");    
  }
} 

void setup(){
  Serial.begin(BAUDRATE);
  LGPS.powerOn();
  Serial.println("GPS power on...waiting");
  delay(3000);
}

void loop(){
  Serial.println("-------------------");
  LGPS.getData(&info);
  Serial.println((char *)info.GPGGA);
  printGPGGA((const char *)info.GPGGA);
 
  delay(1000);
}
