 CLion Project 3des-cbc (des-ede3-cbc) with pkcs5padding
 
 
## c

```
   unsigned char buffer[] = "this is a 3des-cbd-PKCS#5 example2222";
      //after  PKCS#5 padding
      char *buffer2 = padding_with_length(buffer, strlen(buffer));
      int buffer_length = strlen(buffer2);
      //iv = thisthat
      unsigned  char iv[] = {0X74, 0X68, 0X69, 0X73, 0X74, 0X68, 0X61, 0X74};
  //    //key = key1key2key3key4key5key6key7key8
      unsigned char key[] = {0X6B, 0X65, 0X79, 0X31, 0X6B, 0X65, 0X79, 0X32};
      unsigned char key2[] = {0X6B, 0X65, 0X79, 0X33, 0X6B, 0X65, 0X79, 0X34};
      unsigned char key3[] = {0X6B, 0X65, 0X79, 0X35, 0X6B, 0X65, 0X79, 0X36};

        char out[1024] = {0};
      memset(out, 0x0, sizeof(out));

      hexdump(buffer,strlen(buffer2)) ;

      tripleKeyDES_CBCEncryption(buffer2, key, key2, key3, iv, buffer_length, out);

      //hex data
      int len = buffer_length;//strlen(out);
      printf("=======result  hex  ,length =%d \n", len);
      hexdump(out, len);
      printf(" \n");

      //base64
      unsigned char *buf = NULL;
      buf = base64_encode(out,len);
      printf("base64 =%s ", buf);
    
```


# output
```
==stop=======result  hex  ,length =40
 FB  51  9F  1C  41  82  A1  E7
 52  6F  63  C6  67  98  B3  EE
 18  2F  FE  7E  EC  57  12  A5
 4E  58  93  06  A5  D2  4B  BA
 81  4A  9A  1F  0E  3C  5A  01


base64 =+1GfHEGCoedSb2PGZ5iz7hgv/n7sVxKlTliTBqXSS7qBSpofDjxaAQ==
```


## php

```
$data1 ='this is a 3des-cbd-PKCS#5 example';

var_dump(strToHex2("thisthat"));
var_dump(strToHex2("key1key2key3key4key5key6"));

  $data = openssl_encrypt($data1, "DES-EDE3-CBC", 'key1key2key3key4key5key6', OPENSSL_RAW_DATA,'thisthat' );
  //file_put_contents("aa.dat",$data );
  //var_dump(strToHex2($data ));
  
echo $data2 = base64_encode($data) ; //+1GfHEGCoedSb2PGZ5iz7hgv/n7sVxKlTliTBqXSS7ppToK45SGCFQ==


function strToHex2($str){ 
    	$hex="";
		for($i=0;$i<strlen($str);$i++)
		$hex.="0X".dechex(ord($str[$i])).",";
		$hex=strtoupper($hex);
		return $hex;
}
```

## java
```
   public static final byte[] KEY    =
            {
                (BYTE)0X6B,(BYTE)0X65,(BYTE)0X79,(BYTE)0X31,(BYTE)0X6B,(BYTE)0X65,(BYTE)0X79,(BYTE)0X32,(BYTE)0X6B,(BYTE)0X65,(BYTE)0X79,(BYTE)0X33,(BYTE)0X6B,(BYTE)0X65,(BYTE)0X79,(BYTE)0X34,(BYTE)0X6B,(BYTE)0X65,(BYTE)0X79,(BYTE)0X35,(BYTE)0X6B,(BYTE)0X65,(BYTE)0X79,(BYTE)0X36
                  };

    public static final byte[] IV	=
            {
            BYTE)0X74,(BYTE)0X68,(BYTE)0X69,(BYTE)0X73,(BYTE)0X74,(BYTE)0X68,(BYTE)0X61,(BYTE)0X74 
            };
   public static void encrypt_des_ede_cbc_pkcs() throws Exception
    {
        byte[] in = "this is a 3des-cbd-PKCS#5 example".getBytes("UTF-8");
        Cipher cipher = Cipher.getInstance("DESede/CBC/PKCS5Padding");
        SecretKeyFactory skf = SecretKeyFactory.getInstance("DESede");
        SecretKey sk = skf.generateSecret(new DESedeKeySpec(KEY));
        IvParameterSpec ips = new IvParameterSpec(IV);
        cipher.init(Cipher.ENCRYPT_MODE, sk, ips);
        byte[] out = cipher.doFinal(in);
        System.out.println("appd JAVA emo===========");
        printBytes(out);
        System.out.println("appdemo  JAVA =========================");
    }
```

## online test
 
* [online test](https://www.devglan.com/online-tools/triple-des-encrypt-decrypt)
 
 
