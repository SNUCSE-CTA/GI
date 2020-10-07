CXX := g++
AR	:= ar

CXXFLAGS := -std=c++0x -O3 -w #-DDEBUG
CPPFLAGS := -Iinclude
#CPPTESTFLAGS := -Ideps/googletest/googletest/include
CPPTESTFLAGS :=
#TEST_LIBS := deps/googletest/lib/libgtest.a -lpthread
TEST_LIBS := -lgtest -lpthread

SRC := src
TEST_SRC := tests

SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(SRCS:$(SRC)/%.cpp=$(SRC)/%.o)

TEST_SRCS=$(wildcard $(TEST_SRC)/*.cpp)
TEST_OBJS=$(TEST_SRCS:$(TEST_SRC)/%.cpp=$(TEST_SRC)/%.o)

EXAMPLE := program
TARGET := libgi.a
TESTP := test_run

GRAPH  := yeast
INPUT1 := ./input/lcc_$(GRAPH).igraph
INPUT2 := ./input/sfl_lcc_$(GRAPH).igraph

.PHONY: all clean run

all: $(TARGET) $(TESTP) $(GTEST)

$(TARGET):	$(OBJS)
	$(AR) rc $(TARGET) $(OBJS)

$(SRC)/%.o:	$(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(TESTP):	$(TARGET) $(TEST_OBJS)
	$(CXX) -o $(TESTP) $(TEST_OBJS) $(TARGET) $(TEST_LIBS) 

$(TEST_SRC)/%.o:	$(TEST_SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(CPPTESTFLAGS) -c $< -o $@

clean:
	$(RM) -rv $(TARGET) $(OBJ)
	$(RM) -rv $(TEST_OBJS) $(TESTP)

run: $(TARGET)
	./$(TARGET) $(INPUT1) $(INPUT2)

test:	$(TESTP)
	./$(TESTP)
