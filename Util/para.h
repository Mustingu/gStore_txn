#ifndef Para_H
#define Para_H

#include<atomic>

using namespace std;

//IVEntry
extern std::atomic<int> IVEntry_ex[11], IVEntry_sh[11];
extern std::atomic<int> Entry_ex, Entry_sh;


//IVArray
extern std::atomic<int> IVArray_ex[11], IVArray_sh[11];
extern std::atomic<int> Array_ex, Array_sh;


//Database
extern std::atomic<int> Database_insert[11], Database_insertT[11];
extern std::atomic<int> IR, IRT;
extern std::atomic<int> Time1, Time2;

extern std::atomic<int> DB_query[11];
extern std::atomic<int> dbquery;

//StringIndex
extern std::atomic<int> StringIndex1[11];
extern std::atomic<int> SI;

//KVStore
extern std::atomic<int> KVs;
extern std::atomic<int> GVBK[11];
#endif