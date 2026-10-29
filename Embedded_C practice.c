#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t REGISTER = 0x00;
    uint8_t *reg_ptr = &REGISTER;
    uint8_t write_value = 0x5A;

    printf("Initial Register : 0x%02X\n", *reg_ptr);

    *reg_ptr = write_value;

    printf("Written Value    : 0x%02X\n", write_value);
    printf("Register Value   : 0x%02X\n", *reg_ptr);

    return 0;
}
