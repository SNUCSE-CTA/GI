PROG = program
CC = g++
CPPFLAGS = -w -std=c++11 -O3
OBJS = main.o algorithm.o graph.o refine.o coloring.o backtrack.o cs.o mapping.o

program: $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o: algorithm.o graph.o 
	$(CC) $(CPPFLAGS) -c main.cpp

algorithm.o: graph.o refine.o coloring.o backtrack.o cs.o mapping.o
	$(CC) $(CPPFLAGS) -c algorithm.cpp

graph.o:
	$(CC) $(CPPFLAGS) -c graph.cpp

refine.o: graph.o coloring.o
	$(CC) $(CPPFLAGS) -c refine.cpp

coloring.o:
	$(CC) $(CPPFLAGS) -c coloring.cpp

backtrack.o: graph.o cs.o mapping.o
	$(CC) $(CPPFLAGS) -c backtrack.cpp

cs.o: graph.o coloring.o 
	$(CC) $(CPPFLAGS) -c cs.cpp

mapping.o:
	$(CC) $(CPPFLAGS) -c mapping.cpp

clean:
	rm $(PROG) $(OBJS)

run:
	./$(PROG) file1 file2
