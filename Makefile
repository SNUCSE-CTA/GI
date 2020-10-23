CXX := g++
AR	:= ar

CXXFLAGS := -std=c++0x -O3 -w #-DDEBUG
CPPFLAGS := -Iinclude
CPPTESTFLAGS :=
TEST_LIBS := -lgtest -lpthread

SRC := src
OBJ := obj
TEST_SRC := tests

SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(SRCS:$(SRC)/%.cpp=$(SRC)/%.o)

TEST_SRCS=$(wildcard $(TEST_SRC)/*.cpp)
TEST_OBJS=$(TEST_SRCS:$(TEST_SRC)/%.cpp=$(TEST_SRC)/%.o)

GI := GI
LIBGI := libgi.a
TESTP := test_run

GRAPH  := yeast
INPUT1 := ./input/lcc_$(GRAPH).igraph
INPUT2 := ./input/sfl_lcc_$(GRAPH).igraph

.PHONY: all clean run

all: $(GI)

$(GI): $(SRC)/program.cpp $(LIBGI)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(SRC)/program.cpp -o $(SRC)/program.o
	$(CXX) $(CXXFLAGS) $(SRC)/program.o libgi.a -o $@

$(LIBGI): $(OBJS)
	$(AR) rc $(LIBGI) $(OBJS)

$(SRC)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(TESTP): $(LIBGI) $(TEST_OBJS)
	$(CXX) -o $(TESTP) $(TEST_OBJS) $(LIBGI) $(TEST_LIBS) 

$(TEST_SRC)/%.o: $(TEST_SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(CPPTESTFLAGS) -c $< -o $@

example: examples/example.cpp $(LIBGI)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c examples/example.cpp -o examples/example.o
	$(CXX) $(CXXFLAGS) examples/example.o libgi.a -o $@

clean:
	$(RM) -rv $(GI)
	$(RM) -rv $(LIBGI) $(OBJS)
	$(RM) -rv $(TEST_OBJS) $(TESTP)

run: $(GI)
	./$(GI) $(INPUT1) $(INPUT2)

test:	$(TESTP)
	./$(TESTP)

