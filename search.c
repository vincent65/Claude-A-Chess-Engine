// search.c

#include "stdio.h"
#include "defs.h"

#define INFINITE 30000
#define MATE 29000

static void CheckUp() {
	// .. check if time up, or interrupt from GUI
}

static int IsRepetition(const S_BOARD *pos) {

	int index = 0;

	for(index = pos->hisPly - pos->fiftyMove; index < pos->hisPly-1; ++index) {	
		ASSERT(index >= 0 && index < MAXGAMEMOVES);		
		if(pos->posKey == pos->history[index].posKey) {
			return TRUE;
		}
	}	
	return FALSE;
}

static void ClearForSearch(S_BOARD *pos, S_SEARCHINFO *info) {
	
	int index = 0;
	int index2 = 0;
	
	for(index = 0; index < 13; ++index) {
		for(index2 = 0; index2 < BRD_SQ_NUM; ++index2) {
			pos->searchHistory[index][index2] = 0;
		}
	}
	
	for(index = 0; index < 2; ++index) {
		for(index2 = 0; index2 < MAXDEPTH; ++index2) {
			pos->searchKillers[index][index2] = 0;
		}
	}	
	
	ClearPvTable(pos->PvTable);	
	pos->ply = 0;
	
	info->starttime = GetTimeMs();
	info->stopped = 0;
	info->nodes = 0;
	info->fh = 0;
	info->fhf = 0;
}

static int Quiescence(int alpha, int beta, S_BOARD *pos, S_SEARCHINFO *info) {
	return 0;
}

static int AlphaBeta(int alpha, int beta, int depth, S_BOARD *pos, S_SEARCHINFO *info, int DoNull) {

	ASSERT(CheckBoard(pos)); 
	
	if(depth == 0) {
		info->nodes++;
		return EvalPosition(pos);
	}
	
	info->nodes++;
	
	if(IsRepetition(pos) || pos->fiftyMove >= 100) {
		return 0;
	}
	
	if(pos->ply > MAXDEPTH - 1) {
		return EvalPosition(pos);
	}
	
	S_MOVELIST list[1];
    GenerateAllMoves(pos,list);
      
    int MoveNum = 0;
	int Legal = 0;
	int OldAlpha = alpha;
	int BestMove = NOMOVE;
	int Score = -INFINITE;
	
	for(MoveNum = 0; MoveNum < list->count; ++MoveNum) {	
       
        if ( !MakeMove(pos,list->moves[MoveNum].move))  {
            continue;
        }
        
		Legal++;
		Score = -AlphaBeta( -beta, -alpha, depth-1, pos, info, TRUE);		
        TakeMove(pos);
		
		if(Score > alpha) {
			if(Score >= beta) {
				if(Legal==1) {
					info->fhf++;
				}
				info->fh++;				
				return beta;
			}
			alpha = Score;
			BestMove = list->moves[MoveNum].move;
		}		
    }
	
	if(Legal == 0) {
		if(SqAttacked(pos->KingSq[pos->side],pos->side^1,pos)) {
			return -MATE + pos->ply;
		} else {
			return 0;
		}
	}
	
	if(alpha != OldAlpha) {
		StorePvMove(pos, BestMove);
	}
	
	return alpha;
} 

void SearchPosition(S_BOARD *pos, S_SEARCHINFO *info) {
	
	int bestMove = NOMOVE;
	int bestScore = -INFINITE;
	int currentDepth = 0;
	int pvMoves = 0;
	int pvNum = 0;
	
	ClearForSearch(pos,info);
	
	// iterative deepening
	for( currentDepth = 1; currentDepth <= info->depth; ++currentDepth ) {
							// alpha	 beta
		bestScore = AlphaBeta(-INFINITE, INFINITE, currentDepth, pos, info, TRUE);
		
		// out of time?
		
		pvMoves = GetPvLine(currentDepth, pos);
		bestMove = pos->PvArray[0];
		
		printf("Depth:%d score:%d move:%s nodes:%ld ",
			currentDepth,bestScore,PrMove(bestMove),info->nodes);
			
		pvMoves = GetPvLine(currentDepth, pos);	
		printf("pv");		
		for(pvNum = 0; pvNum < pvMoves; ++pvNum) {
			printf(" %s",PrMove(pos->PvArray[pvNum]));
		}
		printf("\n");
		printf("Ordering:%.2f\n",(info->fhf/info->fh));
	}
	
	
}




















