#include "stdio.h"
#include "defs.h"

int main() {
    AllInit();
    //print to check
    for(int index = 0; index < BRD_SQ_NUM; ++index){
        if (index % 10 == 0) printf("\n");
        printf("%5d", Sq120toSq64[index]);
    }
    printf("\n");
    printf("\n");

    for(int index = 0; index < 64; ++index) {
        if(index%8 == 0) printf("\n");
        printf("%5d", Sq64toSq120[index]);
    }
    return 0;
}