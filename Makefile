CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty
	./obroty

obroty: obj obj/main.o obj/Prostopadloscian.o obj/Macierz.o obj/Wektor.o obj/gnuplot.o
	g++ -Wall -pedantic -std=c++0x -o obroty obj/main.o obj/Wektor.o\
                        obj/Macierz.o obj/Prostopadloscian.o obj/gnuplot.o -lpthread
	

obj:
	mkdir obj

obj/gnuplot.o: src/gnuplot.cpp inc/gnuplot.hh 
	g++ -c ${CXXFLAGS} -o obj/gnuplot.o src/gnuplot.cpp
	
obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Macierz.hh inc/Wektor.hh inc/gnuplot.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/interface.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor.o src/Wektor.cpp
	
gnuplot.hh: inc/interface.hh
	touch inc/gnuplot.hh

clean:
	rm -f obj/*.o obroty_2D
