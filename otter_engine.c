#include "stdio.h"
#include "defs.h"
#include "stdlib.h"


#define WAC1 "2rr3k/pp3pp1/1nnqbN1p/3pN3/2pP4/2P3Q1/PPB4P/R4RK1 w - -"
#define WAC2 "r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1KQB1R w KQkq - 0 1"
int main() {	

	AllInit();		
	
	// S_BOARD board[1];
	S_BOARD* board = GenBoard();
	InitPvTable(board->PvTable);
	S_MOVELIST list[1];
	S_SEARCHINFO info[1];
	ParseFen(WAC2,board);
	
	char input[6];
	int Move = NOMOVE;
	int PvNum = 0;
	int Max = 0;
	while(TRUE) {
		PrintBoard(board);
		printf("Please enter a move > ");
		fgets(input, 6, stdin);
		
		if(input[0]=='q') {
			break;
		} else if(input[0]=='t') {
			TakeMove(board);			
		} else if(input[0]=='s') {
			info->depth = 6;
			SearchPosition(board, info);
		} else {
			Move = ParseMove(input, board);
			if(Move != NOMOVE) {
				StorePvMove(board, Move);
				MakeMove(board,Move);
			} else {
				printf("Move Not Parsed:%s\n",input);
			}
		}	
		
		fflush(stdin);
	}

	free(board->PvTable->pTable);
	
	return 0;
}








