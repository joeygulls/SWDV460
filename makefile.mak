CC=gcc 
CFLAGS=-Wall
LIB= ./libxml2-2.7.8.win32/libxml2
INCLUDE= ./libxml2-2.7.8.win32/include

all: binary assembly

binary: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) $(LIB) $(INCLUDE)

assembly: $(SOURCE)
	$(CC) $(CFLAGS) -fverbose-asm -S -masm=intel $(SOURCE)

clean:
	    rm -f books books.o



