// hof05.cpp  A simple illustration of "higher order functions" in C++

// MUST BE COMPILED WITH -std=c++0x

#include <iostream>
using namespace std;

// repeatNTimes takes an integer n, and f, which is a 
//   a pointer to a function that takes void as argument, and returns void. 

int summarizeArray(int n, int *a, int partial, int (*f)(int, int *, int)) 
{
  if (n<=0) 
    return partial;
  else {
    int nextPartial = (*f)(n,a,partial);
    return summarizeArray(n-1,a+1,nextPartial,f);
  }

  // COULD BE WRITTEN:
  //return (n <=0) ?
  //    partial :
  //   summarizeIntArray(n-1, a+1, (*f)(n,a,partial), f);    
}

int min(int a, int b) {
  return (a<b)? a : b;
}

// return the smaller of a[0] and partial
int minHelper(int n, int *a, int partial) {
  return min(a[0], partial);
}

int minArray(int n, int *a) {
  return summarizeArray(n, a, a[0],minHelper);
}



int sumHelper(int n, int *a, int partial) {
  return (a[0]+partial);
}

int sumArray(int n, int *a) {
  return summarizeArray(n, a, 0, sumHelper);
}


int printHelper(int n, int *a, int partial) {
  cout << "a[" << partial << "]=" << a[0] << endl;
  return partial+1;
}

int printArray(int n, int *a) {
  return summarizeArray(n, a, 0, printHelper);
}

int main() 
{
  int nums[] = {50,20,10,40};
  
  printArray(4, nums);
  
  cout << "min=" << minArray(4,nums) << endl;
  cout << "sum=" << sumArray(4,nums) << endl;

  return 0;
}
