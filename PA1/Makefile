WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla 
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=memory.txt --leak-check=full --verbose


SRCS = pa1.c shell_array.c shell_list.c
OBJS = $(SRCS:%.c=%.o)

pa1: $(OBJS) 
	$(GCC) $(OBJS) -o pa1

.c.o: 
	$(GCC) -c $*.c 

testall: test1 test2 

test1: pa1
	./pa1 -a examples/15.b 15sa.b
	diff examples/15sa.b 15sa.b
test2: pa1
	./pa1 -a examples/1K.b 1Ksa.b
	diff examples/1Ksa.b 1Ksa.b
memory: pa1
	$(VAL) ./pa1 examples/15.b > examples/15sa.b
clean: # remove all machine generated files
	rm -f pa1 *.o output? *.b