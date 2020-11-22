#include "StringList.h"
using namespace std;

// Construct an empry list for ListNode objs.
StringList::StringList(void) {
    size = 0;
    head = nullptr;
}

// Delete a list
StringList::~StringList() {
    while (size)
    {
        RemoveHead();
    }
}

//Removes the element from the head of the list.
void StringList::RemoveHead(void) {
    if (head)
    {
        if (head->next) {
			ListNode* tmp = head->next;
			delete head;
			head = tmp;
			head->prev = nullptr;
		}
        else {
            delete head;
            head = nullptr;
        }
		size--;
    }
    else
		throw runtime_error("Error : RemoveHead() head does not exist. \n");
}

//Gets the element at a given position.
const char* StringList::GetAt(size_t id) const {
    if (id < size && id >= 0) {
		ListNode* tmp = head;
		for (size_t i = 0; i < id; i++) {
			tmp = tmp->next;
		}
		return tmp->data;
    }
    else
		throw runtime_error("Error : GetAt() element does not exist. \n");
}

//Adds an element to the head of the list (makes a new head).
void StringList::AddHead(const char* str) {
    if (!head) {
        head = new ListNode;
        if (!head) {
            throw runtime_error("Error : Allocanion error AddHead. \n");
            return;
        }
        size++;
        head->data = str;
    }
    else {
        ListNode* tmp = new ListNode;
        if (!tmp) {
            throw runtime_error("Error : Allocanion error AddHead. \n");
            return;
        }
        tmp->next = head;
        tmp->next->prev = tmp;
        tmp->data = str;
        head = tmp;
        size++;
    }
}

void StringList::AddHead(const StringList& sl) {
    if (sl.IsEmpty()) {
        throw runtime_error("Error : AddHead() adding empty list. \n");
        return;
    }
	for (size_t i = 0; i < sl.size; i++)
		AddHead(sl.GetAt(sl.size - 1 - i));
}

void ListNode::PrintNode() const
{
    if (!data)
        throw runtime_error("Error : PrintNode() node is empty. \n");
    else
		cout << data;
}

//Adds an element to the tail of the list (makes a new tail).
void StringList::AddTail(const char* str) {
    if (!IsEmpty())
    {
        ListNode* tmp = head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new ListNode(str);
        if (!tmp->next) {
            throw runtime_error("Error : Allocanion error AddHead. \n");
            return;
        }
        tmp->next->prev = tmp;
        size++;
    }
    else
        AddHead(str);
}

//Adds all the elements in another list to the tail of the list (makes a new tail).
void StringList::AddTail(const StringList& sl) {
		for (size_t i = 0; i < sl.size; i++) {
			AddTail(sl.GetAt(i));
		}
}

//Removes the element from the tail of the list.
void StringList::RemoveTail() {
    if (!IsEmpty()) {
        if (GetTail()->prev) {
			POSITION tmp = GetTail();
			tmp->prev->next = nullptr;
			delete tmp;
        }
        else {
            delete head;
            head = nullptr;
        }
			size--;
    }
    else
		throw runtime_error("Error : RemoveTail() StingList is empty. \n");
}

//Removes an element from this list as specified by position.
void StringList::RemoveAt(const size_t id) {
    if (id < size && id >= 0) {
		ListNode* tmp = head;
		for (size_t i = 0; i < id; i++) {
			tmp = tmp->next;
		}
        if (tmp->next) {
			// If the next element exists
            if (tmp->prev) {
                // If the next element and the previous element exists
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                delete tmp;
                size--;
            }
            else {
                // If the next element exists but the previous does not exist
                RemoveHead();
            }

        }
        else {
			// If the next element does not exist
            RemoveTail();
        }
    }
    else
		throw runtime_error("Error : RemoveAt() element does not exist. \n");
}

//Gets the position of an element specified by a zero-based index.
size_t StringList::FindIndex(const char* str) const {
    if (!IsEmpty()) {
		size_t id = 0;
		ListNode* tmp = head;
		while (tmp) {
			if (!strcmp(tmp->data, str))
				return id;
			tmp = tmp->next;
			id++;
		}
    }
    throw runtime_error("Error : FindIndex() element not found");
}

