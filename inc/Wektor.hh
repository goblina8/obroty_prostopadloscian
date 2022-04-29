#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "interface.hh"
#include "gnuplot.hh"
#include <vector>
#include <iostream>
#include <initializer_list>

using namespace std; 

template <int ROZMIAR>
class Wektor 
{
  private:
    vector<double> xy;
  public:
    Wektor<ROZMIAR> () {for (int i = 0; i < ROZMIAR; i++) {xy.push_back(0.0);}}
    Wektor<ROZMIAR> (std::initializer_list<double> il): xy(il) {};
    Wektor<ROZMIAR> operator + (const Wektor<ROZMIAR> & W2) const;
    Wektor<ROZMIAR> operator - (const Wektor<ROZMIAR> & W2) const;
    Wektor<ROZMIAR> operator * (const double & d) const;
    Wektor<ROZMIAR> operator / (const double & d) const;
    const double & operator [] (int i) const; 
    double operator * (const Wektor<ROZMIAR> & W2) const; 
    double & operator [] (int i); 
    double dlugosc() const; 
};

template <int ROZMIAR>
std::istream& operator >> (std::istream &strm, Wektor<ROZMIAR> &W);

template <int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Wektor<ROZMIAR> &W);

drawNS::Point3D konwertuj(Wektor<3> W);

#endif
