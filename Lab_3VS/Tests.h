#ifndef __TESTS_H__
#define __TESTS_H__
#include <iostream>
#include <cassert>
#include "StringList.h"
using namespace std;

void checkSplice(void);

void checkUnique(void);

void AllTests(void) {
    try
    {
        StringList lst;
        lst.AddHead("world. ");
        lst.AddHead("hello ");
        lst.AddTail("I'm your father. ");
        lst.SetAt("Linus Torvalds made a new commit!!! ", 1);
        lst.InsertBefore("Now u're gonna die! ", 0);
        StringList lst2;
        lst2.AddHead("world. ");
        lst2.AddHead("hello ");
        lst2.AddTail("I'm your father. ");
        lst2.SetAt("Linus Torvalds made a new commit!!! ", 1);
        lst2.InsertBefore("Now u're gonna die! ", 0);

        cout << (lst == lst2);

        checkUnique();
        checkSplice();
        lst2.AppendExclusively(lst);
        lst2.InsertAfter("Insert after test. ", lst2.GetSize() - 1);
        cout << endl << endl;
        for (const ListNode* p = lst2.GetHead(); p != nullptr; p = p->GetNext()) {
            p->PrintNode();
        }
        cout << endl << endl;
        lst2.RemoveTail();
        cout << endl;
        lst2.Find("world. ")->PrintNode();
        cout << endl;
        for (ListNode* p = lst2.GetHead(); p != nullptr; p = p->next) {
            p->PrintNode();
        }
        
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

#endif // !__TESTS_H__
