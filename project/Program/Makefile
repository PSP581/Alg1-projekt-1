CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE = binary_tree

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)
