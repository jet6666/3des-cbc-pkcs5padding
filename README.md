 
##c
```
    unsigned char buffer[] = "this is a 3des-cbd-PKCS#5 exampl";
    padding_with_length(buffer, strlen(buffer));
    //iv = thisthat
    unsigned  char iv[] = {0X74, 0X68, 0X69, 0X73, 0X74, 0X68, 0X61, 0X74};
    printf("iv = %s \n", iv);

    //key = key1key2key3key4key5key6key7key8
    unsigned char key[] = {0X6B, 0X65, 0X79, 0X31, 0X6B, 0X65, 0X79, 0X32};
    unsigned char key2[] = {0X6B, 0X65, 0X79, 0X33, 0X6B, 0X65, 0X79, 0X34};
    unsigned char key3[] = {0X6B, 0X65, 0X79, 0X35, 0X6B, 0X65, 0X79, 0X36};
    
    unsigned char out[1024] = {0};
    memset(out, 0x0, sizeof(out));
    tripleKeyDES_CBCEncryption(buffer, key, key2, key3, iv, buffer_length, out);
    
    //base64
    unsigned char *buf = NULL;
    buf = base64_encode(out);
    printf("base64 =%s ", buf); 
    
```


##php

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

##java
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

##online test
 

* [online test](https://www.devglan.com/online-tools/triple-des-encrypt-decrypt)
 
 
