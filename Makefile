exec : main.o utils.o tests.o
	g++ -o exec main.o utils.o tests.o

main.o : main.cpp
	g++ -c main.cpp

utils.o : utils.cpp
	g++ -c utils.cpp

tests.o : tests.cpp
	g++ -c tests.cpp

clean :
	rm -f *.o 
	rm -f exec