//Gets the position of an element specified by string value.
StringList::POSITION StringList::Find(const char* str) const {
    if (!IsEmpty())
    {
        ListNode *tmp = head;
        for (size_t i = 0; i < size; i++)
        {
            if (!strcmp(GetAt(i), str))
                return tmp;
			tmp = tmp->next;
        }
		//throw runtime_error("Error : Find() element does not exist. \n");
    }
    //throw runtime_error("Error : Find() StringList is empty \n");
	return nullptr;
}

//Sets the element data to str at a given position.
void StringList::SetAt(const char* str, const size_t id) {
    if (id < size && id >= 0) {
        ListNode* tmp = head;
        for (size_t i = 0; i < id; i++) {
            tmp = tmp->next;
        }
        tmp->data = str;
    }
    else
        throw runtime_error("Error : SetAt() element on id does not exist. \n");
}

//Inserts a new element after a given position.
void StringList::InsertAfter(const char* str, const size_t id) {
    if (id < size && id >= 0) {
        ListNode* tmp = head;
        for (size_t i = 0; i < id; i++) {
            tmp = tmp->next;
        }
        if (tmp->next)
            InsertBefore(str, id + 1);
        else
            AddTail(str);
    }
    else
        throw runtime_error("Error : InserAfter() element on id does not exist. \n");
}

// Inserts a new element before a given position.
void StringList::InsertBefore(const char* str, const size_t id) {
    if (id < size && id >= 0) {
        ListNode* tmp = head;
        for (size_t i = 0; i < id; i++) {
            tmp = tmp->next;
        }
        if (tmp->next) {
			// If the next element exists
            if (tmp->prev) {
                // If the next element and the previous element exists
                ListNode* NewNode = new ListNode(str);
                if (!NewNode) {
					throw runtime_error("Error : InseerBefore() Allocanion error. \n");
					return;
                }
                tmp->prev->next = NewNode;
                NewNode->next = tmp;
                NewNode->prev = tmp->prev;
                tmp->prev = NewNode;
                size++;
            }
            else {
                // If the next element exists but the previous does not exist
                AddHead(str);
            }

        }
        else {
			// If the next element does not exist
            AddTail(str);
        }
    }
    else
        throw runtime_error("Error : InsertBefore() out of StringList range. \n");
}

// Adds StringList items to the tail of the list in addition to the existing ones
void StringList::AppendExclusively(const StringList& sl) {
    if (!IsEmpty())
    {
        for (size_t i = 0; i < sl.size; i++)
        {
			if (!Find(sl.GetAt(sl.size - 1 - i)))
                AddTail(sl.GetAt(sl.size - 1 - i));
        }
    }
    else
        AddTail(sl);
}

// Removes elements from the StringList from first to last
//      and inserts them into the current list, starting from the position where.
void StringList::Splice(POSITION where, StringList& sl, POSITION first, POSITION last) {
    if (!where)
        throw runtime_error("Error : Splice() where is nullptr. \n");
    if (!first)
        throw runtime_error("Error : Splice() first is nullptr. \n");
    if (!last)
        throw runtime_error("Error : Splice() last is nullptr. \n");
    bool flag = false;
    ListNode* tmp = first;
    while (tmp) {
        if (tmp == last) {
            flag = true;
            break;
        }
        tmp = tmp->next;
    }
    if (flag) {
        ListNode* pastepos = where;
        tmp = first;
        while (tmp) {
            InsertAfter(tmp->data, FindIndex(pastepos->data));
            pastepos = pastepos->next;
            tmp = tmp->next;
            sl.RemoveAt(sl.FindIndex(pastepos->data));
        }
    }
    else {
        throw runtime_error("Error : Splice() can't get from first to last. \n");
    }
}

// Removes all duplicate elements
void StringList::Unique() {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < i; j++) {
            if (!strcmp(GetAt(i), GetAt(j))) {
                RemoveAt(i--);
                break;
            }
        }
    }
}

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

void checkUnique(void) {
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
int main() {
    try
    {
        checkUnique();
        checkSplice();
        StringList lst2;
        lst2.AddHead("world. ");
        lst2.AddHead("hello ");
        lst2.AddTail("I'm your father. ");
        lst2.SetAt("Linus Torvalds made a new commit!!! ", 1);
        lst2.InsertBefore("Now u're gonna die! ", 0);
        StringList lst;
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


    return 0;
}