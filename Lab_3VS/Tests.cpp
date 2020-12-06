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
    {
		StringList lst1;
		StringList control_lst;
		/**/
		assert(lst1 == control_lst);
    }
    {
		StringList lst1;
		StringList control_lst;
		/**/
		assert(lst1 == control_lst);
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
    lst.Unique();
	cout << endl;
    for (ListNode* p = lst.GetHead(); p != nullptr; p = p->GetNext())
    {
        p->PrintNode();
        cout << " ";
    }
        cout << endl;
}
