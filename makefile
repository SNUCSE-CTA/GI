PROG = program
CC = g++
CPPFLAGS = -w -std=c++11 -O3
OBJS = main.o algorithm.o graph.o refine.o coloring.o backtrack.o cs.o global.o memory.o heap.o

all: $(PROG)

program: $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o: algorithm.o graph.o 
	$(CC) $(CPPFLAGS) -c main.cpp

algorithm.o: global.o graph.o refine.o coloring.o backtrack.o cs.o
	$(CC) $(CPPFLAGS) -c algorithm.cpp

graph.o:
	$(CC) $(CPPFLAGS) -c graph.cpp

refine.o: graph.o coloring.o memory.o
	$(CC) $(CPPFLAGS) -c refine.cpp

coloring.o:
	$(CC) $(CPPFLAGS) -c coloring.cpp

backtrack.o: graph.o cs.o memory.o heap.o
	$(CC) $(CPPFLAGS) -c backtrack.cpp

cs.o: graph.o coloring.o 
	$(CC) $(CPPFLAGS) -c cs.cpp

heap.o:
	$(CC) $(CPPFLAGS) -c heap.cpp

global.o:
	$(CC) $(CPPFLAGS) -c global.cpp

memory.o:
	$(CC) $(CPPFLAGS) -c memory.cpp

clean:
	rm $(PROG) $(OBJS)

run:
	./$(PROG) file1 file2
