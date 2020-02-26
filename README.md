# 107_2 Compiler Construction

### This repository is for 2019 Compiler Course in NCKU CSIE
### a compiler that can compile micro-C language to JVM instructions

## HW1-Lex-Scanner
* A scanner for the μC language
### Usage
```=shell

$ make
$ ./myscanner input/print.c 
print 	 PRINT
( 	 LB
" 	 QUOTA
Hello World 	 STR_CONST
" 	 QUOTA
) 	 RB
; 	 SEMICOLON

Parse over, the line number is 1.

comment: 0 lines

```
