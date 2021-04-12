
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --leak-check=full --verbose

SRCS = pa3.c tree.c stack.c
OBJS = $(SRCS:%.c=%.o)

pa3: $(OBJS)
	$(GCC) $(OBJS) -o pa3

.c.o: 
	$(GCC) -c $*.c

testall: test1 test2 test3 test4 memory

test1: pa3
	./pa3 /home/shay/a/bbelli/ece368/PA/PA3/examples/3.po /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my3.pr /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my3.dim /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my3.pck
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my3.pr /home/shay/a/bbelli/ece368/PA/PA3/examples/3.pr
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my3.pck /home/shay/a/bbelli/ece368/PA/PA3/examples/3.pck
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my3.dim /home/shay/a/bbelli/ece368/PA/PA3/examples/3.dim
	

test2: pa3
	./pa3 /home/shay/a/bbelli/ece368/PA/PA3/examples/8.po /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my8.pr /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my8.dim /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my8.pck
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my8.pr /home/shay/a/bbelli/ece368/PA/PA3/examples/8.pr
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my8.pck /home/shay/a/bbelli/ece368/PA/PA3/examples/8.pck
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my8.dim /home/shay/a/bbelli/ece368/PA/PA3/examples/8.dim

test3: pa3
	./pa3 /home/shay/a/bbelli/ece368/PA/PA3/examples/1K.po /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.pr /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.dim /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.pck
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.pr /home/shay/a/bbelli/ece368/PA/PA3/examples/1K_user.pr
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.dim /home/shay/a/bbelli/ece368/PA/PA3/examples/1K_user.dim
	diff /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.pck /home/shay/a/bbelli/ece368/PA/PA3/examples/1K_user.pck

test4: pa3
	./pa3 /home/shay/a/bbelli/ece368/PA/PA3/examples/100.po /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my100.pr /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my100.dim /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my100.pck

memory: pa3
	$(VAL) ./pa3 /home/shay/a/bbelli/ece368/PA/PA3/examples/1K.po /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.pr /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.dim /home/shay/a/bbelli/ece368/PA/PA3/myexamples/my1K.pck

clean: # remove all machine generated files
	rm -f pa3 *.o output? vallog testgen
