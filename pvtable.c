
#include "defs.h"
#include "stdio.h"

const int PvSize = 0x100000 * 2;


static void ClearPvTable(S_PVTABLE *table) {
    S_PVENTRY *pvEntry;

    for(pvEntry = table->pTable; pvEntry < table->pTable + table->numEntries; pvEntry ++) {
        pvEntry->move = 0;
        pvEntry->posKey = 0;
    }
}

void InitPvTable(S_PVTABLE * table) {
    table->numEntries = PvSize / sizeof(S_PVENTRY);
    table->numEntries -= 2;
    
    free(table->pTable);
    table->pTable = (S_PVENTRY *) malloc(table->numEntries * sizeof(S_PVENTRY));
    ClearPvTable(table);
    printf("PvTable init is Complete with %d entries\n", table->numEntries);
}