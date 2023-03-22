#ifndef COMPLEX1_H
#define COMPLEX1_H

class Complex {
public:
   Complex( double = 0.0, double = 0.0 );       // konstruktor
   Complex operator+( const Complex & ) const;  // sobiranje
   Complex operator-( const Complex & ) const;  // odzemanje
   Complex operator*( const Complex &) const;//mnozenje dva kompleksni broevi
   Complex operator*( const int ) const;//mnoenje kompleksen so cel broj
   Complex operator*( const int, const Complex &) const;
   const Complex &operator=( const Complex & ); // dodeluvanje
   bool Complex operator==( const Complex & ) const;
   bool Complex operator!=( const Complex & ) const;
   Complex operator*=( const Complex &) const;
   Complex operator+=( const Complex &) const;
   Complex operator-=( const Complex &) const;

   friend ostream &operator<<( ostream&, const Complex & );                         // izlez
private:
   double real;       // realen del
   double imaginary;  // imaginaren del
}; // kraj na klasta Complex

#endif
 

// complex1.cpp
// Definicii na funkciite chlenki na klasata Complex
#include <iostream>

using std::cout;

#include "complex1.h"

// Konstruktor
Complex::Complex( double r, double i ) 
   : real( r ), imaginary( i ) { }

// Preklopi operator za sobiranje
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
                   imaginary + operand2.imaginary );
} // kraj na funkcijata operator+ 

// Preklopi operator za odzemanje
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
                   imaginary - operand2.imaginary );
} // kraj na funkcijata operator- 
//mnozenje na dva kompleksni broevi
Complex operator*( const Complex &operand2 ) const
{
   return Complex( real * operand2.real - imaginary * operand2.imaginary, 
                   real * operand2.imaginary + imaginary * operand2.real );
}//kraj
//mnozenje kompleksen so cel broj
Complex operator*( const int operand2 ) const
{
   return Complex( real * operand2, imaginary * operand2 );
}
//kraj
//mnozenje cel so kompleksen

// Mnozenje cel broj so kompleksen broj
Complex operator*( const int operand1, const Complex &operand2 ) const
{
   return Complex( operand1 * operand2.real, operand1 * operand2.imaginary );
}


// Preklopi operator = 
const Complex& Complex::operator=( const Complex &right )
{
   real = right.real;
   imaginary = right.imaginary;
   return *this;   // ovozmozhuva kaskadiranje
} // ekraj na funkcijata operator= 
// Preklopi operator ==
bool Complex::operator==( const Complex &right ) const
{
return (real == right.real) && (imaginary == right.imaginary);
}

// Preklopi operator !=
bool Complex::operator!=( const Complex &right ) const
{
return !(*this == right);
}
// Ispechati objekt od klasa Complex vo oblik: (a, b)

ostream &operator<<( ostream &output, const Complex &num )
{
   output << num.real << "." << num.imaginary;
   return output;     
} // kraj na oprator<< funkcijata
// Preklopi operator za += 
Complex& Complex::operator+=(const Complex& operand2)
{
   real += operand2.real;
   imaginary += operand2.imaginary;
   return *this;
}

// Preklopi operator za -=
Complex& Complex::operator-=(const Complex& operand2)
{
   real -= operand2.real;
   imaginary -= operand2.imaginary;
   return *this;
}

// Preklopi operator za *=
Complex& Complex::operator*=(const Complex& operand2)
{
   Complex temp(*this);
   real = temp.real * operand2.real - temp.imaginary * operand2.imaginary;
   imaginary = temp.real * operand2.imaginary + temp.imaginary * operand2.real;
   return *this;
}


// p08_06.cpp
// Drajver za klasata Complex
#include <iostream>

using std::cout;
using std::endl;

#include "complex1.h"

int main()
{
   Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );

   cout << "x: ";
   cout<<x;
   cout << "\ny: ";
   cout<<y;
   cout << "\nz: ";
   cout<<z;

   x = y + z;
   cout << "\n\nx = y + z:\n";
   cout<<x;
   cout << " = ";
   cout<<y;
   cout << " + ";
   cout<<z;

   x = y - z;
   cout << "\n\nx = y - z:\n";
   cout<<x;
   cout << " = ";
  cout<<y;
   cout << " - ";
   cout<<z;
   cout << endl;

   return 0;
} // kraj main


