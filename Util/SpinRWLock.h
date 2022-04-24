#ifndef _UTIL_SPINRWLOCK_H
#define _UTIL_SPINRWLOCK_H


#include <atomic>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

const ull XLOCKED = ((ull)1 << 63) + 1;
const ull XBIT_MASK = ((ull)1 << 63);
const ull RCNT_MASK = ~(XBIT_MASK);

struct spinrwlock
{
    //exclusive flag(1bit) + readcount(31bit)
    //2^31 reader max
    std::atomic<ull> lock_ = {0};

    spinrwlock()
    {
        lock_.store(0);
    }

    bool tryexclusivelock(){
        ull expect = 0;
        ull set = XLOCKED;
        return lock_.compare_exchange_strong(expect, set);
    }

    void lockExclusive(){
        ull expect = 0;
        ull set = XLOCKED;
        while(!lock_.compare_exchange_strong(expect, set));
    }

    bool trysharedlock(){
        ull t = lock_.load();
        if((t & XBIT_MASK)  == 0){
            return lock_.compare_exchange_strong(t, t+1);
        } 
        return false;
    }

    void lockShared(){
        while(true){
            ull t = lock_.load();
            if((t & XBIT_MASK) == 0){ //unlocked
                //increament maybe failed
                if(lock_.compare_exchange_strong(t, t+1)) return;
            }
        }
    }

    bool unlock(bool type)
    {
        if(type == true)
        {
            ull set = 0;
            ull expect = XLOCKED;
            bool ret = lock_.compare_exchange_strong(expect, set);
            if(ret == false) {
                cerr << "lock_.load()" << lock_.load() << "  exclusive spin unlatch failed" << endl;
            }
            return ret;
        }
        else
        {
            while(true){
                ull t = lock_.load();
                //xlocked or rnt is zero
                if((t & XBIT_MASK) == XBIT_MASK || t == 0){
                    cerr << "xlocked or rnt is zero" << endl;
                    return false;
                }
                //decrement maybe failed
                if(lock_.compare_exchange_strong(t, t-1)) return true;
            }
        }
    }
    //must use after shared locked 
    bool tryupgradelock()
    {
        ull set = XLOCKED;
        ull expect = 1;
        return lock_.compare_exchange_strong(expect, set);
    }
    //must use after exclusive locked
    bool trydowngradelock()
    {
        ull expect = XLOCKED;
        ull set = 1;
        return lock_.compare_exchange_strong(expect, set);
    }
};
#endif