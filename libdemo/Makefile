all: main.exe

main.exe: main.o lib.o lib2.o
	g++ main.o lib.o lib2.o -o main.exe

main.o: main.cpp lib.h
	g++ -c main.cpp

lib.o: lib.cpp lib.h
	g++ -c lib.cpp

lib2.o: lib2.cpp lib2.h
	g++ -c lib2.cpp


