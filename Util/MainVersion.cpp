#include "MainVersion.h"

using namespace std;

MainVersion::MainVersion()
{
    value = NULL;
    index = 0;
}

MainVersion::MainVersion(char* _str, const unsigned long _len)
{
	if (value != NULL)
		delete value;
	value = new Bstr();
	//value->copy(_str, _len);
	value->setStr(_str);
	value->setLen(_len);
}


void
MainVersion::setBstr(const Bstr* _value)
{
	if (value != NULL)
		delete value;
	value = new Bstr(*_value);
}

void
MainVersion::setBstr(char *_str, unsigned long _len)
{
	if (value != NULL)
		delete value;
	value = new Bstr();
	//value->copy(_str, _len);
	value->setStr(_str);
	value->setLen(_len);
}

bool
MainVersion::getBstr(char *& _str, unsigned long &_len, bool if_copy) const
{
	if (value == NULL)
	{
		_str = NULL;
		_len = 0;
		return false;
	}

	if (if_copy)
	{
		char *str = value->getStr();
		_len = value->getLen();
		_str = new char [_len];
		memcpy(_str, str, _len);
	}
	else
	{
		_str = value->getStr();
		_len = value->getLen();
	}
	return true;
}

//get exclusive latch
bool
MainVersion::getExclusiveLatch()
{
    return latch.tryLockExclusive();
}

//release exclusive latch
bool
MainVersion::releaseExclusiveLatch()
{
    return latch.unlock();
}