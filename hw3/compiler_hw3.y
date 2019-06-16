/*	Definition section */
%{
#include "global.h" // include header if needed
#define BUF_SIZE 1000

extern int yylineno;
extern int yylex();
extern char *yytext; // Get current token from lex
extern char buf[BUF_SIZE]; // Get current code line from lex
char code_buf[100];
FILE *file; // To generate .j file for Jasmin

void yyerror(char *s);

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
Header *header_root = NULL; // connect these headers
Header *cur_header = NULL; // current header
int depth = 0;
Value NaV;

extern int syntax_error;
extern int semantic_error;
extern int NumberOfError;
extern int syn_error_number;
extern int dump_flag;
extern char* error_msg[20];
extern char* syn_error_msg[20];
void redeclared_check(char* name,char* kind);
void undeclared_check(char* name,char* kind);
char* add_attribute(Header *header);
/* symbol table functions */
char* convert_type(Type type);
int lookup_symbol(Header *header, char* name);
void create_symbol_table();
void free_symbol_table();
void insert_symbol(Header *header, Value id, char* kind, Value type, Value R_val);
void dump_symbol();
void debug(char* s);
/* code generation functions, just an example! */
void gencode(char * s);
void do_declaration_stat(int index, Value type, Value id, Value R_val);
void do_function_definition(Entry *temp);
char* str_replace(char* string, const char* substr, const char* replacement);
%}

%union {
    struct Value val;
    Operator op;
}

/* Token */
%token IF ELSE FOR WHILE RETURN SEMICOLON
%token <op> INC DEC
%token <op> MTE LTE EQ NE
%token <op> ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token <op> PRINT 
%token <val> VOID INT FLOAT BOOL STRING
%token <val> TRUE FALSE
%token <val> I_CONST F_CONST STR_CONST
%token <val> ID

/* Non-terminal with return, which need to sepcify type */
%type <op> assign_op
%type <val> expression
%type <val> parenthesis_clause postfix_expr multiplication_expr
%type <val> addition_expr comparison_expr 
%type <val> constant function_call
%type <val> type
%type <val> parameter parameter_list

/* Token with return */


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
    : type ID '=' expression SEMICOLON { insert_symbol(cur_header, $2, "variable", $1, $4); }
    | type ID SEMICOLON { insert_symbol(cur_header, $2, "variable", $1, NaV); }
    ;
type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
    ;
func_declaration
    : type ID '(' { create_symbol_table(); } parameter_list ')' {insert_symbol(cur_header->pre, $2, "function", $1, NaV); } block { dump_flag = 1; } 
    ;
parameter_list
	: parameter { $$ = $1; }
	| parameter_list ',' parameter 
    | {}
	;
parameter
    : type ID { $$ = $1; insert_symbol(cur_header, $2, "parameter", $1, NaV); }
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
    :'=' {}
    | ADDASGN {$$ = ADDASGN_OP;}
    | SUBASGN {$$ = SUBASGN_OP;}
    | MULASGN {$$ = MULASGN_OP;}
    | DIVASGN {$$ = DIVASGN_OP;}
    | MODASGN {$$ = MODASGN_OP;}
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
    : PRINT '(' expression ')' SEMICOLON {}
    | PRINT '(' '"' STRING '"' ')' SEMICOLON
    ;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    NaV.type == NAT;
    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n"
                    ".method public static main([Ljava/lang/String;)V\n");
    yyparse();
    // fprintf(file, "\treturn\n"
    //               ".end method\n");
    if(!syntax_error){
        dump_symbol();
        printf("\nTotal lines: %d \n",yylineno);
    }
    fclose(file);

    return 0;
}

