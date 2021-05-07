cmake_minimum_required(VERSION 3.14)
project(3des_cbc_pkcs5padding C)

set(CMAKE_C_STANDARD 99)

include_directories(DES)

add_library(DES  STATIC
        DES/keyGeneration.c
        DES/BitPermutationFunctions.c
        DES/DESEncrypt.c
        DES/DESDecrypt.c
        DES/FileReader.c
        DES/DataPrint.c
        DES/keyReader.c
        DES/CBCDESEncryption.c
        DES/CBCDESDecryption.c
        DES/tripleDESCBCEncryption.c
        DES/tripleDESCBCDecryption.c
        DES/tripleKeyDESCBCEncryption.c
        DES/tripleKeyDESCBCDecryption.c
        )

add_executable(3des_cbc_pkcs5padding main.c utils.h utils.c cipher_padding.h cipher_padding.c  )
target_link_libraries(3des_cbc_pkcs5padding DES)