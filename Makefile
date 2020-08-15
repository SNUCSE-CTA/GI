CXX := g++

CXXFLAGS := -std=c++0x -O3 -w -DDEBUG
CPPFLAGS := -Iinclude

SRC := src
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(SOURCES:$(SRC)/%.cpp=$(OBJ)/%.o)

TARGET := program
INPUT1 := ./input/lcc_yeast.igraph
INPUT2 := ./input/sfl_lcc_yeast.igraph

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $(OBJ)

clean:
	@$(RM) -rv $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET) $(INPUT1) $(INPUT2)

