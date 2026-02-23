all: build/debug.out

build/my_string.o: src/my_string.cpp src/my_string.hpp
	g++ -g -c -o build/my_string.o src/my_string.cpp

build/text_wrapper.o: src/text_wrapper.cpp src/text_wrapper.hpp
	g++ -g -c -o build/text_wrapper.o src/text_wrapper.cpp

build/rect.o: src/rect.cpp src/rect.hpp
	g++ -g -c -o build/rect.o src/rect.cpp

build/matrix.o: src/matrix.cpp src/matrix.hpp
	g++ -g -c -o build/matrix.o src/matrix.cpp

build/bochka.o: src/bochka.cpp src/bochka.hpp
	g++ -g -c -o build/bochka.o src/bochka.cpp

build/debug.out: src/lab1.cpp build/my_string.o build/text_wrapper.o build/rect.o build/matrix.o build/bochka.o
	g++ -g -c -o build/debug.out src/lab1.cpp build/my_string.o build/text_wrapper.o build/rect.o build/matrix.o build/bochka.o

debug: build/debug.out
	gdb build/debug.out

build/leaks.out: build/debug.out
	cp build/debug.out build/leaks.out

leaks: build/debug.out
	valgrid --leak-check=full ./build/leaks.out < input.txt
