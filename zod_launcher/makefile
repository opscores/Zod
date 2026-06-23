JOBS=$(shell nproc 2>/dev/null || echo 4)
MAKEFLAGS=-j$(JOBS)

default:
	g++ -g -o zod_launcher *.cpp `wx-config --cppflags` `wx-config --libs`

clean:
	rm -f zod_launcher
