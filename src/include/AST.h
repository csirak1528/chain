#ifndef TAC_AST_H
#define TAC_AST_H
#include "list.h"
typedef struct AST_STRUCT
{
    enum
    {
        AST_COMPOUND,
        AST_FUNCTION,
        AST_CALL,
        AST_DEFINITION,
        AST_DEFINITION_TYPE,
        AST_VARIABLE,
        AST_STATEMENT,
        ASt_INT,
        AST_ASSIGNEMNT,
        AST_NOOP,
    } type;

    char *name;
    struct AST_STRUCT *value;
    list_C *children;
    int data_type;
    int int_value;
    
} AST_C;

AST_C *init_ast(int type);
#endif