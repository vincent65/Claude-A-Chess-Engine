#include "stdio.h"
#include "defs.h"
#include "stdlib.h"


#define WAC1 "2rr3k/pp3pp1/1nnqbN1p/3pN3/2pP4/2P3Q1/PPB4P/R4RK1 w - -"

int main() {	

	AllInit();		
	
	S_BOARD board[1];
	S_MOVELIST list[1];
	S_SEARCHINFO info[1];
	ParseFen(START_FEN,board);
	
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
			info->depth = 4;
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
	
	return 0;
}








