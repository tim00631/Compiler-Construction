/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>

	int line_num = 0;
	int comment_num = 0;
	int last_comment_line = -1;

%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
IntNumber {digit}+
FloatNumber ({digit}*\.{digit}+)
WhiteSpace [ \t]+
%x COMMENT
%x STR

/* Rules section */
%%

"+" 	{ printf("%s \t ADD\n", yytext); }
"-"		{ printf("%s \t SUB\n", yytext); }
"*"		{ printf("%s \t MUL\n", yytext); }
"/"		{ printf("%s \t DIV\n", yytext); }
"%"		{ printf("%s \t MOD\n", yytext); }
"++"	{ printf("%s \t INC\n", yytext); }
"--"	{ printf("%s \t DEC\n", yytext); }
">"		{ printf("%s \t MT\n", yytext); }
"<"		{ printf("%s \t LT\n", yytext); }
">="	{ printf("%s \t MTE\n", yytext); }
"<="	{ printf("%s \t LTE\n", yytext); }
"=="	{ printf("%s \t EQ\n", yytext); }
"!="	{ printf("%s \t NE\n", yytext); }
"["		{ printf("%s \t LSB\n", yytext); }
"]"		{ printf("%s \t RSB\n", yytext); }
","		{ printf("%s \t COMMA\n", yytext); }
";"		{ printf("%s \t SEMICOLON\n", yytext); }
"\""        { BEGIN(STR);
                printf("%s \t QUOTA \n", yytext);
            }
<STR>"\\\"" { printf("%s \t STR_CONST \n", yytext); }
<STR>[^\"]* { printf("%s \t STR_CONST \n", yytext); }
<STR>"\""   { BEGIN(INITIAL);
                printf("%s \t QUOTA \n", yytext);
            }
"print"		{ printf("%s \t PRINT\n", yytext); }
"if"		{ printf("%s \t IF\n", yytext); }
"else"		{ printf("%s \t ELSE\n", yytext); }
"for"		{ printf("%s \t FOR\n", yytext); }
"while"		{ printf("%s \t WHILE\n", yytext); }
"string"	{ printf("%s \t STRING\n", yytext); }
"int"		{ printf("%s \t INT\n", yytext); }
"float"		{ printf("%s \t FLOAT\n", yytext); }
"="		{ printf("%s \t ASGN\n", yytext); }
"+="	{ printf("%s \t ADDASGN\n", yytext); }
"-="	{ printf("%s \t SUBASGN\n", yytext); }
"*="	{ printf("%s \t MULASGN\n", yytext); }
"/="	{ printf("%s \t DIVASGN\n", yytext); }
"%="	{ printf("%s \t MODASGN\n", yytext); }
"&&"	{ printf("%s \t AND\n", yytext); }
"||"	{ printf("%s \t OR\n", yytext); }
"!"		{ printf("%s \t NOT\n", yytext); }
"("		{ printf("%s \t LB\n", yytext); }
")"		{ printf("%s \t RB\n", yytext); }
"{"		{ printf("%s \t LCB\n", yytext); }
"}"		{ printf("%s \t RCB\n", yytext); }
"void"		{ printf("%s \t VOID\n", yytext); }
"bool"		{ printf("%s \t BOOL\n", yytext); }
"true"		{ printf("%s \t TRUE\n", yytext); }
"false"		{ printf("%s \t FALSE\n", yytext); }
"return"	{ printf("%s \t RET\n", yytext); }
"continue"	{ printf("%s \t CONT\n", yytext); }
"break"		{ printf("%s \t BREAK\n", yytext); }
{IntNumber} { printf("%s \t I_CONST\n", yytext); }
{FloatNumber} { printf("%s \t F_CONST\n", yytext); }
{id}	{ printf("%s \t ID\n", yytext); }

"//".*      { comment_num++;
                printf("%s \t C++ Comment \n",  yytext);
            }
"/*"        { BEGIN(COMMENT);
				if (line_num != last_comment_line) {
                    comment_num++;
                }
                printf("%s", yytext);
            }
<COMMENT>.      { printf("%s", yytext);}
<COMMENT>"*/"   { BEGIN(INITIAL);
					last_comment_line = line_num;
					printf("%s \t C Comment \n", yytext);
            	}
<COMMENT>\n     { printf("%s", yytext);
					line_num++; comment_num++;
				}

\n		{line_num++;}
.		{;}
{WhiteSpace}	{;}
%%

/*	C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\nParse over, the line number is %d.\n\n", line_num);
	printf("comment: %d lines\n\n", comment_num);

	return 0;
}
