#pragma once

#include "MyStudent.h"

struct MY_ELEM
{
	Student* student;
	MY_ELEM* prev;
};

struct MY_STACK
{
	MY_ELEM* top_elem;

	Student* pop();
	void clear();
	bool empty();
	Student* top();
	void push(Student* s);

	Student* search(char* nazwisko);
	void print();
};

MY_STACK* CreateStack();
void FreeStack(MY_STACK* stack);

bool SaveStack(MY_STACK* stack);
bool ReadStack(MY_STACK* stack);