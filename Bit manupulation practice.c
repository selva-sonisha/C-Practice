SET BIT 3

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x05;

    printf("Before setting bit: 0x%02X\n", reg);
    reg|=(1<<3);
    printf("After setting bit:  0x%02X\n", reg);

    return 0;
}

CLEAT BIT 2

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x0F;

    printf("Before clearing bit: 0x%02X\n", reg);
    reg&=~(1<<2);
    printf("After clearing bit:  0x%02X\n", reg);

    return 0;
}

TOGGLE BIT 1

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x05;

    printf("Before Toggling bit: 0x%02X\n", reg);
    reg^=(1<<1);
    printf("After Toggling bit:  0x%02X\n", reg);

    return 0;
}

CHECK BIT POSITION 3

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x08;

    if ( reg&=(1<<3) )
        printf("Bit is SET\n");
    else
        printf("Bit is CLEAR\n");

    return 0;
}

SWAP THE LOWER AND UPPER BITS

#include <stdio.h>
#include <stdint.h>
int main(void) {
    uint8_t value, result;
    printf("Enter an 8-bit hexadecimal value: ");
    scanf("%hhx", &value); 
    result = (uint8_t)((value << 4) | (value >> 4));
    printf("Original = 0x%02X\n", value); 
    printf("Swapped  = 0x%02X\n", result); 
    return 0;
}

REVERSE THE BIT

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t value, result = 0;

    printf("Enter an 8-bit hexadecimal value: ");
    scanf("%hhx", &value);

    for (int i = 0; i < 8; i++)
    {
        result <<= 1;
        result |= value & 1U;
        value >>= 1;
    }

    printf("Reversed = 0x%02X\n", result);

    return 0;
}
