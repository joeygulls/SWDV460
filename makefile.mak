HEADERS=program.h headers.h

default:HelloWorld

HelloWorld.o: HelloWorld.c $(HEADERS)
	gcc -c HelloWorld.c -o HelloWorld.o

HelloWorld: HelloWorld.o
	gcc HelloWorld.o -o HelloWorld

clean:
	-rm -f HelloWorld.o
	-rm -f HelloWorld