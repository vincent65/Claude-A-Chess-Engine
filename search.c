
#include "defs.h"
#include "stdio.h"


static void CheckUp() {
    //check if up or interrupt from gui

}

static int IsRepition(const S_BOARD *pos){
    int index = 0;
	for(index = pos->hisPly - pos->fiftyMove; index < pos->hisPly - 1; index ++){
	ASSERT(index >= 0 && index < MAXGAMEMOVES);
		if(pos->posKey == pos->history[index].posKey){
			return TRUE;
		}
	}
	return FALSE;
}

static void ClearForSearch(S_BOARD *pos, S_SEARCHINFO *info) {

}

//triees to solve the horizon problem
static int Quiescence(int alpha, int beta, S_BOARD *pos, S_SEARCHINFO *info) {
    return 0;
}

static int AlphaBeta(int alpha, int beta, int depth, S_SEARCHINFO *info, S_BOARD *pos, int DoNull) {
    return 0;
}

void SearchPosition(S_BOARD *pos, S_SEARCHINFO *info) {
    //iterative deepening, searchinit
}