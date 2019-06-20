.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1
	istore 0
LABEL_BEGIN_0:
	iload 0
	ldc 6
	isub
	iflt LABEL_TRUE_0
	goto LABEL_FALSE_0
LABEL_TRUE_0:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	iload 0
	ldc 1
	iadd
	istore 0
	pop
	goto LABEL_BEGIN_0
LABEL_FALSE_0:
	goto EXIT_0
EXIT_0:
	return
.end method
