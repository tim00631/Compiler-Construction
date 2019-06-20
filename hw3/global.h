#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef enum { NotCalculated ,Calculated } State;
typedef enum { VOID_T, INT_T, FLOAT_T, STRING_T, BOOL_T, ID_T, NAT} Type;
typedef enum {
    ADD_OP, SUB_OP, MUL_OP, DIV_OP, MOD_OP, INC_OP, DEC_OP,
    MT_OP, LT_OP, MTE_OP, LTE_OP, EQ_OP, NE_OP,
    ASGN_OP, ADDASGN_OP, SUBASGN_OP, MULASGN_OP, DIVASGN_OP, MODASGN_OP,
    PRINT_OP
} Operator;

typedef struct Value Value;
struct Value {
    Type type;
    int i_val;
    float f_val;
    char* string;
    State state;
};
#endif