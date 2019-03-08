P0: main.o buildtree.o traversals.o helpers.o
	g++ main.o buildtree.o traversals.o helpers.o -o P0

main.o: main.cpp
	g++ -c main.cpp

buildtree.o: buildtree.cpp
	g++ -c buildtree.cpp

traversals.o: traversals.cpp
	g++ -c traversals.cpp

helpers.o: helpers.cpp
	g++ -c helpers.cpp
clean:
	rm -rf *.o P0

