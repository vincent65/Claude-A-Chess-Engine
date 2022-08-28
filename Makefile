all:
	gcc otter_engine.c init.c bitboards.c hashkeys.c board.c data.c attack.c io.c movegen.c validate.c makemove.c perft.c misc.c pvtable.c -o chess


