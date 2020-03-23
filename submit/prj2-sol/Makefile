CXXFLAGS = -g -Wall -std=c++17

all:	nums seq-test
nums:	seq.hh arrayseq.hh dlinkseq.hh command.cc nums.cc
	g++ $(CXXFLAGS) $^ -o $@
seq-test: seq.hh arrayseq.hh dlinkseq.hh command.cc seq-test.cc
	g++ $(CXXFLAGS) $^ -o $@


CXX_FILES = $(wildcard *.cc)
TARGETS = $(CXX_FILES:%.cc=%)


.phony:		clean
clean:
		rm -f *.o *~ $(TARGETS)

.gitignore: $(CXX_FILES)
	cat</dev/null >$@
	for t in $(TARGETS); do echo $$t>>$@; done
