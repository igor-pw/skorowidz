CFLAGS = -Wall -Wextra -std=c99
TARGET = skorowidz

all: $(TARGET)

skorowidz: main.c dyn_vec2D.o index.o
	$(CC) $(CFLAGS) main.c dyn_vec2D.o index.o -o skorowidz

valgrind: main.c dyn_vec2D.o index.o
	valgrind ./$(TARGET) dane jak nie 

gdb: main.c dyn_vec2D.c index.c
	$(CC) $(CFLAGS) -ggdb main.c dyn_vec2D.c index.c -o skorowidz

.o: dyn_vec2D.c dyn_vec2D.h index.c index.h main.o
	$(CC) $(CFLAGS) dyn_vec2D.c -c -o dyn_vec2D.o
	$(CC) $(CFLAGS) index.c -c -o index.o

clean:
	rm -f *.o

clean_all:
	rm -f *.o skorowidz

test:
	./$(TARGET) dane jak nie
