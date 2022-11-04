CXXFLAGS=--coverage -g -O0

main: main.o funcs.o caesar.o
	g++ -o main --coverage -g -O0 main.o funcs.o caesar.o

tests: tests.o funcs.o caesar.o
	g++ -o tests --coverage -g -O0 tests.o funcs.o caesar.o
	./tests
	gcovr 2> /dev/null > /dev/null
	gcovr --html-details coverage.html



funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h caesar.h

tests.o: tests.cpp doctest.h funcs.h caesar.h
	g++ -c -std=c++11 tests.cpp

caesar.o: caesar.cpp caesar.h

clean:
	rm -f main.o funcs.o tests.o caesar.o *gcda *html *gcno
