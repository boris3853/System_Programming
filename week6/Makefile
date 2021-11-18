TARGET1 = pthread_test 
OBJ1 = pthread_test.o
SRC1 = pthread_test.c

TARGET2 = simultaneous_thread
OBJ2 = simultaneous_thread.o
SRC2 = simultaneous_thread.c

TARGET3 = sync_test
OBJ3 = sync_test.o
SRC3 = sync_test.c


CC = gcc
LDFLAGS = -pthread -lpthread
CFLAGS = -D_REENTRANT

all: $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1): $(OBJ1)
	$(CC) -o $(TARGET1) $(LDFLAGS) $(OBJ1)

$(TARGET2): $(OBJ2)
	$(CC) -o $(TARGET2) $(LDFLAGS) $(OBJ2)

$(TARGET3): $(OBJ3)
	$(CC) -o $(TARGET3) $(LDFLAGS) $(OBJ3)

.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o *.swp $(TARGET)
