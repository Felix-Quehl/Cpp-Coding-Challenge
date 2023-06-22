name = a.out
HEADERS = -I./include

trash = $(shell find ./ -name '*.o') $(name)
sources = $(shell find ./src -name '*.cpp')
objects = $(sources:.cpp=.o)

SHELL := /bin/bash
CC = g++
CFLAGS = -std=c++17 -Wall $(HEADERS) 

all: release

release: $(name)

debug: CFLAGS += -g
debug: $(name)

$(name): $(objects)
	$(CC) $(LDFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) $(headers) -o $@ -c $< 

test: $(name)
	./$(name)

clean:
	rm -rf $(trash)

.ONESHELL: