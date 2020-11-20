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
			size--;
		}
        else {
            delete head;
            head = nullptr;
            size--;
        }
    }
    else
		throw runtime_error("Error : RemoveHead() head does not exist. \n");
}

//Gets the element at a given position.
const char* StringList::GetAt(size_t id)const {
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
        }
        size++;
        head->data = str;
    }
    else {
        ListNode* tmp = new ListNode;
        if (!tmp) {
            throw runtime_error("Error : Allocanion error AddHead. \n");
        }
        tmp->next = head;
        tmp->next->prev = tmp;
        tmp->data = str;
        head = tmp;
        size++;
    }
}

void StringList::AddHead(const StringList* sl) {
    if (sl->IsEmpty())
        throw runtime_error("Error : AddHead() adding empty list. \n");
	for (size_t i = 0; i < sl->Getsize(); i++) {
		AddHead(sl->GetAt(sl->Getsize() - 1 - i));
	}
}






int main() {
    try
    {
        StringList lst;
        StringList lst2;
        lst2.AddHead("world");
        lst2.AddHead("hello ");
        lst.AddHead(&lst2);
        cout << lst.GetAt(0) << lst.GetAt(1) << endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}