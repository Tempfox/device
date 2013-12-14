#include "base64encoder.h"

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

uint16_t base64_length(uint16_t input_length) {
    return ((input_length + 2) / 3) * 4;
}

void base64_encode(const uint8_t *input,
                   uint16_t input_length,
                   Base64EncodeCallback callback) {
    uint16_t i;
    uint8_t input_a,input_b,input_c;

    for (i = 0; i < input_length;) {

        input_a = input[ i++ ];
        callback( encoding_table[  (input_a & 0xFC) >> 2 ] );

        if (i < input_length) {
            input_b = input[ i++ ];
            callback( encoding_table[ ((input_a & 0x03) << 4) + ((input_b & 0xF0) >> 4) ] );
        }
        else {
            input_b = 0;
            callback( encoding_table[ ((input_a & 0x03) << 4) + ((input_b & 0xF0) >> 4) ] );
            callback( '=' );
            callback( '=' );
            break;
        }

        if (i < input_length) {
            input_c = input[ i++ ];
            callback( encoding_table[ ((input_b & 0x0F) << 2) + ((input_c & 0xC0) >> 6) ] );
            callback( encoding_table[   input_c & 0x3F ] );
        }
        else {
            input_c = 0;
            callback( encoding_table[ ((input_b & 0x0F) << 2) + ((input_c & 0xC0) >> 6) ] );
            callback( '=' );
            break;
        }
    }
}
