#include "stdlib.h"
#include "defs.h"
#include "stdio.h"

char *PrSq(const int sq) {

	static char SqStr[3];
	
	int file = FilesBrd[sq];
	int rank = RanksBrd[sq];
	
	
	
	sprintf(SqStr, "%c%c", ('a'+file), ('1'+rank));
	
	return SqStr;

}

char *PrMove(const int move) {

	static char MvStr[6];
	
	int ff = FilesBrd[FROMSQ(move)];
	int rf = RanksBrd[FROMSQ(move)];
	int ft = FilesBrd[TOSQ(move)];
	int rt = RanksBrd[TOSQ(move)];
	
	int promoted = PROMOTED(move);
	
	if(promoted) {
		char pchar = 'q';
		if(IsKn(promoted)) {
			pchar = 'n';
		} else if(IsRQ(promoted) && !IsBQ(promoted))  {
			pchar = 'r';
		} else if(!IsRQ(promoted) && IsBQ(promoted))  {
			pchar = 'b';
		}
		sprintf(MvStr, "%c%c%c%c%c", ('a'+ff), ('1'+rf), ('a'+ft), ('1'+rt), pchar);
	} else {
		sprintf(MvStr, "%c%c%c%c", ('a'+ff), ('1'+rf), ('a'+ft), ('1'+rt));
	}
	
	return MvStr;
}

//check if move exists
int ParseMove(char* ptrChar, S_BOARD *pos) {
	if(ptrChar[1] > '8' || ptrChar[1] < '1') return FALSE;
	if(ptrChar[3] > '8' || ptrChar[3] < '1') return FALSE;
	if(ptrChar[0] > 'h' || ptrChar[0] < 'a') return FALSE;
	if(ptrChar[2] > 'h' || ptrChar[2] < 'a') return FALSE;
	
	int from = FR2SQ(ptrChar[0] - 'a', ptrChar[1] - '1');
	int to = FR2SQ(ptrChar[2] - 'a', ptrChar[3] - '1');

	// printf("ptrCHAR:%s from:%d to:%d\n", ptrChar,from,to);

	S_MOVELIST list[1];
	GenerateAllMoves(pos, list);
	int Movenum = 0;
	int move = 0;
	int PromPce = EMPTY;

	for(Movenum = 0; Movenum < list->count; Movenum ++){
		move = list->moves[Movenum].move;
		if(FROMSQ(move) == from && TOSQ(move) == to){
			PromPce = PROMOTED(move);
			if(PromPce != EMPTY){
				if(IsRQ(PromPce) && !IsBQ(PromPce) && ptrChar[4] == 'r'){
					return move;
				}
				else if(!IsRQ(PromPce) && IsBQ(PromPce) && ptrChar[4] == 'b'){
					return move;
				}
				else if(IsRQ(PromPce) && IsBQ(PromPce) && ptrChar[4] == 'q'){
					return move;
				}
				else if(IsKn(PromPce) && ptrChar[4] == 'n'){
					return move;
				}
				continue;
			}
			return move;
		}
	}

	return NOMOVE;
}

void PrintMoveList(const S_MOVELIST *list) {
	int index = 0;
	int score = 0;
	int move = 0;
	printf("MoveList: %d\n",list->count);
	
	for(index = 0; index < list->count; ++index) {
	
		move = list->moves[index].move;
		score = list->moves[index].score;
		
		printf("Move:%d > %s (score:%d)\n",index+1,PrMove(move),score);
	}
	printf("MoveList Total %d Moves:\n\n",list->count);
}
