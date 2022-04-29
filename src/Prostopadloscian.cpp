#include "Prostopadloscian.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "gnuplot.hh"
#include "interface.hh"
#include <iostream>
#include <cmath>

using namespace std;

  int Prostopadloscian:: rysuj(drawNS::Draw3DAPI * rysownik, int i) const
    {
      drawNS::Point3D P1(0,0,0), P2(0,0,0), P3(0,0,0), P4(0,0,0), P5(0,0,0), P6(0,0,0), P7(0,0,0), P8(0,0,0);
      P1=konwertuj(this->p1);
      P2=konwertuj(this->p2);
      P3=konwertuj(this->p3);
      P4=konwertuj(this->p4);
      P5=konwertuj((*this)[4]);
      P6=konwertuj((*this)[5]);
      P7=konwertuj((*this)[6]);
      P8=konwertuj((*this)[7]);
      std::vector<drawNS::Point3D> dane;
      dane.push_back(P1);
      dane.push_back(P2);
      dane.push_back(P3);
      dane.push_back(P4);
      dane.push_back(P1);
      dane.push_back(P5);
      dane.push_back(P6);
      dane.push_back(P2);
      dane.push_back(P6);
      dane.push_back(P7);
      dane.push_back(P3);
      dane.push_back(P7);
      dane.push_back(P8);
      dane.push_back(P4);
      dane.push_back(P8);
      dane.push_back(P5);  
      rysownik->draw_polygonal_chain(dane, "blue");
      
    }

  void Prostopadloscian:: podsumowanie_bledu() const
    {
      double epsilon = 0.000001;
      Wektor<3> W1, W2, W3, W4, W5, W6, W7, W8, W9, W10, W11, W12;
      W1 = (this)->p2 - (this)->p1;
      W2 = (this)->p3 - (this)->p2;
      W3 = (this)->p4 - (this)->p3;
      W4 = (this)->p1 - (this)->p4;
      W5 = (*this)[5] - (*this)[4];
      W6 = (*this)[6] - (*this)[5];
      W7 = (*this)[7] - (*this)[6];
      W8 = (*this)[4] - (*this)[7];
      W9 = (*this)[4] - (this)->p1;
      W10 = (*this)[5] - (this)->p2;
      W11 = (*this)[6] - (this)->p3;
      W12 = (*this)[7] - (this)->p4;
      cout << W1 << "," << W2 << "," << W3 << "," << W4 << endl;
      cout << W5 << "," << W6 << "," << W7 << "," << W8 << endl;
      cout << W9 << "," << W10 << "," << W11 << "," << W12 << endl;
      //DLUGOSCI BOKOW
      if ((W1.dlugosc() == W3.dlugosc()) && (W5.dlugosc() == W7.dlugosc()) && (W1.dlugosc() == W7.dlugosc()))  
        {
          cout << "Boki p1p2, p3p4, p5p6 i p7p8 sa sobie rowne" << endl;
        }
      else
          {
            cout << "Boki p1p2, p3p4, p5p6 i p7p8 nie sa sobie rowne" << endl;
          }
      if ((W2.dlugosc() - W4.dlugosc() <= epsilon) && (W6.dlugosc() - W8.dlugosc() <= epsilon) && (W6.dlugosc() - W2.dlugosc() <= epsilon))  
        {
          cout << "Boki p2p3, p4p1, p7p6 i p8p5 sa sobie rowne" << endl;
        }
      else
          {
            cout << "Boki p2p3, p4p1, p7p6 i p8p5 nie sa sobie rowne" << endl;
          }
      if ((W9.dlugosc() - W10.dlugosc() <= epsilon) && (W12.dlugosc() - W11.dlugosc() <= epsilon) && (W12.dlugosc() - W9.dlugosc() <= epsilon))  
        {
          cout << "Boki p1p5, p2p6, p3p7 i p4p8 sa sobie rowne" << endl;
        }
      else
          {
            cout << "p1p5, p2p6, p3p7 i p4p8 nie sa sobie rowne" << endl;
          }
    }
  
  Prostopadloscian Prostopadloscian:: rotacja(double kat, char os) const 
    {
      Macierz<3> M(kat, os);
      cout << M << endl;
      Prostopadloscian P(M*this->p1, M*this->p2, M*this->p3, M*this->p4, this->h);
      return P;
    }
    
  Prostopadloscian Prostopadloscian:: translacja(Wektor<3> W) const
    {
      Wektor<3> Wp1{this->p1[0]+W[0], this->p1[1]+W[1], this->p1[2]+W[2]};
      Wektor<3> Wp2{this->p2[0]+W[0], this->p2[1]+W[1], this->p2[2]+W[2]};
      Wektor<3> Wp3{this->p3[0]+W[0], this->p3[1]+W[1], this->p3[2]+W[2]};
      Wektor<3> Wp4{this->p4[0]+W[0], this->p4[1]+W[1], this->p4[2]+W[2]};
      Prostopadloscian P(Wp1,Wp2,Wp3,Wp4,this->h);
      return P;
    }
  
  Prostopadloscian::Prostopadloscian(Wektor<3> W1, Wektor<3> W2, Wektor<3> W3, Wektor<3> W4, double H) //set
    {
      this->p1 = W1;
      this->p2 = W2;
      this->p3 = W3;
      this->p4 = W4;
      this->h = H;
    }
    
  std::ostream& operator << (std::ostream &strm, const Prostopadloscian &P)
    { 
      strm << "p1 = " << P[0] << endl;
      strm << "p2 = " << P[1] << endl;
      strm << "p3 = " << P[2] << endl;
      strm << "p4 = " << P[3] << endl;
      strm << "p5 = " << P[4] << endl;
      strm << "p6 = " << P[5] << endl;
      strm << "p7 = " << P[6] << endl;
      strm << "p8 = " << P[7] << endl;
      return strm;
    }
    
  const Wektor<3> & Prostopadloscian:: operator [] (int i) const //get
    {
       double A=0, B=0, C=0, v=0;
       A = (((this->p1[1]-this->p3[1])*(this->p2[2]-this->p3[2]))-(this->p2[1]-this->p3[1])*(this->p1[2]-this->p3[2])); //wyliczam wartosc A wektora naturalnego plaszczyzny n(A,B,C)
       B = (((this->p1[2]-this->p3[2])*(this->p2[0]-this->p3[0]))-(this->p2[2]-this->p3[2])*(this->p1[0]-this->p3[0])); //wyliczam wartosc B wektora naturalnego plaszczyzny n(A,B,C)
       C = (((this->p1[0]-this->p3[0])*(this->p2[1]-this->p3[1]))-(this->p2[0]-this->p3[0])*(this->p1[1]-this->p3[1])); //wyliczam wartosc C wektora naturalnego plaszczyzny n(A,B,C)
       v = sqrt(((this->h)*(this->h))/((A)*(A)+(B)*(B)+(C)*(C)));                                                       //dopasowuje skale wyliczonego wektora pod dlugosc boku prostopadloscianu
          Wektor<3> n{A*v,B*v,C*v}; 
          static Wektor<3> p5, p6, p7, p8;
          p5 = this->p1 + n;
          p6 = this->p2 + n;
          p7 = this->p3 + n;
          p8 = this->p4 + n;
      switch (i)
        {
          case 0:
            {
              return this->p1;
              break;
            }
          case 1:
            {
              return this->p2;
              break;
            }
          case 2:
            {
              return this->p3;
              break;
            }
          case 3:
            {
              return this->p4;
              break;
            }
          case 4:
            {
              return p5;
              break;
            }
          case 5:
            {
              return p6;
              break;
            }
          case 6:
            {
              return p7;
              break;
            }
          case 7:
            {
              return p8;
              break;
            }
          default:  
            {
              throw std::logic_error("Błąd indeksu");
              break;
            }
         }
    }
