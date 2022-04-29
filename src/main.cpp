#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Prostopadloscian.hh"
#include "gnuplot.hh"
#include "interface.hh"

using namespace std;

int main()
  {
    double kat = 0;
    double h = 8;
    Wektor<3> W, Wp1{-6,4,2},Wp2{6,4,2},Wp3{6,-4,2},Wp4{-6,-4,2};
    Prostopadloscian P(Wp1,Wp2,Wp3,Wp4,h);
    char wybor;
    char os = 'Z';
    int i=0;
    int warunek_wyjscia = 1;
    drawNS::Draw3DAPI * api = new drawNS::APIGnuPlot3D(-20,20,-20,20,-20,20,1000);
    api->change_ref_time_ms(0);
    system("clear");
    i = P.rysuj(api,i);
    cout << endl;
    while (warunek_wyjscia)
      { 
         cout << "MENU:" << endl;
         cout << "o - obrot prostopadloscianu o zadany kat" << endl;
         cout << "t - powtorzenie poprzedniego obrotu" << endl;
         cout << "r - wyswietlenie macierzy rotacji" << endl;
         cout << "s - sprawdzenie dlugosci przeciwleglych bokow" << endl;
         cout << "p - przesuniecie prostokata o zadany wektor" << endl;
         cout << "w - wyswietlenie wspolrzednych wierzcholkow" << endl;
         cout << "k - koniec dzialania programu" << endl;
         cin >> wybor;
         system("clear");
         switch (wybor)
           {
             case 'o':
               {
                 cout << "Podaj kat o jaki chcesz obrocic prostokat (w stopniach):" << endl;
                 cin >> kat;
                 cout << "Podaj os obrotu (X,Y lub Z)" << endl;
                 cin >> os;
                 P = P.rotacja(kat, os);
                 i = P.rysuj(api,i);
                 cout << endl;
                 break;
               }
             case 't':
               {
                 P = P.rotacja(kat, os);
                 i = P.rysuj(api,i);
                 break;
               }
             case 'r':
               {
                 Macierz<3> M(kat, os);
                 cout << M << endl;
                 break;
               }
             case 's':
               {
                 P.podsumowanie_bledu();
                 break;
               }
             case 'p':
               {
                 cout << "Podaj wektor o jaki chcesz przesunac prostokat (forma zapisu: [a,b,c]):" << endl;
                 cin >> W;
                 P = P.translacja(W);
                 i = P.rysuj(api,i);
                 cout << endl;
                 break;
               }
             case 'w':
               {
                 cout << P << endl << endl;
                 break;
               }
             case 'k':
               {
                 warunek_wyjscia = 0;
                 break;
               }
             default:
               {
                 cout << "Blednie wybrana opcja" << endl << endl;
                 break;
               }
           }
      }
     delete api;
  }

