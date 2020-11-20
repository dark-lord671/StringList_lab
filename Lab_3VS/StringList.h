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
    }

    operator char* () { return data; }

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
        std::cout << "String Destructor \n";
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
    String data;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
};

class StringList {
    // typedef const ListNode* POSITION;
    using POSITION = ListNode*;
private:
    //put your own data members here
    size_t size;
    ListNode* head;
public:
    // Construct an empry list for ListNode objs.
    StringList(void);
    ~StringList();

    ListNode& operator[](const size_t id) {
        ListNode* tmp = head;
        for (size_t i = 0; i < id; i++)
            tmp = tmp->next;
        return *tmp;
    }
    
    //Head/Tail Access
	//Returns the head element of the list
    const ListNode* GetHead() { return head; }
    //Returns the tail element of the list
    const ListNode* GetTail() {
        ListNode* tmp = head; 
        while (tmp->next) { 
            tmp = tmp->next; 
        } 
        return tmp; 
    }

    //Operations
    //Adds an element to the head of the list (makes a new head).
    void AddHead(const char*);

    //Adds all the elements in another list to the head of the list (makes a new head).
    void AddHead(const StringList*);

    //Adds an element to the tail of the list (makes a new tail).
    void AddTail(const char*);

    //Adds all the elements in another list to the tail of the list (makes a new tail).
    void AddTail(const StringList*);

    //Removes all the elements from this list.
    void RemoveAll();

    //Removes the element from the head of the list.
    void RemoveHead();

    //Removes the element from the tail of the list.
    void RemoveTail();
    void AppendExclusively(const StringList*);
    void Splice(POSITION where, StringList* sl, POSITION first, POSITION last);

    //removes all duplicate elements
    void Unique();

    //Iteration
    //Gets the next element for iterating.
    POSITION GetNext();

    //Gets the previous element for iterating.
    POSITION GetPrev();

    //Retrieval/Modification
    POSITION GetHeadPosition();

    //Gets the element at a given position.
    const char* GetAt(size_t)const;

    //Removes an element from this list as specified by position.
    void RemoveAt(size_t);

    //Sets the element at a given position.
    void SetAt(char*, int);

    //Insertion
    //Inserts a new element after a given position.
    void InsertAfter(char*, int);

    //Inserts a new element before a given position.
    void InsertBefore(char*, int);

    //Searching
    //Gets the position of an element specified by string value.
    const ListNode* Find(char*);

    //Gets the position of an element specified by a zero-based index.
    int FindIndex(char*)const;

    //Status
    //Returns the number of elements in this list.
    size_t Getsize()const { return size; }

    //Tests for the empty list condition (no elements).
    bool IsEmpty()const { return !size; }
    void Printnode(const ListNode* p);

};

#endif //!__STRINGLIST_H__