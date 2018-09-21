CXX 		:= g++
TARGET 	:= gengu

SRCEXT 	:= cpp
HDREXT 	:= h
SRCDIR 	:= ./src
HDRDIR 	:= ./include
DOXDIR 	:= ./doxy

SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
HEADERS := $(shell find $(HDRDIR) -type f -name "*.$(HDREXT)")

CFLAGS 	:= -g -Wall -std=c++11 -no-pie
INCLUDE := -I$(HDRDIR) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -L. -lBox2D

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) -o $@ $(SOURCES) $(CFLAGS) $(INCLUDE)

run:
	./$(TARGET)

all: clean $(TARGET) run

doxygen:
	doxygen $(DOXDIR)/doxyfile

clean:
	@echo "Clenaing..."
	$(RM) -r $(TARGET) $(DOXDIR)/html

.PHONY: clean
