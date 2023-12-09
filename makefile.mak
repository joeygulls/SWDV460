default:helloworld

helloworld.o: helloworld.c $(HEADERS)
	C:\ProgramData\mingw64\mingw64\bin\gcc.exe -c helloworld.c -o helloworld.o

helloworld: helloworld.o
	C:\ProgramData\mingw64\mingw64\bin\gcc.exe helloworld.o -o helloworld

clean:
	-rm -f helloworld.o
	-rm -f helloworld