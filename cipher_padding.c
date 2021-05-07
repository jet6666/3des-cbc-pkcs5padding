//
// Created by jet on 2021/4/26.
//

#include "cipher_padding.h"


int get_padding_length(int data_length) {
    return 8 - data_length % 8;
}


//PKCS#5 padding
char *padding_with_length(const char *src, int src_length) {
    int padding_length = get_padding_length(src_length);
    char *res = (char *) malloc(src_length + padding_length + 1);
    int i = 0;
    memcpy(res, src, src_length);
    for (; i < padding_length; i++) {
        res[src_length + i] = padding_length;
    }
    res[src_length + i] = '\0';
    return res;
}