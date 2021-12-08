#include "MyStudent.h"
#include "MyErrorAndCom.h"

void StudentPutData(Student* ptr, char* title, Kierunek kierunek)
{
	strcpy_s(ptr->nazwisko, sizeof(ptr->nazwisko), title);

	ptr->kierunek = kierunek;
}

char* ReadStringDynamic() 
{
	int total = 10;
	char* nazwisko = (char*)malloc(total * sizeof(char));

	int i = 0;
	char c;

	while ((c = getchar()) != '\n')
	{
		nazwisko[i] = c;
		i++;

		if (i >= total)
		{
			total = 2 * total;
			nazwisko = (char*)realloc(nazwisko, total);
		}
	}

	nazwisko[i] = '\0';
	nazwisko = (char*)realloc(nazwisko, i + 1);

	return nazwisko;
}

void StudentInput(Student* ptr)
{

	getchar();

	TypeSurnameYearSubject();
	SurnameType();
	ptr->nazwisko = ReadStringDynamic();

	TypeYear();
	scanf_s("%d", &ptr->rok);

	ChooseSubject();
	TypeSubject();

	int num;
	scanf_s("%d", &num);

	switch (num)
	{
	case 0:
		ptr->kierunek = Kierunek::INFORMATYKA;
		break;
	case 1:
		ptr->kierunek = Kierunek::MATEMATYKA;
		break;
	case 2:
		ptr->kierunek = Kierunek::FIZYKA;
		break;
	case 3:
		ptr->kierunek = Kierunek::MECHANIKA;
		break;
	default:
		TypeSubjectFail();
	}
	

}

void StudentPrint(void* pdata)
{
	Student* ptr = (Student*)pdata;

	printf("\n");

	printf("nazwisko: %s\n", ptr->nazwisko);
	printf("rok: %d\n", ptr->rok);

	switch (ptr->kierunek)
	{
	case Kierunek::INFORMATYKA:
		InformatykaChoice();
		break;
	case Kierunek::MATEMATYKA:
		MatematykaChoice();
		break;
	case Kierunek::FIZYKA:
		FizykaChoice();
		break;
	case Kierunek::MECHANIKA:
		MechanikaChoice();
		break;
	}
	printf("\n\n");
}

void StudentFree(void** pTr)
{
	if (pTr)
	{
		if (*pTr)
		{
			Student* ptr = (Student*)(*pTr);
			free(*pTr);
			*pTr = NULL;
		}
	}
}

bool StudentSave(void** pdat, FILE* pf)
{
	if (pf && *pdat)
	{
		Student* ptr = (Student*)(*pdat);
		size_t ctrl_len;

		int len = strlen(ptr->nazwisko);

		fwrite(ptr->nazwisko, 1, len, pf);
		fputc('\0', pf);
		fwrite(&(ptr->rok), sizeof(int), 1, pf);
		fwrite(&(ptr->kierunek), sizeof(Kierunek), 1, pf);


		return true;
	}
	else
		return false;
}

bool StudentRead(void** pdat, FILE* pf)
{
	if (pf)
	{
		Student* ptr = (Student*)(*pdat);
		size_t ctrl_len;

		if (!ptr)
		{
			if ((ptr = (Student*)malloc(sizeof(Student))) == NULL)
				return false;
		}

		*pdat = (void*)ptr;

		int total = 10;
		char* nazwisko = (char*)malloc(total * sizeof(char));

		int i = 0;
		char c;

		while ((c = fgetc(pf)) != '\0')
		{
			if (c == EOF)
				return false;

			nazwisko[i] = c;
			i++;

			if (i >= total)
			{
				total = 2 * total;
				nazwisko = (char*)realloc(nazwisko, total);
			}
		}

		nazwisko[i] = '\0';
		nazwisko = (char*)realloc(nazwisko, i + 1);
		ptr->nazwisko = nazwisko;

		fread(&(ptr->rok), sizeof(int), 1, pf);
		fread(&(ptr->kierunek), sizeof(int), 1, pf);

		return true;
	}
	else
		return false;
}