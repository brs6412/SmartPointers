CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

SRCS = main.cpp File.cpp FileManager.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = file_manager

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean