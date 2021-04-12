
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --leak-check=full --verbose --show-leak-kinds=all --track-origins=yes

SRCS = pa2.c tree.c stack.c
OBJS = $(SRCS:%.c=%.o)

pa2: $(OBJS)
	$(GCC) $(OBJS) -o pa2

.c.o: 
	$(GCC) -c $*.c

testall: test1 test2 


test_compile: pa2
	./pa2 /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_huff.hbt /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval 

test1: pa2
	./pa2 /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_huff.hbt /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval 
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_huff.tree /home/shay/a/bbelli/ece368/PA/re_pa2/tree/gophers_huff.tree
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/decoded/gophers
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/count/gophers.count
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval /home/shay/a/bbelli/ece368/PA/re_pa2/eval/gophers_huff.eval
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/tree/binary1_huff.tree
test1_2: pa2
	./pa2 /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_huff.hbt /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval 
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/tree/gophers_huff.tree
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/decoded/gophers
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/count/gophers.count
	
test2: pa2
	./pa2 /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_nonhuff.hbt /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval 
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_huff.tree /home/shay/a/bbelli/ece368/PA/re_pa2/tree/gophers_nonhuff.tree
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/decoded/gophers
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/count/gophers.count
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval /home/shay/a/bbelli/ece368/PA/re_pa2/eval/gophers_huff.eval
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/tree/binary1_huff.tree


test3: pa2
	./pa2 /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_nonhuff.hbt /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval 
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_huff.tree /home/shay/a/bbelli/ece368/PA/re_pa2/tree/gophers_nonhuff.tree
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/decoded/gophers
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/count/gophers.count
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval /home/shay/a/bbelli/ece368/PA/re_pa2/eval/gophers_huff.eval
	diff /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/tree/binary1_huff.tree

memory: pa2
	$(VAL) ./pa2 /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/gophers_huff.hbt /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval 

memory2: pa2
	$(VAL) ./pa2 /home/shay/a/bbelli/ece368/PA/re_pa2/encoded/woods_nonhuff.hbt /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.tree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.ori /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.count /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.htree /home/shay/a/bbelli/ece368/PA/re_pa2/myexamples/gophers.eval 

clean: # remove all machine generated files
	rm -f pa2 *.o output? vallog testgen
