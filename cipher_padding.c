//
// Created by jet on 2021/4/26.
//

#include "cipher_padding.h"

int get_padding_length(int data_length) {
    return 8 - data_length % 8;
}

//PKCS#5 padding
void padding_with_length(unsigned char *src, int src_length) {
    int padding_length = get_padding_length(src_length);
    int i = 0;
    for (; i < padding_length; i++) {
        src[src_length + i] = padding_length;
    }
    src[src_length+i] = '\0';
}