#include "BlynkGO_HMAC.h"
#include "mbedtls/md.h"

String hmac(String key, String payload){
  byte hmacResult[32];
 
  mbedtls_md_context_t ctx;
  mbedtls_md_type_t md_type = MBEDTLS_MD_SHA256;
  
  mbedtls_md_init(&ctx);
  mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(md_type), 1);
  mbedtls_md_hmac_starts(&ctx, (const uint8_t*) key.c_str(), key.length());
  mbedtls_md_hmac_update(&ctx, (const uint8_t*) payload.c_str(), payload.length());
  mbedtls_md_hmac_finish(&ctx, hmacResult);
  mbedtls_md_free(&ctx);

  String _hmac = "";
  for(int i= 0; i< sizeof(hmacResult); i++){
      char str[3]; 
      sprintf(str, "%02x", (int)hmacResult[i]);
      _hmac += str;
  }
  return _hmac;
}
