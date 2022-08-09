#include "defs.h"
#include "stdio.h"

void AddQuietMove(const S_BOARD *pos, int move, S_MOVELIST *list) {
  list->moves[list->count].move = move;
  list->moves[list->count].score = 0;
  list->count = 0;
}

void AddCaptureMove(const S_BOARD *pos, int move, S_MOVELIST *list) {
  list->moves[list->count].move = move;
  list->moves[list->count].score = 0;
  list->count = 0;
}

void AddEnPassantMove(const S_BOARD *pos, int move, S_MOVELIST *list) {
  list->moves[list->count].move = move;
  list->moves[list->count].score = 0;
  list->count = 0;
}

void GenerateAllMoves(const S_BOARD *pos, S_MOVELIST *list) {
  list->count = 0;
  
}