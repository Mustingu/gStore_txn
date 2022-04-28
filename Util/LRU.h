#ifndef _UTIL_LRU_H
#define _UTIL_LRU_H

#include <memory>
#include "SpinLock.h"
#include "Util.h"
namespace LRU{

class ListNode
{
    private:
    unsigned _id;
    ListNode* _nxt;
    ListNode* _prv;

    public:
    void delink()
    {
        if(this->_nxt)
            this->_nxt->_prv = this->_prv;
        if(this->_prv)
            this->_prv->_nxt = this->_nxt;
        this->_nxt = this->_prv = nullptr;
    }

    void setnext(ListNode* nxt){
        this->_nxt = nxt;
    }

    void setprev(ListNode* prv){
        this->_prv = prv;
    }

    ListNode* getnext()
    {
        return this->_nxt;
    }

    ListNode* getprev()
    {
        return this->_prv;
    }

    unsigned getid() {
        return _id;
    }
    ListNode(unsigned id):_id(id), _prv(nullptr), _nxt(nullptr){}
    ListNode():_id(-1), _prv(nullptr), _nxt(nullptr){}
    ~ListNode()
    {
        delink();
    }
};

class LRUList
{
    public:
    LRUList(){
        _head = new ListNode();
        _tail = new ListNode();
        _head->setnext(_tail);
        _tail->setprev(_head);
    }
    ListNode* add(unsigned _id);
    void update(ListNode* p_lru_entry);
    unsigned evict();
    void remove(ListNode* p_lru_entry);
    ~LRUList() {clear();}

    private:
    ListNode* _head;
    ListNode* _tail;
    spinlock _mutex;
    void clear();
};

}
#endif
