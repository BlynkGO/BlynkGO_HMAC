#include <BlynkGO_HMAC.h>

void setup(){
 
  Serial.begin(115200);
 
  char *key = "secretKey";
  char *payload = "Hello HMAC SHA 256!";
 
  Serial.printf("Hash: %s\n", hmac( key, payload).c_str() );
}

void loop(){  
}


