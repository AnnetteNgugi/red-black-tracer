all:
	g++ -std=c++17 src/*.cpp -Iinclude -o tracer

test:
	g++ -std=c++17 src/Node.cpp src/RedBlackTree.cpp tests/test_redblack.cpp -Iinclude -o tests_run
	./tests_run