// void yyerror(char *s)
// {
//     printf("\n|-----------------------------------------------|\n");
//     printf("| Error found in line %d: %s\n", yylineno, buf);
//     printf("| %s", s);
//     printf("\n| Unmatched token: %s", yytext);
//     printf("\n|-----------------------------------------------|\n");
//     exit(-1);
// }
void yyerror(char *s)
{
    if(!strcmp(s,"syntax error")){
        printf("%d: %s\n", yylineno, buf);
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

/* stmbol table functions */
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
void insert_symbol(Header *header, Value id, char* kind, Value type, Value R_val){
    if(cur_header == NULL){
        create_symbol_table();
        // header_root = cur_header;
        header = cur_header;
    }
    if(lookup_symbol(cur_header, id.string) == -1){
        Entry *temp = malloc(sizeof(Entry));
        temp->index = header->entry_num++;
        temp->name = id.string;
        temp->kind = kind;
        temp->type = type.string;
        temp->scope = header->depth;
        temp->next = NULL;
        if(!strcmp(kind,"function")){
            char* attr = add_attribute(cur_header);
            temp->attribute = attr;
        }
        header->table_tail->next = temp;
        header->table_tail = header->table_tail->next;
        if(!strcmp(kind,"variable")){
            do_declaration_stat(temp->index, type, id, R_val);
        }
        else if(!strcmp(kind, "function")){ 
            do_function_definition(temp);
        }
        // printf("%-10d%-10s%-12s%-10s%-10d%-10s\n", temp->index, temp->id, temp->kind, temp->type, temp->scope, temp->attribute);
    } 
    else{
        redeclared_check(id.string, kind);
    }
}
char* add_attribute(Header *header){
    int n = 0;
    Entry *cur = header->table_root->next;
    char* temp = malloc(50);
    while(cur != NULL){
        if(!strcmp(cur->kind,"parameter")){
            if(n == 0){
                n++;
                //strcpy(temp,cur->type);
            }
            else{
                //strcat(temp,",");
                strcat(temp,cur->type);
            }
        }
        cur = cur->next;
    }
    return temp;
}

int lookup_symbol(Header *header, char* id) { 
    // return index 0~n :redeclared
    // return -1, undeclared
    if(header->table_root == NULL){
        return -1;
    }
    Entry *cur = header->table_root->next;
    while(cur != NULL){
        if(!strcmp(cur->name,id))
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
    Entry *cur_entry = cur_header->table_root->next;
    while(cur_entry != NULL) {
        if(cur_entry->attribute != NULL) {
            printf("%-10d%-10s%-12s%-10s%-10d%s\n", cur_entry->index, cur_entry->name, cur_entry->kind, cur_entry->type, cur_entry->scope, cur_entry->attribute);
        }
        else {
            printf("%-10d%-10s%-12s%-10s%-10d\n", cur_entry->index, cur_entry->name, cur_entry->kind, cur_entry->type, cur_entry->scope);
        }
        Entry *temp = cur_entry;
        cur_entry = cur_entry->next;
        free(temp);
        temp = NULL;
    }
    printf("\n");
    cur_header->entry_num = 0;
    Header* tmp = cur_header;
    cur_header = cur_header->pre;
    free(tmp);
    tmp = NULL;
    depth = depth -1;
}

void free_symbol_table(){

}

void undeclared_check(char* name, char* kind){
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
            if(!strcmp(kind, "function")){
                error_msg[NumberOfError] = malloc(200);
                sprintf(error_msg[NumberOfError++],"Undeclared function %s", name);
                semantic_error = 1;
            } else if(!strcmp(kind, "variable")){
                error_msg[NumberOfError] = malloc(200);
                sprintf(error_msg[NumberOfError++],"Undeclared variable %s", name);
                semantic_error = 1;
            }
        }
}
void redeclared_check(char* name, char* kind){
    //printf("%s\n",type);
    if(!strcmp(kind, "function")){
        sprintf(error_msg[NumberOfError++],"Redeclared function %s", name);
        semantic_error = 1;
    } else if(!strcmp(kind, "variable")){
        sprintf(error_msg[NumberOfError++],"Redeclared variable %s", name);
        semantic_error = 1;
    }
}

/* code generation functions */
void gencode(char *s) {
    fprintf(file, "%s", s);
}
void do_declaration_stat(int index, Value type, Value id, Value R_val){
    int global;
    if(cur_header->depth == 0) global = 1;
    char* asm_type = convert_type(type.type);
    int R_int;
    float R_float;
    char* R_string;
    bool R_bool;
    if(index == -1){
        debug("not found declaration");
    }
    /////////////////////////////
    if(R_val.type != NAT){ //with initial
        if(type.type == INT_T){
                if(R_val.type ==INT_T)
                    R_int = R_val.i_val; 
                else{
                    R_int = (int)R_val.f_val;
                }
        }
        else if(type.type == FLOAT_T){
            if(R_val.type ==INT_T)
                R_float = (float)R_val.i_val;
            else{
                R_float = R_val.f_val;
            }
        }
        else if(type.type == BOOL_T){
            R_bool = R_val.i_val;
        }
    }
    else{ //not initial
        R_int = 0;
        R_float = (float)0.0;
        R_string = "";
        R_bool = 0;
    }
    /////////////////////////////
    if(global){
        switch (type.type){
            case INT_T:
                sprintf(code_buf,".field public static %s %s = %d\n",id.string, asm_type, R_int); 
                gencode(code_buf);
                break;
            case FLOAT_T:
                sprintf(code_buf,".field public static %s %s = %f\n",id.string, asm_type, R_float);
                gencode(code_buf); 
                break;
            case STRING_T:
                sprintf(code_buf,".field public static %s %s = \"%s\"\n",id.string, asm_type, R_string);
                gencode(code_buf); 
                break;
            case BOOL_T:
                sprintf(code_buf,".field public static %s %s = \"%d\"\n",id.string, asm_type, R_bool);
                gencode(code_buf); 
                break;
            default:
                printf("%d\n",type.type);
                debug("variable type is not int,float,string,bool. line 455");
                break;
        }
    }
    else{ 
        switch (type.type){
            case INT_T:
                sprintf(code_buf,"\tldc %d\n\tistore %d\n", R_int, index);
                gencode(code_buf); 
                break;
            case FLOAT_T:
                sprintf(code_buf,"\tldc %f\n\tfstore %i\n", R_float, index); 
                gencode(code_buf);
                break;
            case STRING_T:
                sprintf(code_buf,"\tldc \"%s\"\n\tastore %i\n", R_string, index);
                gencode(code_buf); 
                break;
            case BOOL_T:
                sprintf(code_buf,"\tldc %i\n\tistore %i\n", R_bool, index);
                gencode(code_buf); 
                break;
            default:
                printf("%s,%d\n",id.string,type.type);
                debug("variable type is not int,float,string,bool. line 475");
        }

    }
}
void debug(char* s){
    printf("%s\n",s);
}
char* convert_type(Type type){
    switch (type){
        case INT_T:
            return "I";
            break;
        case FLOAT_T:
            return "F";
            break;
        case STRING_T:
            return "Ljava/lang/String;";
            break;
        case BOOL_T:
            return "Z";
            break;
        case VOID_T:
            return "V";
            break;
        default :
            debug("type is not I, F, STRING, Z, V");
            break;
    }
}
void do_function_definition(Entry* temp){
    char* parameter = str_replace(temp->attribute,",","");
    parameter = str_replace(parameter,"int","I");
    parameter = str_replace(parameter,"float","F");
    parameter = str_replace(parameter,"bool", "Z");
    parameter = str_replace(parameter,"string","Ljava/lang/String;");
    char* return_type = str_replace(temp->type,"int","I");
    return_type = str_replace(return_type,"float","F");
    return_type = str_replace(return_type,"bool", "Z");
    return_type = str_replace(return_type,"void", "V");
    return_type = str_replace(return_type,"string","Ljava/lang/String;");
    sprintf(code_buf,".method public static %s(%s)%s\n", temp->name,parameter,return_type);
    gencode(code_buf);
    sprintf(code_buf,".limit stack 50\n");
    gencode(code_buf);
    sprintf(code_buf,".limit locals 50\n");
    gencode(code_buf);
}
char* str_replace(char* string, const char* substr, const char* replacement) {
	char* tok = NULL;
	char* newstr = NULL;
	char* oldstr = NULL;
	int   oldstr_len = 0;
	int   substr_len = 0;
	int   replacement_len = 0;

	newstr = strdup(string);
	substr_len = strlen(substr);
	replacement_len = strlen(replacement);

	if (substr == NULL || replacement == NULL) {
		return newstr;
	}

	while ((tok = strstr(newstr, substr))) {
		oldstr = newstr;
		oldstr_len = strlen(oldstr);
		newstr = (char*)malloc(sizeof(char) * (oldstr_len - substr_len + replacement_len + 1));

		if (newstr == NULL) {
			free(oldstr);
			return NULL;
		}

		memcpy(newstr, oldstr, tok - oldstr);
		memcpy(newstr + (tok - oldstr), replacement, replacement_len);
		memcpy(newstr + (tok - oldstr) + replacement_len, tok + substr_len, oldstr_len - substr_len - (tok - oldstr));
		memset(newstr + oldstr_len - substr_len + replacement_len, 0, 1);

		free(oldstr);
	}
	return newstr;
}
