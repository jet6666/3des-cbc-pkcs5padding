#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "keyGeneration.h"
#include "DESEncrypt.h"
#include "DESDecrypt.h"
#include "CBCDESEncryption.h"
#include "CBCDESDecryption.h"
#include "tripleDESCBCEncryption.h"
#include "tripleDESCBCDecryption.h"
#include "tripleKeyDESCBCEncryption.h"
#include "tripleKeyDESCBCDecryption.h"
#include "keyReader.h"


#include "utils.h"
#include "cipher_padding.h"



int main() {
    printf("Hello, World!\n");


    //test 32 Bytes
    //this is a 3des-cbd-PKCS#5 exampl
    //test 33 Bytes
    unsigned char buffer[] = "this is a 3des-cbd-PKCS#5 example";
    printf("plain  text  = %s ,length = %d \n", buffer,strlen(buffer));

    //after  PKCS#5 padding
    padding_with_length(buffer, strlen(buffer));
    int buffer_length = strlen(buffer);
    printf("plain  text2 = %s ,length = %d \n", buffer,strlen(buffer));
    //hexdump(buffer,strlen(buffer)) ;

    //iv = thisthat
    unsigned  char iv[] = {0X74, 0X68, 0X69, 0X73, 0X74, 0X68, 0X61, 0X74};
//    printf("iv = %s \n", iv);
//
//    //key = key1key2key3key4key5key6key7key8
    unsigned char key[] = {0X6B, 0X65, 0X79, 0X31, 0X6B, 0X65, 0X79, 0X32};
    unsigned char key2[] = {0X6B, 0X65, 0X79, 0X33, 0X6B, 0X65, 0X79, 0X34};
    unsigned char key3[] = {0X6B, 0X65, 0X79, 0X35, 0X6B, 0X65, 0X79, 0X36};


//    printf("key  = %s \n", iv);

      char out[1024] = {0};
    memset(out, 0x0, sizeof(out));

    hexdump(buffer,strlen(buffer)) ;
    printf("==stop") ;

    tripleKeyDES_CBCEncryption(buffer, key, key2, key3, iv, buffer_length, out);

    //hex data
    int len = buffer_length;//strlen(out);
    printf("=======result  hex  ,length =%d \n", len);
    hexdump(out, len);
    printf(" \n");

    //base64
    unsigned char *buf = NULL;
    buf = base64_encode(out,len);
    printf("base64 =%s ", buf);

    free(buf);
    return 0;
}