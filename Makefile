all: lab1
    ./lab1

lab1: main.o util.o algorithm.o io.o
    g++ main.o util.o algorithm.o io.o -o lab1

main.o: main.cpp header.h
    g++ -c main.cpp -o main.o

util.o: util.cpp header.h
    g++ -c util.cpp -o util.o

io.o: io.cpp header.h
    g++ -c io.cpp -o io.o

algorithm.o: algorithm.cpp header.h
    g++ -c algorithm.cpp -o algorithm.o