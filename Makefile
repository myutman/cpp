all: lab1
	./lab1

lab1: bin/main.o bin/util.o bin/algorithm.o bin/io.o
	g++ bin/main.o bin/util.o bin/algorithm.o bin/io.o -o lab1

bin/main.o: src/main.cpp include/main.h
	g++ -c src/main.cpp -o bin/main.o

bin/util.o: src/util.cpp include/util.h
	g++ -c src/util.cpp -o bin/util.o

bin/io.o: src/io.cpp
	g++ -c src/io.cpp -o bin/io.o

bin/algorithm.o: src/algorithm.cpp include/algorithm.h
	g++ -c src/algorithm.cpp -o bin/algorithm.o