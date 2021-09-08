#ifndef CHAIN_TOKEN_H
#define CHAIN_TOKEN_H

typedef struct TOKEN_STRUCT
{
    char *value;
    enum
    {
        TOKEN_ID,
        TOKEN_INT,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_COMMA,
        TOKEN_LCURL,
        TOKEN_RCURL,
        TOKEN_SEMICOLON,
        TOKEN_COLON,
        TOKEN_QOUTE,
        TOKEN_EQUALS,
        TOKEN_EOF
    } type;
} token_C;

token_C* init_token(char* val, int type);
#endif
