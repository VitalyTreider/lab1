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
	g++ -g -o build/debug.out src/lab1.cpp build/my_string.o build/text_wrapper.o build/rect.o build/matrix.o build/bochka.o

debug: build/debug.out
	gdb build/debug.out

build/leaks.out: build/debug.out
	cp build/debug.out build/leaks.out

leaks: build/leaks.out
	valgrind --leak-check=full ./build/leaks.out < input.txt

clean:
	rm -rf build/*.o build/debug.out build/leaks.out

build/test_rect_basic.out: tests/test_rect_basic_methods.cpp src/rect.cpp
	g++ -g -o build/test_rect_basic.out tests/test_rect_basic_methods.cpp src/rect.cpp

build/test_rect_properties.out: tests/test_rect_properties.cpp src/rect.cpp
	g++ -g -o build/test_rect_properties.out tests/test_rect_properties.cpp src/rect.cpp

build/test_rect_operations.out: tests/test_rect_operations.cpp src/rect.cpp
	g++ -g -o build/test_rect_operations.out tests/test_rect_operations.cpp src/rect.cpp

build/test_bounding_rect.out: tests/test_bounding_rect.cpp src/rect.cpp
	g++ -g -o build/test_bounding_rect.out tests/test_bounding_rect.cpp src/rect.cpp

test: build/test_rect_basic.out build/test_rect_properties.out build/test_rect_operations.out build/test_bounding_rect.out
	@echo "Running basic methods test..."
	./build/test_rect_basic.out
	@echo "Running properties tests (width, height) ..."
	./build/test_rect_properties.out
	@echo "Running operations tests (move, inflate) ..."
	./build/test_rect_operations.out
	@echo "Running bounding rect tests ..."
	./build/test_bounding_rect.out
	@echo "--ALL TESTS PASSED--"
