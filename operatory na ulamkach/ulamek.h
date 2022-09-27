class Ulamek{
  private:
  int l;
  int m;
  public:
  Ulamek();
  Ulamek(int, int);
  Ulamek(int);
  Ulamek(Ulamek, Ulamek);
  void print();

  Ulamek operator+ (Ulamek &);
  Ulamek operator- (Ulamek &);
  Ulamek operator* (Ulamek &);
  Ulamek operator/ (Ulamek &);
  
  Ulamek operator+ (const int &) const; 
  Ulamek operator- (const int &) const;
  Ulamek operator* (const int &) const ;
  Ulamek operator/ (const int &) const;

  bool operator== (Ulamek) const; 
  bool operator!= (Ulamek) const; 
  bool operator<= (Ulamek) const;  
  bool operator>= (Ulamek) const;
  bool operator< (Ulamek) const;
  bool operator> (Ulamek) const;  
  
  operator double () const;
  operator string () const;
};