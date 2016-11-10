// hof01.cpp  A simple illustration of "higher order functions" in C++

#include <iostream>
using namespace std;

// repeatNTimes takes an integer n, and f, which is a 
//   a pointer to a function that takes void as argument, and returns void. 
void doNTimes(int n, void (*f)(void)) 
{
  for (int i=0; i<n; i++) 
    (*f)(); // call the function
}

void sayHello(void) {
  cout << "Hello World" << endl;
}

void printStar(void) {
  cout << "*";
}

void printEndl(void) {
  cout << endl;
}

void printTwoStarsAndEndl(void) {
  doNTimes(2,printStar);
  printEndl();
}

int main() 
{
  doNTimes(3,sayHello); // vs: for(int i=0;i<3;i++) { sayHello(); }
 
  doNTimes(4,printTwoStarsAndEndl); 
  // instead of: 
  // for(int i=0;i<4;i++) 
  //   for (j=0; j<=2; j++) 
  //       printStar();
  
  doNTimes(2,printEndl); // vs: for (int i=0;i<2;i++) printEndl();
  return 0;
}
