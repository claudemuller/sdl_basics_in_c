CFLAGS = -Wall -g
IFLAGS = -I/usr/include/SDL
LFLAGS = -L/usr/lib -lSDL2
CFILES = ./*.h ./*.c
OBJS   = game.o
PROG = game
CXX = gcc

build:
	$(CXX) $(CFLAGS) \
	$(CFILES) \
	-o $(PROG) \
	$(IFLAGS) \
	$(LFLAGS)

build_and_run:
	$(CXX) $(CFLAGS) \
	$(CFILES) \
	-o $(PROG) \
	$(IFLAGS) \
	$(LFLAGS) \
	&& ./game

clean:
	rm ./game ./*.o;

run:
	./game;
