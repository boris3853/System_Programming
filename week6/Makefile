TARGET1 = pthread_test 
OBJ1 = pthread_test.o
SRC1 = pthread_test.c

TARGET2 = simultaneous_thread
OBJ2 = simultaneous_thread.o
SRC2 = simultaneous_thread.c

TARGET3 = sync_test
OBJ3 = sync_test.o
SRC3 = sync_test.c

TARGET4 = sync_test2
OBJ4 = sync_test2.o
SRC4 = sync_test2.c

TARGET5 = matrix1
OBJ5 = matrix_setup.o matrix1.o
SRC5 = matrix_setup.c matrix1.c

TARGET6 = pthread_attr
OBJ6 = pthread_attr.o
SRC6 = pthread_attr.c

TARGET7 = sync_test3
OBJ7 = sync_test3.o
SRC7 = sync_test3.c

TARGET8 = pthread_attr2
OBJ8 = pthread_attr2.o
SRC8 = pthread_attr2.c

TARGET9 = pthread_cancel
OBJ9 = pthread_cancel.o
SRC9 = pthread_cancel.c

TARGET10 = pthread_abundance
OBJ10 = pthread_abundance.o
SRC10 = pthread_abundance.c

TARGET11 = matrix2
OBJ11 = matrix_setup.o matrix2.o
SRC11 = matrix_setup.c matrix2.c



CC = gcc
LDFLAGS = -pthread -lpthread
CFLAGS = -D_REENTRANT

all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11)

$(TARGET1): $(OBJ1)
	$(CC) -o $(TARGET1) $(LDFLAGS) $(OBJ1)

$(TARGET2): $(OBJ2)
	$(CC) -o $(TARGET2) $(LDFLAGS) $(OBJ2)

$(TARGET3): $(OBJ3)
	$(CC) -o $(TARGET3) $(LDFLAGS) $(OBJ3)

$(TARGET4): $(OBJ4)
	$(CC) -o $(TARGET4) $(LDFLAGS) $(OBJ4)

$(TARGET5): $(OBJ5)
	$(CC) -o $(TARGET5) $(LDFLAGS) $(OBJ5)

$(TARGET6): $(OBJ6)
	$(CC) -o $(TARGET6) $(LDFLAGS) $(OBJ6)

$(TARGET7): $(OBJ7)
	$(CC) -o $(TARGET7) $(LDFLAGS) $(OBJ7)

$(TARGET8): $(OBJ8)
	$(CC) -o $(TARGET8) $(LDFLAGS) $(OBJ8)

$(TARGET9): $(OBJ9)
	$(CC) -o $(TARGET9) $(LDFLAGS) $(OBJ9)

$(TARGET10): $(OBJ10)
	$(CC) -o $(TARGET10) $(LDFLAGS) $(OBJ10)

$(TARGET11): $(OBJ11)
	$(CC) -o $(TARGET11) $(LDFLAGS) $(OBJ11)



.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o *.swp $(TARGET)
