.PHONY: all, clean, run

CXX := gcc
CXXFLAGS := -c -g -Wall -Wextra -Werror -Og -g3 -std=c17
LDFLAGS := -g
HEADERS := $(wildcard *.h)
objs := $(patsubst %.c,%.o,$(wildcard *.c))

all: executable

executable: $(objs)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CXX) $(CXXFLAGS) $<


clean:
	rm -f $(objs)

run:
	./executable
