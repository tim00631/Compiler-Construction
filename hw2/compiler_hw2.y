/*	Definition section */
%{
#include "global.h"
#include <stdio.h>
#include <string.h>
extern int yylineno;
extern int yylex();
void yyerror(char* s);
extern char* yytext;   // Get current token from lex
extern char buf[2048];  // Get current code line from lex
extern int syntax_error;
extern int semantic_error;
extern int NumberOfError;
extern int syn_error_number;
extern int dump_flag;
extern char* error_msg[20];
extern char* syn_error_msg[20];
char last_function[100];
char *attr = "int, int";
/* Symbol Table Structure, Variable Definition */
typedef struct Entry Entry;
struct Entry {
    int index;
    char* name;
    char* kind;
    char* type;
    int scope;
    char* attribute;
    Entry *next;
};
typedef struct Header Header;
struct Header {
    int depth;
    int entry_num;
    Entry *table_root;
    Entry *table_tail;
    Header *pre;
};

Header *header_root = NULL; //connect these headers
Header *cur_header = NULL; //current header
//int entry_num = 0; // to record the number of entries
int depth = 0;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol_table();
void insert_symbol(Header *header, char* name, char* kind, char* type);
void dump_symbol();
void add_attribute(Header *header, char* attribute);
/* Syntax Error Check Function and Semantic Error Check Function Declaration*/
void syntax_check();
void undeclared_check(char* name, char* type);
void redeclared_check(char* name, char* type);
%}
/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    Value val;
    char* type;
}

/* Token without return */
%token INC DEC
%token MTE LTE EQ NE
%token ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT 
%token PRINT 
%token IF ELSE FOR WHILE RETURN SEMICOLON
/* Token with return, which need to sepcify type */
%token <type> VOID INT FLOAT BOOL STRING
%token <val> TRUE FALSE
%token <val> I_CONST F_CONST STR_CONST
%token <val> ID
/* Nonterminal with return, which need to sepcify type */
%type <val> expression
%type <val> parenthesis_clause postfix_expr multiplication_expr
%type <val> addition_expr comparison_expr 
%type <val> constant function_call
%type <type> type
%type <type> parameter parameter_list
/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    |
    ;
stat
    : declaration { }
    | func_declaration { }
    | function_call { }
    | compound_stat { }
    | expression_stat { }
    | return_stat 
    | print_func
    | SEMICOLON { }
    ;
declaration
    : type ID '=' expression SEMICOLON { insert_symbol(cur_header, $2.string, "variable", $1); }
    | type ID SEMICOLON { insert_symbol(cur_header, $2.string, "variable", $1); }
    ;
type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
    ;
func_declaration
    : type ID { insert_symbol(cur_header, $2.string, "function", $1); } '(' { create_symbol_table(); } parameter_list ')' block { dump_flag = 1; } 
    ;
parameter_list
	: parameter { $$ = $1; }
	| parameter_list ',' parameter 
    | {}
	;
parameter
    : type ID { $$ = $1; insert_symbol(cur_header, $2.string, "parameter", $1); }
    ; 
function_call
    : ID { undeclared_check($1.string, "function"); } '(' argument_list ')' SEMICOLON
    ;
argument_list
    : ID { undeclared_check($1.string, "variable"); }
    | argument_list ',' ID { undeclared_check($3.string, "variable"); }
    | { }
    ;
compound_stat
    : assign_stat
    | if_stat
    | while_stat
    ;
assign_stat
    : ID { undeclared_check($1.string, "variable"); } assign_op expression SEMICOLON
    ;
assign_op
    :'='
    | ADDASGN
    | SUBASGN
    | MULASGN
    | DIVASGN
    | MODASGN
    ;
if_stat
    : IF expression block
    | IF expression block ELSE block
    | IF expression block ELSE if_stat
    ;
while_stat
    : WHILE expression block
    ;
block
    : lb program rb 
    ;
lb
    : '{' 
    ;
rb
    : '}'
    ;
expression_stat
    : expression
    ;
expression
    : comparison_expr
    ;
constant
    : I_CONST
    | F_CONST
    | '"' STR_CONST '"' { $$ = $2; }
    ;
post_op
    : INC
    | DEC
    ;
mul_op
    : '*'
    | '/'
    | '%'
    ;
add_op
    : '+'
    | '-'
    ;
cmp_op
    : '<'
    | '>'
    | MTE
    | LTE
    | EQ
    | NE
    ;
parenthesis_clause
    : constant {  }
    | ID { undeclared_check($1.string, "variable"); }
    | '(' expression ')' {  }
    | TRUE {  }
    | FALSE {  }
    | function_call
    ;
postfix_expr
    : parenthesis_clause
    | parenthesis_clause post_op
    ;
multiplication_expr
    : postfix_expr
    | multiplication_expr mul_op postfix_expr
    ;
addition_expr
    : multiplication_expr
    | addition_expr add_op multiplication_expr
    ;
comparison_expr
    : addition_expr
    | comparison_expr cmp_op addition_expr
    ;
return_stat
    : RETURN SEMICOLON
	| RETURN expression 
	;
print_func
    : PRINT '(' expression ')' SEMICOLON
    | PRINT '(' '"' STRING '"' ')' SEMICOLON
    ;
