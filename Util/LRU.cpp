#include "LRU.h"

using namespace LRU;

ListNode* LRUList::add(unsigned _id)
{
    if(_id == -1) return nullptr;
    ListNode* pnode = new ListNode(_id);
    update(pnode);
    return pnode;
}

void LRUList::update(ListNode* p_lru_entry)
{
    if(!p_lru_entry) return;
    _mutex.lock();
    p_lru_entry->delink();
    p_lru_entry->setnext(_head->getnext());
    _head->getnext()->setprev(p_lru_entry);
    _head->setnext(p_lru_entry);
    p_lru_entry->setprev(_head);
    _mutex.unlock();
}

unsigned LRUList::evict()
{
    
    _mutex.lock();
    ListNode *tmp = _tail->getprev();
    unsigned ret = tmp->getid();
    tmp->delink();
    _mutex.unlock();
    return ret;
}

void LRUList::clear()
{
    ListNode* p = _head->getnext();
    while(p && p != _tail)
    {
        _head->setnext(p->getnext());
        delete p;
        p = _head->getnext();
    }
    delete _head;
    delete _tail;
}

void LRUList::remove(ListNode* p_lru_entry)
{
    if(p_lru_entry == nullptr) return;
    _mutex.lock();
    p_lru_entry->delink();
    _mutex.unlock();
}