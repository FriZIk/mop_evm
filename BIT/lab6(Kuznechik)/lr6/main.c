#include <stdio.h>
#include <time.h>
#include "kuznechik.h"
#include <locale.h>

void kuz_init();

int main(int argc, char **argv)
{   
    setlocale(0, "Russian");
    
    const uint8_t testvec_key[32] = {
        0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
        0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10, 
        0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF  
    };
    const uint8_t testvec_pt[16] = {
        0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x00, 
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
    };

    int i;
    kuz_key_t key;
    w128_t x;

    printf("Установка 32 байтного ключа для шифрования...\n");
    kuz_set_encrypt_key(&key, testvec_key);


    printf("Список раундовых ключей:\n");
    for (i = 0; i < 10; i++) {  
        printf("K_%d\t=", i + 1);
        print_w128(&key.k[i]);
    }


    printf("Исходные данные:\n");
    for (i = 0; i < 16; i++)
        x.b[i] = testvec_pt[i];
    printf("PT\t=");
    print_w128(&x);

    printf("Шифрование ... \n");
    kuz_encrypt_block(&key, &x);

    printf("Результат шифрования:\t");
    print_w128( (w128_t *) &x );

    
    printf("Установка 32 байтного ключа для дешифрования...\n");

    kuz_set_decrypt_key(&key, testvec_key);

    printf("Дешифрование ... \n");
    
    print_w128( (w128_t *) &x );

    printf("\n");

    kuz_decrypt_block(&key, &x);
    
    printf("Расшифрованные данные:\n");
    printf("PT =");
    print_w128(&x);
}
