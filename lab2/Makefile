all: init lab2

init:    
	mkdir -p bin

lab2: test.o test_str.o str.o
	g++ bin/test.o bin/test_str.o bin/str.o -o lab2

test.o: src/test.cpp include/test_str.h
	g++ -c src/test.cpp -o bin/test.o

str.o: src/str.cpp
	g++ -c src/str.cpp -o bin/str.o

test_str.o: src/test_str.cpp include/str.h
	g++ -c src/test_str.cpp -o bin/test_str.o

clean:
	rm -rf bin
	rm -rf lab2