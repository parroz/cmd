CC=gcc
CFLAGS= -Wall -ansi -pedantic
OBJS= main.o cmd.o monitor.o
TARGET=cmd

%.o : %.c
	$(CC) $(CFLAGS) -c $^ 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o $(TARGET)
