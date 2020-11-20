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
        this->RemoveHead();
    }
}

//Removes the element from the head of the list.
void StringList::RemoveHead(void)
{
    if (head)
    {
        ListNode* tmp = head->next;
        delete head;
        head = tmp;
        size--;
    }
}

//Adds an element to the head of the list (makes a new head).
void StringList::AddHead(const char* str)
{
    if (!head) {
        head = (ListNode*) malloc(sizeof(ListNode));
        if (!head) {
            throw runtime_error("Error : Allocanion error AddHead");
        }
        size++;
        head->data = str;
    }
    else {
        ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
        if (!tmp) {
            throw runtime_error("Error : Allocanion error AddHead");
        }
        tmp->next = head;
        tmp->next->prev = tmp;
        tmp->data = str;
        head = tmp;
    }
}







int main() {
    try
    {
        StringList lst;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}