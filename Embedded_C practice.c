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

SET, CLEAR, TOGGLE, TEST REGISTER BITS
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x00;

    reg |= (1u << 3);
    printf("After SET bit 3    : 0x%02X\n", reg);

    reg |= (1u << 5);
    printf("After SET bit 5    : 0x%02X\n", reg);

    reg &= (uint8_t)~(1u << 3);
    printf("After CLEAR bit 3  : 0x%02X\n", reg);

    reg ^= (1u << 1);
    printf("After TOGGLE bit 1 : 0x%02X\n", reg);

    printf("Bit 5: %s\n", (reg & (1u << 5)) ? "SET" : "CLEAR");

    return 0;
}

READ-MODIFY-WRITE REGISTER
    
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x91;
    uint8_t mode = 2;

    printf("Initial Register : 0x%02X\n", reg);

    reg |= (1u << 0);
    reg |= (1u << 1);
    reg &= (uint8_t)~(3u << 2);
    reg |= (uint8_t)(mode << 2);

    printf("Final Register   : 0x%02X\n", reg);

    return 0;
}

VOLATILE HARDWARE STATUS REGISTER

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    volatile uint8_t STATUS_REG = 0x00;

    printf("Waiting for sensor event...\n");

    STATUS_REG = 0x01;

    while ((STATUS_REG & 0x01) == 0)
    {
    }

    printf("Sensor Event Detected\n");

    return 0;
}

GPIO REGISTER CONTROLLER

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t GPIO_REG = 0x00;

    GPIO_REG |= (1u << 3);
    GPIO_REG |= (1u << 5);
    GPIO_REG &= (uint8_t)~(1u << 3);
    GPIO_REG ^= (1u << 6);

    printf("READ bit 5 : %s\n",
           (GPIO_REG & (1u << 5)) ? "ON" : "OFF");

    printf("Final GPIO Register : 0x%02X\n", GPIO_REG);

    return 0;
}

MODIFY A REGISTER FIELD WITHOUT AFFECTING OTHER BITS

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0xA7;
    uint8_t mode = 5;

    printf("Initial Register : 0x%02X\n", reg);

    reg &= (uint8_t)~(7u << 2);
    reg |= (uint8_t)((mode & 7u) << 2);

    printf("Final Register   : 0x%02X\n", reg);

    return 0;
}

EXTRACT REGISTER FIELD

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t STATUS_REG = 0xB5;

    uint8_t power = STATUS_REG & 0x01;
    uint8_t mode = (STATUS_REG >> 1) & 0x03;
    uint8_t speed = (STATUS_REG >> 3) & 0x03;
    uint8_t error = (STATUS_REG >> 5) & 0x01;
    uint8_t device_id = (STATUS_REG >> 6) & 0x03;

    printf("Power     : %s\n", power ? "ON" : "OFF");
    printf("Mode      : %u\n", (unsigned)mode);
    printf("Speed     : %u\n", (unsigned)speed);
    printf("Error     : %s\n", error ? "ON" : "OFF");
    printf("Device ID : %u\n", (unsigned)device_id);

    return 0;
}

CONFIGURE A PERIPHERAL CONTROL REGISTER 

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t enable = 1;
    uint8_t interrupt = 1;
    uint8_t mode = 3;
    uint8_t priority = 5;
    uint8_t reset = 0;

    uint8_t CONTROL_REG = 0x00;

    CONTROL_REG |= (uint8_t)(enable & 1u);
    CONTROL_REG |= (uint8_t)((interrupt & 1u) << 1);
    CONTROL_REG |= (uint8_t)((mode & 3u) << 2);
    CONTROL_REG |= (uint8_t)((priority & 7u) << 4);
    CONTROL_REG |= (uint8_t)((reset & 1u) << 7);

    printf("CONTROL_REG : 0x%02X\n", CONTROL_REG);

    return 0;
}

CLEAR BIT 4

    #include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0xFF;

    printf("Initial Register : 0x%02X\n", reg);

    reg &= (uint8_t)~(1u << 4);

    printf("Final Register   : 0x%02X\n", reg);

    return 0;
}
