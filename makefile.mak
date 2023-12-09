default:helloworld

helloworld.o: helloworld.c $(HEADERS)
	gcc -c helloworld.c -o helloworld.o

helloworld: helloworld.o
	gcc helloworld.o -o helloworld

clean:
	-rm -f helloworld.o
	-rm -f helloworld