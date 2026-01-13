exec : main.o utils.o
	g++ -o exec main.o utils.o

main.o : main.cpp
	g++ -c main.cpp

utils.o : utils.cpp
	g++ -c utils.cpp

clean :
	rm -f *.o 
	rm -f exec