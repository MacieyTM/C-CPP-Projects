#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "windows.h"

enum Kierunek
{
	INFORMATYKA,
	MATEMATYKA,
	FIZYKA,
	MECHANIKA
};

struct Student
{
	char *nazwisko;
	int rok;
	Kierunek kierunek;
};

char* ReadStringDynamic();

void StudentPrint(void* pdata);
void StudentInput(Student* ptr);
void StudentFree(void** pTr);

bool StudentSave(void** pdat, FILE* pf);
bool StudentRead(void** pdat, FILE* pf);