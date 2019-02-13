P0: main.o buildtree.o traversals.o
	g++ main.o buildtree.o traversals.o -o P0

main.o: main.cpp
	g++ -c main.cpp

buildtree.o: buildtree.cpp
	g++ -c buildtree.cpp

traversals.o: traversals.cpp
	g++ -c traversals.cpp

clean:
	rm -rf *.o all P0

