#include <LWiFi.h>
#include <LWiFiClient.h>
#include <stdarg.h>
#include <LWiFiUdp.h>

#define SITE_URL "www.google.com"
#define WIFI_AP "TP-LINK_D78C4C" //請輸入所要連的AP名稱
#define WIFI_PWD "microlab" // 請輸入AP 密碼
LWiFiClient c;

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
}

void loop() {
  // put your main code here, to run repeatedly:

}
