#include <iostream>
#include <string>
using namespace std;
#include "ulamek.h"

Ulamek::Ulamek(){};

Ulamek::Ulamek(int a, int b){
    l = a;
    m = b;
    while(b) swap(a %= b, b);
    l /= a;
    m /= a;
  }
  
Ulamek::Ulamek(int a) : l(a), m(1){}

Ulamek::Ulamek(Ulamek x, Ulamek y){
    int a = x.m*y.l +y.m*x.l , b = x.m*y.m;
    l = a;
    m = b;
    while(b) swap(a %= b, b);
    l /= a;
    m /= a;
  }
/////////////////DZIAlANIA/////////////////
Ulamek  Ulamek::operator+ (Ulamek &obj){
    return Ulamek(l*obj.m+obj.l*m, m*obj.m);
  }

Ulamek  Ulamek::operator- (Ulamek &obj){
    return Ulamek(l*obj.m+obj.l*m, m*obj.m);;
  }  
Ulamek  Ulamek::operator* (Ulamek &obj){
    return Ulamek(l*obj.l, m*obj.m);
  }  

Ulamek  Ulamek::operator/ (Ulamek &obj){
      return Ulamek(l*obj.m, m*obj.l);
  }   

  Ulamek  Ulamek::operator+ (const int &a ) const{   
    return Ulamek(l+m*a, m);
  }

  Ulamek  Ulamek::operator- (const int &a ) const{   
    return Ulamek(l-m*a, m);
  }
  Ulamek  Ulamek::operator* (const int &a ) const{   
    return Ulamek(l*a, m);
  }

  Ulamek  Ulamek::operator/ (const int &a ) const{   
    return Ulamek(l, m*a);
  } 

//////////////////BOOL////////////////////
  bool Ulamek::operator!= (const Ulamek a)const{
    if((l != a.l) || ((m != a.m))) return true;
    else return false;
  } 
  bool Ulamek::operator== (const Ulamek a)const{
    if((l == a.l) && ((m == a.m))) return true;
    else return false;
  } 

  bool Ulamek::operator> (const Ulamek a)const{
    if(((l < a.l) && (m <= a.m)) || ((l <= a.l) && ((m < a.m)))) return true;
    else return false;
  }

  bool Ulamek::operator>= (const Ulamek a)const{
    if(((l <= a.l) && (m <= a.m))) return true;
    else return false;
  } 

  bool Ulamek::operator< (const Ulamek a)const{
    if(((l > a.l) && (m >= a.m)) || ((l >= a.l) && ((m > a.m)))) return true;
    else return false;
  }

  bool Ulamek::operator<= (const Ulamek a)const{
    if(((l >= a.l) && (m >= a.m))) return true;
    else return false;
  } 

//////////////////ZMIANA TYPU////////////////////////
Ulamek::operator double() const{
  return (static_cast<double>(l) / static_cast<double>(m));;
  }

Ulamek::operator string ()  const{
		return to_string(l) + "/" + to_string(m);
	}
  
void Ulamek::print(){
  if(l != m ) cout << l << "/" << m << endl;
  else if( (l == m) || (m == 1)) cout << l << endl;
}