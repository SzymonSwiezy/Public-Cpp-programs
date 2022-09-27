#include <iostream>
using namespace std;
#include "ulamek.h"

int main() {
  Ulamek u1(1,5), u2(1,2), u3(3), u4(1,4), u5(2,5), z, e;
  Ulamek u6(u1, u2);
  bool y;
  u6.print();
  u1.print();
  u2.print();
  cout << "\n\noperacje na ulamkach" << endl; 
  z = u1+u2; z.print();
  z = u1-u2; z.print();
  z = u1*u2; z.print();
  z = u1/u2; z.print();

  cout << "\n\noperacje cal/ulamek" << endl; 
  e = u2+2; e.print();
  e = u2-2; e.print();
  e = u2*2; e.print();
  e = u2/2; e.print();

  cout << "\n\nBOOL" << endl; 
  y = u1!=u2; cout << y << endl;
  y = u1==u2; cout << y << endl;
  y = u1<u2; cout << y << endl;
  y = u1<=u2; cout << y << endl;
  y = u1>u2; cout << y << endl;
  y = u1>=u2; cout << y << endl;

  cout << "\n\ntypy" << endl; 
  cout << (double)u1 << endl;
  cout << (string)u1 << endl;
  cout << (double)u1 << endl;
}