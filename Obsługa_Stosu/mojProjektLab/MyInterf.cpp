#include "MyInterf.h"

void MyMenu()
{
	int ops;
	MY_STACK* stack = CreateStack();

	while (1)
	{
		ChooseFunction();
		scanf_s("%d", &ops);

		switch (ops)
		{
		case 0:			
			AddObject(stack);
			break;
		case 1:
			PrintAllObjects(stack);
			break;
		case 2:
			SaveToDisk(stack);
			break;
		case 3:
			stack = ReadFromDisk(stack);
			break;
		case 4:
			PrintPopStudent(stack);
			break;
		case 5:
			PrintClearStudent(stack);
			break;
		case 6:
			PrintTopStudent(stack);
			break;
		case 7:
			PrintStudentBySurname(stack);
			break;
		case 8:
			PrintIsEmpty(stack);
			break;
		case 9:
			MyExit(stack);
			break;
		default:
			UnknownOperation();
		};
	}
}

void AddObject(MY_STACK* stack)
{
	int kierunek;
	Student* s = (Student*)malloc(sizeof(Student));
	if (!s)
	{
		MemoryAllocationError();
		return;
	}

	StudentInput(s);
	stack->push(s);

}

void PrintIsEmpty(MY_STACK* stack)
{
	if (stack->empty())
		StackIsEmpty();
	else
		StackIsNotEmpty();
}

void PrintAllObjects(MY_STACK* stack)
{
	stack->print();
}

void PrintPopStudent(MY_STACK* stack)
{
	Student* s = stack->pop();

	if (s == NULL)
		StackPopFail();
	else
	{
		StackPop();
		StudentPrint(s);
	}
}

void PrintClearStudent(MY_STACK* stack)
{
	stack->clear();
	StackClearSuccess();
}

void PrintTopStudent(MY_STACK* stack)
{
	Student* s = stack->top();

	if (s == NULL)
		StackTopFail();
	else
		StudentPrint(s);

}

void PrintStudentBySurname(MY_STACK* stack)
{
	TypeSurname();
	getchar();
	char* nazwisko = ReadStringDynamic();

	Student* s = stack->search(nazwisko);
	if (s == NULL)
		TypeSurnameFail();
	else
		StudentPrint(s);
}

void SaveToDisk(MY_STACK* stack)
{
	if (!SaveStack(stack))
		ErrorDuringWriteToFile();
}

MY_STACK* ReadFromDisk(MY_STACK* stack)
{
	if (!ReadStack(stack))
		ErrorDuringReadToFile();
	return stack;
}

void MyExit(MY_STACK* stack)
{
	Quit();
	FreeStack(stack);
	system("pause");
	exit(1);
}

void MyInterfDealloc(void* ptr)
{
	if (ptr)
		free(ptr);
}