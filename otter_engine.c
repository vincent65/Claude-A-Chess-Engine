#include "stdio.h"
#include "defs.h"
#include "stdlib.h"

#define FEN_1 "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define FEN_2 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN_3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN_4 "1k1q1r1r/pbp2p1p/1pn2n2/2bpp1pQ/3PPB2/N1P2N2/PP3PPP/R3KB1R w KQkq - 0 1"
int main() {
    AllInit();
    
    S_BOARD board[1];

    ParseFen(FEN_4, board);
    PrintBoard(board);
    printf("\nwP:\n");
    
    ASSERT(CheckBoard(board));

    // ParseFen(START_FEN, board);
    // PrintBoard(board);

    // ParseFen(FEN_1, board);
    // PrintBoard(board);
    
    // ParseFen(FEN_2, board);
    // PrintBoard(board);
    
    // ParseFen(FEN_3, board);
    // PrintBoard(board);
    
    return 0;
}