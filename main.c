// ********************************
// * Examples of bitwise manipulation in C taken from various locations
// * 1. https://github.com/davepl/MACRO-11/blob/main/SIEVE.C
// * 2. https://stackoverflow.com/questions/11815894/how-to-read-write-arbitrary-bits-in-c-c
// ********************************

#include <stdio.h>
#include <stdlib.h>
#define PRINT(message) printf("%s",message);
typedef unsigned char byte;

#define BITSPERBYTE 8

#define GET_BIT(array, n) ((array[(n) / BITSPERBYTE] >> ((n) % BITSPERBYTE)) & 1)
#define SET_BIT(array, n) (array[(n) / BITSPERBYTE] |= (1 << ((n) % BITSPERBYTE)))

int main()
{
    PRINT("\nReading and manipulating individual bits in an array\n");
    PRINT("****************************************************\n");
    
    size_t size = 3; // # of "objects" to have space allocated for.

    byte *sieve = (byte *) calloc(size,1); //allocate space for "size" number of objects, each 1 byte in size.
    // sieve pointer is currently at:
    //                   Lower <--- mem ---> Higher 
    //                   *
    // byte              00000000 11111111 22222222
    // bits of byte      01234567 01234567 01234567
    // bit num in array  0        8        16

    printf("Address byte 0 = %p \n", sieve);
    sieve++;
    printf("Address byte 1 = %p \n", sieve);
    sieve++;
    printf("Address byte 2 = %p \n", sieve);

    // Set the 0th position bit in the 0th byte to 1 (i.e. "bit num in array" 0 to 1).
    // Owing to little endian-ness, this results is a value of 1 being set in the first byte.
    SET_BIT(sieve,0); 
    // sieve[0] = 1; // This would also have done the same thing.
    printf("BYTE 0 = %d (%d%d%d%d%d%d%d%d)\n",sieve[0], GET_BIT(sieve,7),GET_BIT(sieve,6),GET_BIT(sieve,5),GET_BIT(sieve,4),GET_BIT(sieve,3),GET_BIT(sieve,2),GET_BIT(sieve,1),GET_BIT(sieve,0));
    
    // Now set bit 6 (the 64 bit). Results is a new total value of 65 being stored.
    SET_BIT(sieve,6);  
    printf("BYTE 0 = %d (%d%d%d%d%d%d%d%d)\n",sieve[0], GET_BIT(sieve,7),GET_BIT(sieve,6),GET_BIT(sieve,5),GET_BIT(sieve,4),GET_BIT(sieve,3),GET_BIT(sieve,2),GET_BIT(sieve,1),GET_BIT(sieve,0));
    
    SET_BIT(sieve,8); 
    //sieve[1] = 1; // This would also have done the same thing.
    printf("BYTE 1 = %d (%d%d%d%d%d%d%d%d)\n",sieve[1], GET_BIT(sieve,15),GET_BIT(sieve,14),GET_BIT(sieve,13),GET_BIT(sieve,12),GET_BIT(sieve,11),GET_BIT(sieve,10),GET_BIT(sieve,9),GET_BIT(sieve,8));
    
    // Now set bit 9 (the 2 bit). Results is a new total value of 3 being stored.
    SET_BIT(sieve,9); 
    //sieve[1] = 3; // This would also have done the same thing. 
    printf("BYTE 1 = %d (%d%d%d%d%d%d%d%d)\n",sieve[1], GET_BIT(sieve,15),GET_BIT(sieve,14),GET_BIT(sieve,13),GET_BIT(sieve,12),GET_BIT(sieve,11),GET_BIT(sieve,10),GET_BIT(sieve,9),GET_BIT(sieve,8));
    

    PRINT("\nBitwise examples on whole bytes\n");
    PRINT("*******************************\n");
    int x = 7;       // 00000110
    int y = 10;      // 00001100
    byte result = 0; // 00000000

    result = x & y;
    printf("AND = %d\n", result);

    result = x | y;
    printf("OR  = %d\n", result);

    result = x ^ y;
    printf("XOR = %d\n", result);

    result = x << 1;
    printf("Left Shift 1 place = %d (0x%x)\n", result, result);

    return 0;
}