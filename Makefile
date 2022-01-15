main: main.o image.o pixel.o lodepng.o filter.o
	g++ -std=c++11 main.o image.o pixel.o lodepng.o filter.o -o main;rm *.o

image.o: src/image.cpp src/image.h
	g++ -std=c++11 -c src/image.cpp -o image.o

main.o : src/main.cpp
	g++ -std=c++11 -c src/main.cpp -o main.o

pixel.o: src/pixel.cpp src/pixel.h
	g++ -std=c++11 -c src/pixel.cpp -o pixel.o

lodepng.o: src/lodepng/lodepng.cpp src/lodepng/lodepng.h
	g++ -std=c++11 -c src/lodepng/lodepng.cpp -o lodepng.o

filter.o: src/filter.cpp src/filter.h
	g++ -std=c++11 -c src/filter.cpp -o filter.o

clean:
	rm *.o;rm main

