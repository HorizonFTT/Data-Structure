test:test.o algorithm.o
	g++ test.o algorithm.o -o test.out

test.o:test.cpp 
	g++ -g -c test.cpp

algorithm.o:algorithm.cpp algorithm.hpp list.hpp stack.hpp queue.hpp binary_tree.hpp graph.hpp
	g++ -g -c algorithm.cpp

clean:
	rm -rf test test.o algorithm.o