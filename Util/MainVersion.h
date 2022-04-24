#ifndef _UTIL_MVERSION_H
#define _UTIL_MVERSION_H


#include <pthread.h>
#include "Bstr.h"
#include "Latch.h"

using namespace std;

class MainVersion{
private:
    Bstr* value;
    uint index;
    Latch latch;
public:
	MainVersion();
    MainVersion(char* _value, unsigned long _len);
    void setBstr(const Bstr* _value);
	bool getBstr(char *& _str, unsigned long& _len, bool if_copy = true) const;
	void setBstr(char *_str, unsigned long _len);

    //get/release exclusive latch
    bool getExclusiveLatch();
    bool releaseExclusiveLatch();

    //create new MainVersion
//    MainVersion Create(const Bstr* _value, const unsigned long _len);
};

#endif
