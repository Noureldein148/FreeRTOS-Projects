#ifndef BITMATH_H_INCLUDED
#define BITMATH_H_INCLUDED

#define SetBit(REG,bit)    REG|=(1<<bit)
#define ClearBit(REG,bit)  REG&=(~(1<<bit))
#define ToggleBit(REG,bit) REG^= (1<<bit)
#define GetBit(REG,bit)   (REG>>bit)&1





#endif // BITMATH_H_INCLUDED
