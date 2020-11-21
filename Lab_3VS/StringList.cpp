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

void StringList::AddHead(const StringList* sl) {
    if (sl->IsEmpty()) {
        throw runtime_error("Error : AddHead() adding empty list. \n");
        return;
    }
	for (size_t i = 0; i < sl->size; i++)
		AddHead(sl->GetAt(sl->size - 1 - i));
}

void StringList::PrintNode(const ListNode* node)
{
    if (!node) {
        throw runtime_error("Error : PrintNode node does not exist. \n");
        return;
    }
    cout << node->data;
}

//Adds an element to the tail of the list (makes a new tail).
void StringList::AddTail(const char* str) {
    if (!IsEmpty())
    {
        ListNode* tmp = head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new ListNode(str);
        tmp->next->prev = tmp;
        size++;
    }
    else
        AddHead(str);
}

//Adds all the elements in another list to the tail of the list (makes a new tail).
void StringList::AddTail(const StringList* sl) {
    for (size_t i = 0; i < sl->size; i++) {
        AddTail(sl->GetAt(i));
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
size_t StringList::FindIndex(const char* str)const {
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
StringList::POSITION StringList::Find(const char* str) {
    if (!IsEmpty())
    {
        ListNode *tmp = head;
        for (size_t i = 0; i < size; i++)
        {
            if (!strcmp(GetAt(i), str))
                return tmp;
			tmp = tmp->next;
        }
		throw runtime_error("Error : Find() element does not exist. \n");
    }
    throw runtime_error("Error : Find() StringList is empty \n");
}

//Sets the element at a given position.
void StringList::SetAt(const char* str, const size_t id) {
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
        throw runtime_error("Error : SetAt() out of StringList range. \n");
}




int main() {
    try
    {
        StringList lst2;
        lst2.AddHead("world. ");
        lst2.AddHead("hello ");
        lst2.AddTail("I'm your father. ");
        lst2.SetAt("Now u're gonna die! ", 1);
        for (ListNode* p = lst2.GetHead(); p != nullptr; p = p->next)
        {
            lst2.PrintNode(p);
        }
        cout << endl << endl;
        lst2.RemoveTail();
        lst2.PrintNode(lst2.Find("world. "));
        for (ListNode* p = lst2.GetHead(); p != nullptr; p = p->next)
        {
            lst2.PrintNode(p);
        }
        
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}