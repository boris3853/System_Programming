TARGET = pthread_test
SRC = pthread_test.c
OBJ = pthread_test.o
CC = gcc
LDFLAGS = -pthread -lpthread
CFLAGS = -D_REENTRANT

all: $(OBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJ)

.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o *.swp $(TARGET)
