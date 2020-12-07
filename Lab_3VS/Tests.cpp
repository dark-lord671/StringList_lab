#include "Tests.h"
using namespace std;

void checkSplice(void) {
    StringList lst;
    lst.AddHead("one");
    lst.AddTail("two");
    lst.AddTail("three");
    lst.AddTail("four");
    lst.AddTail("five");
    StringList lst2;
    lst2.AddTail("check this out");
    lst2.Splice(lst2.GetHead(), lst, lst.GetHead(), lst.GetTail());
    cout << "lst: \n";
    for (ListNode* p = lst.GetHead(); p != nullptr; p = p->GetNext()) {
        p->PrintNode();
        cout << " "; 
    }
	cout << endl << endl; 
    cout << "lst2: \n";
    for (ListNode* p = lst2.GetHead(); p != nullptr; p = p->GetNext()) {
        p->PrintNode();
        cout << " "; 
    }
}

void checkUnique(void)
 {
    StringList lst;
    lst.AddTail("one");
    lst.AddTail("2");
    lst.AddHead("one");
    lst.AddTail("one");
    lst.AddTail("one");
    lst.AddTail("1");
    lst.AddHead("2");
    lst.AddTail("3");
    lst.AddTail("4");
    lst.InsertAfter("one", 7);
    lst.InsertBefore("one", 3);
    lst.Unique();
	cout << endl;
    for (ListNode* p = lst.GetHead(); p != nullptr; p = p->GetNext())
    {
        p->PrintNode();
        cout << " ";
    }
        cout << endl;
}

void AllTests(void) {
    try
    {
        StringList lst;
        lst.AddHead("first. ");
        lst.AddHead("second ");
        lst.AddTail("third. ");
        lst.SetAt("fourth ", 1);
        lst.InsertBefore("zero ", 0);
        StringList lst2;
        lst2.AddHead("first. ");
        lst2.AddHead("second ");
        lst2.AddTail("third. ");
        lst2.SetAt("fourth ", 1);
        lst2.InsertBefore("zero ", 0);

        cout << (lst == lst2);

        checkUnique();
        checkSplice();
        lst2.AppendExclusively(lst);
        lst2.InsertAfter("Last. ", lst2.GetSize() - 1);
        cout << endl << endl;
        for (const ListNode* p = lst2.GetHead(); p != nullptr; p = p->GetNext()) {
            p->PrintNode();
        }
        cout << endl << endl;
        lst2.RemoveTail();
        cout << endl;
        lst2.Find("first. ")->PrintNode();
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
