#include <stdio.h>
#include "base64encoder.h"
#include "nanotap.h"

uint8_t decoded[ 4 ];
uint8_t decoded_index = 0;

void encoded(char letter) {
    decoded[ decoded_index ++ ] = letter;
    printf( "%c", letter );
}

void clear() {
    memset( decoded, 0, sizeof(decoded) );
    decoded_index = 0;
}

int main() {
    ok( 1, "ok" );

    {
        uint8_t binary[] = {
            0x8E
        };
        clear();
        base64_encode( binary, 1, &encoded );
        printf("\n");

        ok( decoded[ 0 ] == 'j' );
        ok( decoded[ 1 ] == 'g' );
        ok( decoded[ 2 ] == '=' );
        ok( decoded[ 3 ] == '=' );
        ok( base64_length(1) == 4 );
    }

    {
        uint8_t binary[] = {
            0x8E, 0x76
        };
        clear();
        base64_encode( binary, 2, &encoded );
        printf("\n");

        ok( decoded[ 0 ] == 'j' );
        ok( decoded[ 1 ] == 'n' );
        ok( decoded[ 2 ] == 'Y' );
        ok( decoded[ 3 ] == '=' );
        ok( base64_length(2) == 4 );
    }

    {
        uint8_t binary[] = {
            0x8E, 0x76, 0x01
        };
        clear();
        base64_encode( binary, 3, &encoded );
        printf("\n");

        ok( decoded[ 0 ] == 'j' );
        ok( decoded[ 1 ] == 'n' );
        ok( decoded[ 2 ] == 'Y' );
        ok( decoded[ 3 ] == 'B' );
        ok( base64_length(3) == 4 );
    }

    // {
    //     uint8_t binary[] = {
    //         0x8E, 0x76, 0x1, 0x42, 0x70, 0x3, 0x40, 0x1,
    //         0x55, 0x42, 0x6, 0x54, 0x70, 0x42, 0x1, 0x55,
    //         0x42, 0x8, 0x55, 0x70, 0x42, 0x55, 0x42, 0x1,
    //         0x70, 0x42, 0x4, 0x50, 0x55, 0x42, 0x1, 0x70,
    //         0x42, 0xA, 0x55, 0x40, 0x1, 0x55, 0x42, 0x4,
    //         0x50, 0x70, 0x42, 0x1, 0x55, 0x42, 0xC, 0x55,
    //         0x50, 0x1, 0x70, 0x42, 0xA, 0x55, 0x40, 0x55,
    //         0x42, 0x1, 0x70, 0x42, 0x4, 0x50, 0x1, 0x55,
    //         0x42, 0x18, 0x55, 0x55, 0x55, 0x1, 0x70, 0x42,
    //         0x8, 0x55, 0x1, 0x55, 0x42, 0x8, 0x55, 0xC2,
    //         0x8E, 0x76, 0x42, 0x70, 0x42, 0x1, 0x55, 0x42,
    //         0x6, 0x54, 0x70, 0x42, 0x1, 0x55, 0x42, 0x8,
    //         0x55, 0x70, 0x42, 0x55, 0x42, 0x1, 0x70, 0x42,
    //         0x4, 0x50, 0x55, 0x42, 0x1, 0x70, 0x42, 0xA,
    //         0x55, 0x40, 0x1, 0x55, 0x42, 0x4, 0x50, 0x70,
    //         0x42, 0x1, 0x55, 0x42, 0x14, 0x55, 0x55, 0x50,
    //         0x1, 0x70, 0x42, 0x4, 0x50, 0x1, 0x55, 0x42,
    //         0x4, 0x50, 0x70, 0x42, 0x55, 0x42, 0x1, 0x70,
    //         0x42, 0x4, 0x50, 0x1, 0x55, 0x42, 0x6, 0x54,
    //         0x1, 0x70, 0x42, 0x4, 0x50, 0x1, 0x55, 0x42,
    //         0x6, 0x54, 0x70, 0x42, 0x1, 0x55, 0x42, 0x6,
    //         0x54, 0x1, 0x70, 0x42, 0x8, 0x55, 0x1, 0x55,
    //         0x42, 0x12, 0x55, 0x55, 0x40, 0x70, 0x42, 0x1,
    //         0x55, 0x42, 0xC, 0x55, 0x50, 0x1, 0x70, 0x42,
    //         0x8, 0x55, 0x1, 0x55, 0x42, 0x6, 0x54, 0x1,
    //         0x70, 0x42, 0x6, 0x54, 0x55, 0x42, 0x70, 0x42,
    //         0x1, 0x55, 0x42, 0xE, 0x55, 0x54, 0x70, 0x42,
    //         0x1, 0x55, 0x42, 0xA, 0x55, 0x40, 0x70, 0x42,
    //         0x1, 0x55, 0x42, 0x4, 0x50, 0x70, 0x42, 0x1,
    //         0x55, 0x42, 0x4, 0x50, 0x70, 0x42
    //     };
    //     clear();
    //     base64_encode( binary, 238, &encoded );
    //     printf("\n");
    // }

    done_testing();
}
