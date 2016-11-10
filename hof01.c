// hof01.c  A simple illustration of "higher order functions" in C
// that is, functions that take other functions as parameters

#include <stdio.h>

// doNTimes takes an integer n, and f, which is a 
//   a pointer to a function that takes void as argument, and returns void. 
void doNTimes(int n, void (*f)(void)) 
{
  int i;
  for (i=0; i<n; i++) 
    (*f)(); // call the function
}

void sayHello(void) {
  printf("Hello World\n");
}

void printStar(void) {
  printf("*");
}

void printEndl(void) {
  printf("\n");
}

int main() 
{
  doNTimes(3,sayHello); // vs: for(i=0;i<3;i++) { sayHello(); }

  doNTimes(4,printStar); // vs: for(i=0;i<4;i++) { printStar(); }
 
  doNTimes(2,printEndl); // vs: for (i=0;i<2;i++) printEndl();
  return 0;
}
