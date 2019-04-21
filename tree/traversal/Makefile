# help from : https://opensource.com/article/18/8/what-how-makefile

CPP = g++
LDFLAG = -std=c++11

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%)

all: ${BINS}

%: %.o
	@echo "Checking ..."
	${CPP} -o $@ $^
%.o: %.cpp
	${CPP} ${LDFLAG} -c $<

clean:
	@echo "Cleaning up..."
	rm -rf ${BINS} *.o
	