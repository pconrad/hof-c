// hof01.cpp  A simple illustration of "higher order functions" in C++

// MUST BE COMPILED WITH -std=c++0x

#include <iostream>
using namespace std;

// repeatNTimes takes an integer n, and f, which is a 
//   a pointer to a function that takes void as argument, and returns void. 

void doNTimes(int n, void (*f)(void)) 
{
  if (n<=0) 
    return;
  else {
    (*f)();
    doNTimes(n-1,f);
  }
}

int main() 
{
  // instead of: 
  //   for (int i=0;i<3;i++)
  //     cout << "Hello" << endl;

  doNTimes(3, [](){ cout << "Hello" << endl;} );

  // instead of: 
  // for(int i=0;i<4;i++) 
  // {
  //   for (j=0; j<=2; j++) 
  //       cout << "*";
  //   cout << endl;
  // }
  doNTimes(4, [](){ 
      doNTimes(2, []() {cout << "*";} );
      cout << endl;
    });

  return 0;
}
