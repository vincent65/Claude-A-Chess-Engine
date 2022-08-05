#include "defs.h"

int Sq120toSq64[BRD_SQ_NUM];
int Sq64toSq120[64];

//called at start of game
//setup game

void InitSq120To64() {
    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;

    for(index = 0; index < BRD_SQ_NUM; ++index){
        Sq120toSq64[index] = 65;
    }
    for(index = 0; index < 64; ++index){
        Sq64toSq120[index] = 120;
    }

    for (rank = RANK_1; rank <= RANK_8; ++rank) {
        for(file = FILE_A; file <= FILE_H; ++file){
            sq = FR2SQ(file, rank);
            Sq64toSq120[sq64] = sq;
            Sq120toSq64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit(){
    InitSq120To64();
}