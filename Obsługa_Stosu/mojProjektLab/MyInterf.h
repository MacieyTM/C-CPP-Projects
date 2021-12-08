#pragma once

#include "MyErrorAndCom.h"
#include "MyStack.h"

void MyMenu();

void AddObject(MY_STACK* stack);
void PrintIsEmpty(MY_STACK* stack);
void PrintPopStudent(MY_STACK* stack);
void PrintClearStudent(MY_STACK* stack);
void PrintTopStudent(MY_STACK* stack);
void PrintStudentBySurname(MY_STACK* stack);
void PrintAllObjects(MY_STACK* stack);
void MyExit(MY_STACK* stack);
void MyInterfDealloc(void* ptr);

void SaveToDisk(MY_STACK* stack);
MY_STACK* ReadFromDisk(MY_STACK* stack);