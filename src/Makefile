all: main

main: fifo.o rr.o main.o proceso.o planificador.o
	g++ fifo.o rr.o main.o proceso.o planificador.o -o main

%.o : %.cc
	$(CXX) -o $@ $< -c
