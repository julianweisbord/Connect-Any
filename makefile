a.out: connect_any.o main.o
	g++ connect_any.o main.o -o a.out
connect_any: connect_any.cpp
	g++ -c connect_any.cpp
main: main.cpp
	g++ main.cpp
clean:
	rm -f *.o *.out *.exe
