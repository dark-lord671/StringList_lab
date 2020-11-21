/*
 * file: StringList.h
 * StringList class declaration
 * created: 19/11/2020
 * last changes: xx/xx/xxxx
 * Copyright (c) by Orydoroha Mykhailo
 */

#ifndef __STRINGLIST_H__
#define __STRINGLIST_H__

#include <iostream>
#include <string.h>


class String {
public:
    String(void)
    {
        size = 0;
        data = nullptr;
    }

    String(const char* str)
    {
        size = strlen(str);
        data = new char[size + 1];
        if (!data) {
            throw std::runtime_error("Error : String memory allocation error \n");
        }
        for (size_t i = 0; i < strlen(str) + 1; i++)
            data[i] = str[i];
    }

    operator char* () {
        return !this ? nullptr : data;
    }

    //{ if(!this) return data; }

	friend std::ostream& operator<<(std::ostream& os, const String& str)
	{
        return os << str.data;
	}

    String& operator=(const char* str)
    {
        if(data)
			delete[] data;
        size = strlen(str);
        data = new char[size + 1];
        for (size_t i = 0; i < size + 1; i++)
            data[i] = str[i];
        return *this;
    }

    ~String() {
        std::cout << "\nString Destructor";
        delete[] data;
    }

    size_t length(void) const {
        return size;
    }
private:
    char* data = nullptr;
    size_t size = 0;
};

struct ListNode {
    ListNode() {}
    ListNode(const char* str)
    {
        data = str;
    }

    String data;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;

    void PrintNode();
};

class StringList {
private:
    //put your own data members here
    size_t size = 0;
    ListNode* head = nullptr;
    //const ListNode* current_element = nullptr;
public:
    using POSITION = ListNode *const;

    // Construct an empry list for ListNode objs.
    StringList(void);
    ~StringList();

    //Head/Tail Access
	//Returns the head element of the list
    POSITION GetHead() { return head; }
    //Returns the tail element of the list
    POSITION GetTail() {
        if (!IsEmpty()) {
			ListNode* tmp = head; 
			while (tmp->next) { 
				tmp = tmp->next; 
			} 
			return tmp; 
        }
            throw std::runtime_error("Error : GetTail() List is empty");
    }

    //Operations
    //Adds an element to the head of the list (makes a new head).
    void AddHead(const char*);

    //Adds all the elements in another list to the head of the list (makes a new head).
    void AddHead(const StringList&);

    //Adds an element to the tail of the list (makes a new tail).
    void AddTail(const char*);

    //Adds all the elements in another list to the tail of the list (makes a new tail).
    void AddTail(const StringList&);

    //Removes all the elements from this list.
    void RemoveAll() {
        while (size)
            RemoveHead();
    }

    //Removes the element from the head of the list.
    void RemoveHead();

    //Removes the element from the tail of the list.
    void RemoveTail();

    // Adds StringList* items to the tail of the list in addition to the existing ones
    void AppendExclusively(const StringList&);
    void Splice(POSITION where, StringList* sl, POSITION first, POSITION last);

    //removes all duplicate elements
    void Unique();

    //Iteration
    //Gets the next element for iterating.
    /*
    POSITION GetNext() {
        current_element ? current_element = current_element->next : current_element = head;
        return current_element;
    }

    //Gets the previous element for iterating.
    POSITION GetPrev() {
        current_element ? current_element = current_element->prev : current_element = GetTail();
        return current_element;
    }
	*/
    //Retrieval/Modification
    POSITION GetHeadPosition() { return head; }

    //Gets the element at a given position.
    const char* GetAt(size_t)const;

    //Removes an element from this list as specified by position.
    void RemoveAt(size_t);

    //Sets the element at a given position.
    void SetAt(const char*, const size_t);

    //Insertion
    //Inserts a new element after a given position.
    void InsertAfter(const char*, const size_t);

    //Inserts a new element before a given position.
    void InsertBefore(char*, int);

    //Searching
    //Gets the position of an element specified by string value.
    POSITION Find(const char*);

    //Gets the position of an element specified by a zero-based index.
    size_t FindIndex(const char*)const;

    //Status
    //Returns the number of elements in this list.
    size_t GetSize()const { return size; }

    //Tests for the empty list condition (no elements).
    bool IsEmpty()const { return !size; }

};

#endif //!__STRINGLIST_H__