%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();
    if(!syntax_error){
        dump_symbol();
        printf("\nTotal lines: %d \n",yylineno);
    }
    return 0;
}

void yyerror(char *s)
{
    if(!strcmp(s,"syntax error")){
        printf("%d: %s\n", yylineno+1, buf);
        syntax_error = 1;
        if(semantic_error){
            for (int i = 0; i< NumberOfError;i++){
                printf("\n|-----------------------------------------------|\n");
                printf("| Error found in line %d: %s\n", yylineno, buf);
                printf("| %s", error_msg[i]);
                printf("\n|-----------------------------------------------|\n\n");
                memset(error_msg[i],'\0', 200);
            }
            semantic_error = 0;
            NumberOfError = 0;
        }
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");        

    } else {     
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", s);
        printf("\n|-----------------------------------------------|\n\n");
    }
}

void create_symbol_table() {
    Header *ptr = malloc(sizeof(Header));
    ptr->depth = depth++;
    ptr->entry_num = 0;
    ptr->table_root = malloc(sizeof(Entry));
    ptr->table_root->next = NULL;
    ptr->table_tail = ptr->table_root;
    if(cur_header == NULL) header_root = ptr;
    //printf("create a table: %d\n", ptr->depth);
    ptr->pre = cur_header;
    cur_header = ptr;
}
void insert_symbol(Header *header, char* name, char* kind, char* type){
    if(cur_header == NULL){
        create_symbol_table();
        header_root = cur_header;
        header = cur_header;
    }
    if(lookup_symbol(cur_header, name) == -1){
        Entry *temp = malloc(sizeof(Entry));
        temp->index = cur_header->entry_num++;
        temp->name = name;
        temp->kind = kind;
        temp->type = type;
        temp->scope = header->depth;
        temp->next = NULL;
        if(!strcmp(name,"loop")){
            //printf("hello");
            temp->attribute = attr;
        }
        else{
            temp->attribute = "";
        }
        header->table_tail->next = temp;
        header->table_tail = header->table_tail->next;
        // printf("%-10d%-10s%-12s%-10s%-10d%-10s\n", temp->index, temp->name, temp->kind, temp->type, temp->scope, temp->attribute);

    } else{
        redeclared_check(name, kind);
    }
}
void add_attribute(Header *header,char* attribute){
    // //printf("atrribute: %s\n", attribute);
    // Entry *cur = cur_header->pre->table_root->next;
    // while(cur != NULL){
    //     //printf("%s\n",cur->name);
    //     //printf("%s\n",last_function);
    //     if(!strcmp(cur->name,last_function)){
    //         cur->attribute = "int,int";
    //         // if(!strcmp(cur->attribute,"")){
    //         //     printf("ya");
    //         //     cur->attribute = attribute;
    //         // } else{
    //         //     char* temp;
    //         //     sprintf(temp,"%s,%s",cur->attribute,attribute);
    //         //     cur->attribute = "int,int";   
    //         // }
    //         break;
    //     }
    //     else{
    //         //printf("else\n");
    //         cur = cur->next;
    //     }
    // }
    //printf("out\n");
}
int lookup_symbol(Header *header, char* name) { 
    // return index 0~n :redeclared
    // return -1, undeclared
    if(header->table_root == NULL){
        return -1;
    }
    Entry *cur = header->table_root->next;
    while(cur != NULL){
        if(!strcmp(cur->name,name))
        {
            return cur->index;
        }
        else{
            cur = cur->next;
        }
    }
    return -1;
}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    Entry *cur = cur_header->table_root->next;
    while(cur != NULL) {
        if(strcmp(cur->attribute, "")) {
            printf("%-10d%-10s%-12s%-10s%-10d%s\n", cur->index, cur->name, cur->kind, cur->type, cur->scope, cur->attribute);
        }
        else {
            printf("%-10d%-10s%-12s%-10s%-10d\n", cur->index, cur->name, cur->kind, cur->type, cur->scope);
        }
        Entry *temp = cur;
        free(temp);
        temp = NULL;
        cur = cur->next;
    }
    printf("\n");
    cur_header->entry_num = 0;
    cur_header = cur_header->pre;
    depth = depth -1;
}

void undeclared_check(char* name, char* type){
        int undeclared = 1;
        Header *ptr = cur_header;
        while(ptr != NULL){
            if(lookup_symbol(ptr,name) != -1){
                undeclared = 0;
                break;
            } else {
                ptr = ptr->pre; // goto parent scope
            }
        }
        if(undeclared){
            if(!strcmp(type, "function")){
                error_msg[NumberOfError] = malloc(200);
                sprintf(error_msg[NumberOfError++],"Undeclared function %s", name);
                semantic_error = 1;
            } else if(!strcmp(type, "variable")){
                error_msg[NumberOfError] = malloc(200);
                sprintf(error_msg[NumberOfError++],"Undeclared variable %s", name);
                semantic_error = 1;
            }
        }
}
void redeclared_check(char* name, char* type){
    //printf("%s\n",type);
    if(!strcmp(type, "function")){
        sprintf(error_msg[NumberOfError++],"Redeclared function %s", name);
        semantic_error = 1;
    } else if(!strcmp(type, "variable")){
        sprintf(error_msg[NumberOfError++],"Redeclared variable %s", name);
        semantic_error = 1;
    }
}
