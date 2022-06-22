all:queue

queue: main.o queue.o llist.o
	$(CC) $^ -o $@

clean:
	rm *.o main -rf