TARGET1 = pthread_test 
OBJ1 = pthread_test.o
SRC1 = pthread_test.c

TARGET2 = simultaneous_thread
OBJ2 = simultaneous_thread.o
SRC2 = simultaneous_thread.c

CC = gcc
LDFLAGS = -pthread -lpthread
CFLAGS = -D_REENTRANT

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJ1)
	$(CC) -o $(TARGET1) $(LDFLAGS) $(OBJ1)

$(TARGET2): $(OBJ2)
	$(CC) -o $(TARGET2) $(LDFLAGS) $(OBJ2)

.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o *.swp $(TARGET)
