//
// Created by naruto on 16/08/11.
//

#ifndef SPECK_H
#define SPECK_H

#include <stdint.h>

typedef struct speck_ctx_t_ speck_ctx_t;

// number of round
enum speck_encrypt_type {
    SPECK_ENCRYPT_TYPE_32_64 = 0,
    SPECK_ENCRYPT_TYPE_48_72,
    SPECK_ENCRYPT_TYPE_48_96,
    SPECK_ENCRYPT_TYPE_64_96,
    SPECK_ENCRYPT_TYPE_64_128,
    SPECK_ENCRYPT_TYPE_96_96,
    SPECK_ENCRYPT_TYPE_96_144,
    SPECK_ENCRYPT_TYPE_128_128,
    SPECK_ENCRYPT_TYPE_128_192,
    SPECK_ENCRYPT_TYPE_128_256,
};

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

speck_ctx_t *speck_init(enum speck_encrypt_type type, const uint64_t key[2]);

speck_ctx_t *speck_init2(enum speck_encrypt_type type, const unsigned char *key);

void speck_encrypt(speck_ctx_t *ctx, const uint64_t plaintext[2],uint64_t ciphertext[2]);

void speck_decrypt(speck_ctx_t *ctx, const uint64_t ciphertext[2], uint64_t decrypted[2]);

int speck_encrypt_ex(speck_ctx_t *ctx, const unsigned char *plain, unsigned char *crypted, int plain_len);

int speck_decrypt_ex(speck_ctx_t *ctx, const unsigned char *crypted, unsigned char *decrypted, int crypted_len);

void speck_finish(speck_ctx_t **ctx);

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //SPECK_H
