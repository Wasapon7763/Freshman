CC=gcc
OBJS=main.o stack.o que.o

test-prog: $(OBJS)
	$(CC) $(OBJS) -o test-prog

clean:
	rm *.o test-prog

stack.o: stack.c stack.h
que.o: que.c que.h
main.o: main.c que.h stack.h