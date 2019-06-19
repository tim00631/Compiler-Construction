int foo(int a) {
   a += 6;
   return a;
}

void lol(int a) {
    print(a);
	return;
}

void main(){
   int a = foo(4);
   lol(a);
   return;
}
