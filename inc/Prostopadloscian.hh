#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include <vector>
#include "interface.hh"
#include "gnuplot.hh"
#include "Wektor.hh"
#include "Macierz.hh"

class Prostopadloscian
{
  private:
    Wektor<3> p1; //wspolrzedne dolnego prostokata
    Wektor<3> p2;
    Wektor<3> p3;
    Wektor<3> p4;
    double h;     //wysokosc prostopadloscianu
  public:
    Prostopadloscian rotacja(double kat, char os) const; 
    Prostopadloscian translacja(Wektor<3> W) const;
    Prostopadloscian(Wektor<3> W1, Wektor<3> W2, Wektor<3> W3, Wektor<3> W4, double H); //set
    const Wektor<3> & operator [] (int i) const; //get
    int rysuj(drawNS::Draw3DAPI * api, int i) const;
    void podsumowanie_bledu() const;
};

std::ostream& operator << (std::ostream &strm, const Prostopadloscian &P);

#endif
