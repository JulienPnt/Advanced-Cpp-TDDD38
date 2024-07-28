CC=g++
CFLAGS=-I.
DEPS = src/linked_list.hpp

linked_list: src/main.cpp src/linked_list.cpp $(DEPS)
	$(CC) -o build/linked_list src/main.cpp src/linked_list.cpp

clean:
	rm -f build/*


