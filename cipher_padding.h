//
// Created by jet on 2021/4/26.
//

#ifndef INC_3DES_CBC_PKCS5PADDING_CIPHER_PADDING_H
#define INC_3DES_CBC_PKCS5PADDING_CIPHER_PADDING_H

int get_padding_length (int data_length) ;
char *padding_with_length(const char *src, int src_length);

#endif //INC_3DES_CBC_PKCS5PADDING_CIPHER_PADDING_H
