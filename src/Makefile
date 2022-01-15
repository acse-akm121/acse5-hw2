main: main.o image.o pixel.o lodepng.o
	g++ -std=c++11 main.o image.o pixel.o lodepng.o -o main

image.o: image.cpp image.h
	g++ -std=c++11 -c image.cpp -o image.o

main.o : main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

pixel.o: pixel.cpp pixel.h
	g++ -std=c++11 -c pixel.cpp -o pixel.o

lodepng.o: lodepng/lodepng.cpp lodepng/lodepng.h
	g++ -std=c++11 -c lodepng/lodepng.cpp -o lodepng.o

clean:
	rm *.o;rm main

