all: test

test: test.o RingBuffer.o
	g++ -o test test.o StringSound.o RingBuffer.o -std=c++11 -l boost_unit_test_framework

main.o: main.cpp RingBuffer.o
	g++ -c main.cpp -o main.o -std=c++11

test.o: test.cpp StringSound.o
	g++ -c test.cpp -o test.o 

StringSound.o: StringSound.cpp RingBuffer.o
	g++ -c StringSound.cpp -o StringSound.o -std=c++11

RingBuffer.o: RingBuffer.cpp
	g++ -c RingBuffer.cpp -o RingBuffer.o -std=c++11

clean:
	rm *.o test