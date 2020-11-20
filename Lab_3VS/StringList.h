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
#include <malloc.h>


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
        data = (char*)malloc(size + 1);
        if (!data) {
            throw std::runtime_error("Error : String memory allocation error \n");
        }
    }

    String& operator=(const char* str)
    {
        if(data)
			delete data;
        size = strlen(str);
        data = (char*)malloc(size + 1);
        return *this;
    }

    ~String() {
        std::cout << "String Destructon \n";
        free(data);
    }

    size_t length(void) const {
        return size;
    }
private:
    char* data;
    size_t size;
};

struct ListNode {
    String data = "";
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
    //Head/Tail Access
    const ListNode* GetHead();//Returns the head element of the list
    const ListNode* GetTail();//Returns the tail element of the list

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
    const char* GetAt(int)const;

    //Removes an element from this list as specified by position.
    void RemoveAt(int);

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
    int Getsize()const;

    //Tests for the empty list condition (no elements).
    bool IsEmpty()const;
    void Printnode(const ListNode* p);

};

#endif //!__STRINGLIST_H__