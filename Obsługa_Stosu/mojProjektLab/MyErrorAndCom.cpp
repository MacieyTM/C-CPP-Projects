#include "MyErrorAndCom.h"
#include <stdio.h>

void ChooseFunction()
{
	printf("0 - Push, 1 - Print, 2 - Save, 3 - Read, 4 - Pop, 5 - Clear, 6 - Top, 7 - Search, 8 - CheckIfStackIsEmpty, 9 - Quit\n");
}

void UnknownOperation()
{
	printf("Nie ma takiego numeru\n");
}

void MemoryAllocationError()
{
	printf("memory allocation error\n");
}

void StackIsEmpty()
{
	printf("Stos jest pusty\n");
}

void StackIsNotEmpty()
{
	printf("Stos nie jest pusty\n");
}

void StackPopFail()
{
	printf("Nie mozna zrobic pop bo stos byl pusty\n");
}

void StackPop()
{
	printf("Zabrano ze stosu takiego studenta:\n");
}

void StackClearSuccess()
{
	printf("Wyczyszczono stos\n");
}

void StackTopFail()
{
	printf("Nie mozna zrobic top bo stos byl pusty\n");
}

void TypeSurname()
{
	printf("Podaj nazwisko:\n");
}

void TypeSurnameFail()
{
	printf("Nie ma takiego nazwiska studenta\n");
}

void ErrorDuringWriteToFile()
{
	printf("IO error during write to file\n");
}

void ErrorDuringReadToFile()
{
	printf("IO error during read to file\n");
}

void TypeSurnameYearSubject()
{
	printf("Wprowadz nazwisko studenta, rok studenta i kierunek studenta:\n");
}

void SurnameType()
{
	printf("Nazwisko: ");
}

void TypeYear()
{
	printf("Rok: ");
}

void ChooseSubject()
{
	printf("Kierunek (0 - INFORMATYKA, 1 - MATEMATYKA, 2 - FIZYKA, 3 - MECHANIKA)\n");
}

void TypeSubject()
{
	printf("Kierunek: ");
}

void TypeSubjectFail()
{
	printf("Nie wybrales zadnego numeru (0, 1, 2, 3) kierunku. Dlatego ten student nie bedzie mial przypisanego kierunku.\n");
}

void InformatykaChoice()
{
	printf("kierunek: Informatyka");
}

void MatematykaChoice()
{
	printf("kierunek: Matematyka");
}

void FizykaChoice()
{
	printf("kierunek: Fizyka");
}

void MechanikaChoice()
{
	printf("kierunek: Mechanika");
}

void Quit()
{
	printf("\nKoniec dzialania programu\n\n");
}