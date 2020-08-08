#include <stdio.h>
#include <stdint.h> //to specify datatypes as uint16_t

#define SET_BIT(BF, N) BF |= (1 << N)
#define CLR_BIT(BF, N) BF &= ~(1 << N) 
#define IS_BIT_SET(BF, N) ((BF>>N) & 1)
#define INVERT_BIT(BF, N) BF^= 1<<N


int main()
{
    uint8_t value = 0x00; //0b00000000
    INVERT_BIT(value, 7);
    printf("%d\n", value);
    
}
