#include <LWiFi.h>
#include <LWiFiClient.h>
#include <stdarg.h>
#include <LWiFiUdp.h>
#include <LGPS.h>

#define SITE_URL "www.google.com"
#define WIFI_AP "TP-LINK_D78C4C" //請輸入所要連的AP名稱
#define WIFI_PWD "microlab" // 請輸入AP 密碼
LWiFiClient c;

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


void printGPGGA(const char *str)// 解析資料，印出想要的東西
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


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
LWiFi.begin();

Serial.println();
Serial.print("Connecting to AP...");
if(LWiFi.connectWPA(WIFI_AP, WIFI_PWD) < 0)
{
  Serial.println("FAIL!");
  return;
}
 
LWifiStatus ws = LWiFi.status();
Serial.println(ws);
        
Serial.println("ok");
 
IPAddress ip = LWiFi.localIP();
Serial.print("IP Address: ");
Serial.println(ip);
 

uint8_t macAddress[VM_WLAN_WNDRV_MAC_ADDRESS_LEN] = {0};
LWiFi.macAddress(macAddress);
Serial.print("MAC Address is:");
for(int i = 0; i < VM_WLAN_WNDRV_MAC_ADDRESS_LEN; ++i)
{
  Serial.print(macAddress[i], HEX);
  Serial.print(":");
}
Serial.println();

  
 Serial.print("Connecting to site...");
 if(!c.connect(SITE_URL, 80))
 {
   Serial.println("FAIL!");
   return;
 }
 Serial.println("ok");
 Serial.println("send HTTP GET request");
 c.println("GET / HTTP/1.1");
 c.println("Host: " SITE_URL);
 c.println("Connection: close");
 c.println();
 
LGPS.powerOn();
Serial.println("GPS power on...waiting");
delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("-------------------");
LGPS.getData(&info);
Serial.println((char *)info.GPGGA);
printGPGGA((const char *)info.GPGGA);
 
delay(1000);
}
