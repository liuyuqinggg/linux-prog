all:ball_clock

ball_clock: sqstack.o main.o queue.o
	$(CC) $^ -o $@

clean:
	rm *.o ball_clock -rf