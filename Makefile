all: KSGuitarSim test

KSGuitarSim: KSGuitarSim.o
	g++ -o KSGuitarSim KSGuitarSim.o StringSound.o RingBuffer.o -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

test: test.o RingBuffer.o
	g++ -o test test.o StringSound.o RingBuffer.o -std=c++11 -l boost_unit_test_framework

KSGuitarSim.o: KSGuitarSim.cpp StringSound.o
	g++ -c KSGuitarSim.cpp -o KSGuitarSim.o -std=c++11

test.o: test.cpp StringSound.o
	g++ -c test.cpp -o test.o 

StringSound.o: StringSound.cpp RingBuffer.o
	g++ -c StringSound.cpp -o StringSound.o -std=c++11

RingBuffer.o: RingBuffer.cpp
	g++ -c RingBuffer.cpp -o RingBuffer.o -std=c++11

clean:
	rm *.o test KSGuitarSim