# Micro C Compiler Construction

* This repository is for 2019 Compiler Course in NCKU CSIE
* a compiler that can compile micro-C language to JVM instructions

## Usage
#### 1. Compile 
```bash
$ make 
```

#### 2.Execute this Compiler, spawn a java file
```bash
$ ./myparser < test.c 
```
This step will produce a file named ```comiler_hw3.j```
#### 3.Convert your file to Java class 
```bash
$ java -jar jasmin.jar compiler_hw3.j
```
And this step will produce a file named```compiler_hw3.class``` 
#### 4. Execute on J.V.M (Java Virtual Machine)
```bash
$ java compiler_hw3
```

