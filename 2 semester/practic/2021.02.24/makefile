myProg: Insertion_sort.o main.o
	g++ Insertion_sort.o main.o -o myProg
Insertion_sort.o: Insertion_sort.h Insertion_sort.cpp
	g++ -c  Insertion_sort.cpp
main.o: Insertion_sort.h main.cpp
	g++ -c main.cpp
clean:
	rm -f myProg*.o
