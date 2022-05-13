
mistborn: main.o messages.o grid.o customlist.o characters.o items.o 
	g++ main.o messages.o grid.o customlist.o characters.o items.o -o mistborn

main.o: main.cpp 
	g++ -c main.cpp

messages.o: messages.cpp messages.h
	g++ -c messages.cpp

customlist.o: customlist.cpp customlist.h
	g++ -c customlist.cpp

items.o: items.cpp items.h
	g++ -c items.cpp

characters.o: characters.cpp characters.h
	g++ -c characters.cpp

grid.o: grid.cpp grid.h
	g++ -c grid.cpp

clean:
	rm *.o mistborn