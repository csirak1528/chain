#include "include/token.h"
#include "include/parser.h"
#include "include/types.h"
#include "include/AST.h"

#include <stdlib.h>
#include <string.h>

parser_C *init_parser(lexer_C *lexer)
{
    parser_C *parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->token = lexer_next_token(lexer);

    return parser;
}

token_C *parser_eat(parser_C *parser, int type)
{
    if (parser->token->type != type)
    {
        printf("[Parser]: Unexpected token: %s\n", token_to_str(parser->token->type));
        printf("[Parser]: Expected: %s\n", token_to_str(type));
        exit(1);
    }
    parser->token = lexer_next_token(parser->lexer);
    return parser->token;
}

AST_C *parser_parse(parser_C *parser)
{
    return parser_parse_compound(parser);
}

AST_C *parser_parse_block(parser_C *parser)
{
    parser_eat(parser, TOKEN_LCURL);
    AST_C *ast = init_ast(AST_COMPOUND);
    while (parser->token->type != TOKEN_RCURL)
    {
        list_push(ast->children, parser_parse_expr(parser));
    }
    parser_eat(parser, TOKEN_RCURL);

    return ast;
}

AST_C *parser_parse_id(parser_C *parser)
{
    char *value = calloc(strlen(parser->token->value) + 1, sizeof(char));
    strcpy(value, parser->token->value);
    parser_eat(parser, TOKEN_ID);
    if (parser->token->type == TOKEN_EQUALS)
    {
        parser_eat(parser, TOKEN_EQUALS);
        AST_C *ast = init_ast(AST_ASSIGNEMNT);
        ast->name = value;
        printf("-->%s\n", ast->name);
        ast->value = parser_parse_expr(parser);
        if (parser->token->type == TOKEN_LCURL)
        {
            ast->type = AST_FUNCTION;
            ast->value = parser_parse_block(parser);
        }
        else
        {
            parser_eat(parser, TOKEN_SEMICOLON);
        }
        return ast;
    }

    AST_C *ast = init_ast(AST_VARIABLE);
    ast->name = value;
    if (parser->token->type == TOKEN_COLON)
    {
        parser_eat(parser, TOKEN_COLON);
        ast->data_type = typename_to_int(parser->token->value);
        parser_eat(parser, TOKEN_ID);
        if (parser->token->type == TOKEN_LBRACKET)
        {
            parser_eat(parser, TOKEN_LBRACKET);
            if (parser->token->type == TOKEN_ID)
            {
                parser_eat(parser, TOKEN_ID);
            }
            parser_eat(parser, TOKEN_RBRACKET);
        }
    }
    else if (parser->token->type == TOKEN_LPAREN)
    {
        ast->type = AST_CALL;
        ast->children = parser_parse_list(parser);
    }

    return ast;
}

AST_C *parser_parse_int(parser_C *parser)
{
    int value = atoi(parser->token->value);
    parser_eat(parser,TOKEN_INT);
    AST_C* ast = init_ast(TOKEN_INT);
    ast->int_value = value; 
}

AST_C *parser_parse_expr(parser_C *parser)
{
    switch (parser->token->type)
    {
    case TOKEN_ID:
        return parser_parse_id(parser);
    case TOKEN_LPAREN:
        return parser_parse_list(parser);
    case TOKEN_INT:
        return parser_parse_int(parser);
    default:
    {
        printf("[Parser]: Unexpected Token `%s`\n", token_to_str(parser->token->type));
        parser_eat(parser, parser->token->type);
        return 0;
    }
    }
}

AST_C *parser_parse_list(parser_C *parser)
{
    parser_eat(parser, TOKEN_LPAREN);
    AST_C *ast = init_ast(AST_COMPOUND);
    list_push(ast->children, parser_parse_expr(parser));

    while (parser->token->type == TOKEN_COMMA)
    {
        parser_eat(parser, TOKEN_COMMA);
        list_push(ast->children, parser_parse_expr(parser));
    }
    parser_eat(parser, TOKEN_RPAREN);

    if (parser->token->type == TOKEN_COLON)
    {
        parser_eat(parser, TOKEN_COLON);
        ast->data_type = typename_to_int(parser->token->value);
        parser_eat(parser, TOKEN_ID);
        if (parser->token->type == TOKEN_LBRACKET)
        {
            parser_eat(parser, TOKEN_LBRACKET);
            if (parser->token->type == TOKEN_ID)
            {
                parser_eat(parser, TOKEN_ID);
            }
            parser_eat(parser, TOKEN_RBRACKET);
        }
    }
    return ast;
}

AST_C *parser_parse_compound(parser_C *parser)
{
    AST_C *compound = init_ast(AST_COMPOUND);

    while (parser->token->type != TOKEN_EOF)
    {
        list_push(compound->children, parser_parse_expr(parser));
    }
    return compound;
}