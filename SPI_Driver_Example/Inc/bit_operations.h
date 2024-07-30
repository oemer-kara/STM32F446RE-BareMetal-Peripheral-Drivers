#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

#define SET_BIT(register, bit)    ((register) |= (1 << (bit)))
#define CLEAR_BIT(register, bit)  ((register) &= ~(1 << (bit)))
#define TOGGLE_BIT(register, bit) ((register) ^= (1 << (bit)))
#define CHECK_BIT(register, bit)  ((register) & (1 << (bit)))

#endif