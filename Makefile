name = a.out
HEADERS = -I./include

trash = $(shell find ./ -name '*.o') $(name)
sources = $(shell find ./src -name '*.cpp')
objects = $(sources:.cpp=.o)

SHELL := /bin/bash
CC = g++
CFLAGS = -Wall $(HEADERS)

all: release

release: $(name)

debug: CFLAGS += -g
debug: $(name)

$(name): $(objects)
	$(CC) $(LDFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) $(headers) -o $@ -c $< 

clean:
	rm -rf $(trash)

.ONESHELL: