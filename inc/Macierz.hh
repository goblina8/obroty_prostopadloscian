#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <iostream>
#include <vector>
#include "interface.hh"
#include "Wektor.hh"

using namespace std;

template <int ROZMIAR>  
class Macierz
{
  private:
    vector<Wektor<ROZMIAR>> wiersze;
  public:
    Macierz<ROZMIAR>(){Wektor<ROZMIAR> W; for (int i = 0; i < ROZMIAR; i++) {wiersze.push_back(W);};};
    explicit Macierz<ROZMIAR>(double kat, char os); 
    explicit Macierz<ROZMIAR>(double kat); 
    double wyznacznik() const;
    Wektor<ROZMIAR> operator * (const Wektor<ROZMIAR> & W) const;
    Macierz operator * (const Macierz<ROZMIAR> & M2) const; //set
    const Wektor<ROZMIAR> & operator [] (int i) const; //get
    Wektor<ROZMIAR> operator [] (int i); 
};

template <int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Macierz<ROZMIAR> &M);

#endif
