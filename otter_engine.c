#include "stdio.h"
#include "defs.h"
#include "stdlib.h"

#define FEN_1 "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define FEN_2 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN_3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"

int main() {
    AllInit();
    
    S_BOARD board[1];

    ParseFen(START_FEN, board);
    PrintBoard(board);

    ParseFen(FEN_1, board);
    PrintBoard(board);
    
    ParseFen(FEN_2, board);
    PrintBoard(board);
    
    ParseFen(FEN_3, board);
    PrintBoard(board);
    
    return 0;
}