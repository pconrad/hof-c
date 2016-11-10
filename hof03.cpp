// hof01.cpp  A simple illustration of "higher order functions" in C++

// MUST BE COMPILED WITH -std=c++0x

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

int main() 
{
  doNTimes(3,sayHello); // vs: for(int i=0;i<3;i++) { sayHello(); }
 
  auto twoStars = [] () { doNTimes(2,printStar); };
  // equivalent to:
  //    void twoStars(void) {
  //        doNTimes(2,printStar);
  //    }

  doNTimes(4,twoStars); 
  // instead of: 
  // for(int i=0;i<4;i++) 
  //   for (j=0; j<=2; j++) 
  //       printStar();
  
  doNTimes(4, []() { doNTimes(3,printStar); printEndl();});
 
  // instead of: 
  // for(int i=0;i<4;i++) 
  //   for (j=0; j<=3; j++) 
  //      { printStar(); printEndl(); } 


  doNTimes(2,printEndl); // vs: for (int i=0;i<2;i++) printEndl();
  return 0;
}
