main.o: main.cpp functions.h
	g++ -c $<
main:  main.o
	g++ $^ -o $@
clean:
	rm -f main.o main
.PHONY: clean
