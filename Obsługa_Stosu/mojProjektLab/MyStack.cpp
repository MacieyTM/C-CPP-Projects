#include "MyStack.h"

#pragma warning (disable : 4996)

const char MyFileName[] = "PlikDoProjektu.bin";

MY_STACK* CreateStack()
{
	MY_STACK* stack = (MY_STACK*)malloc(sizeof(MY_STACK));
	stack->top_elem = NULL;
	return stack;
}

void FreeStack(MY_STACK* stack) 
{
	stack->clear();
	free(stack);
	stack = NULL;
}

bool SaveStack(MY_STACK* stack)
{
	FILE* pf = fopen(MyFileName, "wb");
	if (!pf)
		return false;


	for (MY_ELEM* temp = stack->top_elem; temp != NULL; temp = temp->prev)
		StudentSave((void**)&(temp->student),pf);

	fclose(pf);
	return true;
}

bool ReadStack(MY_STACK* stack)
{	
	FILE* pf = fopen(MyFileName, "rb");
	if (!pf)
		return false;
	
	stack->clear();
	MY_STACK* stack_helper = CreateStack();

	char c;
	while((c = fgetc(pf)) != EOF)
	{
		ungetc(c, pf);
		Student* s = (Student*)malloc(sizeof(Student));
		bool success = StudentRead((void**)&s, pf);

		if (!success)
			return false;

		stack_helper->push(s);	
	}

	while (!stack_helper->empty())
		stack->push( stack_helper->pop() );

	FreeStack(stack_helper);

	fclose(pf);
	return true;
}

Student* MY_STACK::pop()
{
	if (empty())
		return NULL;

	Student* res = top();

	if (top_elem->prev == NULL)
	{
		free(top_elem);
		top_elem = NULL;
	}

	else 
	{
		MY_ELEM* e = top_elem;
		top_elem = top_elem->prev;
		free(e);
		e = NULL;
	}

	return res;
}

void MY_STACK::clear()
{
	while (!empty()) {
		pop();
	}
}

bool MY_STACK::empty()
{
	return top_elem == NULL;
}

Student* MY_STACK::top()
{
	if (empty())
		return NULL;
	else
		return top_elem->student;
}

void MY_STACK::push(Student* s)
{
	MY_ELEM* e = (MY_ELEM*)malloc(sizeof(MY_ELEM));

	e->student = s;
	e->prev = top_elem;

	top_elem = e;
}

Student* MY_STACK::search(char* nazwisko)
{
	if (empty())
		return NULL;

	for (MY_ELEM* temp = top_elem; temp != NULL; temp = temp->prev)
	{
		if (strcmp(temp->student->nazwisko,nazwisko) == 0)
			return temp->student;
	}

	return NULL;
}

void MY_STACK::print()
{
	if (empty())
		return;

	for (MY_ELEM* temp = top_elem; temp != NULL; temp = temp->prev)
	{
		StudentPrint(temp->student);
	}

}