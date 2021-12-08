#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void insert_sort(int tab[], int a)
{
    int i, j, x;
    for(j=a-2; j>=0; j=j-1)
    {
        x=tab[j];
        i=j+1;
        while((i<a) && (x>tab[i]))
        {
            tab[i-1]=tab[i];
            i=i+1;
        }
        tab[i-1]=x;
    }
}

void select_sort(int tab[], int a)
{
    int j, pmin, i, tamp;
    for(j=0; j<a-1; j=j+1)
    {
        pmin=j;
        for(i=j+1; i<a; i=i+1)
            if(tab[i]<tab[pmin])
                pmin = i;
        tamp=tab[pmin];
        tab[pmin]=tab[j];
        tab[j]=tamp;
    }
}

void bubble_sort(int tab[], int a)
{
    int pmin, i, p, pmax, tamp;
    pmin=0;
    pmax=a-1;
    do
    {
        p=-1;
        for(i=pmin; i<pmax; i=i+1)
            if(tab[i]>tab[i+1])
            {
                tamp=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=tamp;
                if(p<0)
                    pmin=i;
                p=i;
            }
        if(pmin)
            pmin=pmin-1;
        pmax=p;
    }
    while(p>=0);
}

void quicksort(int lewy, int prawy, int tab[])
{
    int i, j, piwot, temp;
    i=(lewy+prawy)/2;
    piwot=tab[i];
    tab[i]=tab[prawy];
    for(j=i=lewy; i<prawy; i=i+1)
        if(tab[i]<piwot)
        {
            temp=tab[i];
            tab[i]=tab[j];
            tab[j]=temp;
            j=j+1;
        }
    tab[prawy]=tab[j];
    tab[j]=piwot;
    if(lewy<j-1)
        quicksort(lewy, j-1, tab);
    if(j+1<prawy)
        quicksort(j+1, prawy, tab);
}

void Shell_sort(int tab[], int a)
{
    int h, j, x, i;
    for(h=1; h<a; h=3*h+1);
        h=h/9;
    if(!h)
        h=h+1;
    while(h)
    {
        for(j=a-h-1; j>=0; j=j-1)
        {
            x=tab[j];
            i=j+h;
            while((i<a) && (x>tab[i]))
            {
                tab[i-h]=tab[i];
                i=i+h;
            }
            tab[i-h]=x;
        }
        h=h/3;
    }
}

void heapsort(int t[], int r)
{
    int k, x, i, j, temp, m;
    for(i=2; i<=r; i=i+1)
    {
        j=i;
        k=j/2;
        x=t[i];
        while((k>0) && (t[k]<x))
        {
            t[j]=t[k];
            j=k;
            k=j/2;
        }
        t[j]=x;
    }
    for(i=r; i>1; i=i-1)
    {
        temp=t[1];
        t[1]=t[i];
        t[i]=temp;
        j=1;
        k=2;
        while(k<i)
        {
            if((k+1<i) && (t[k+1]>t[k]))
                m=k+1;
            else
                m=k;
            if(t[m]<=t[j])
                break;
            temp=t[j];
            t[j]=t[m];
            t[m]=temp;
            j=m;
            k=j+j;
        }
    }
}

void odwracanie(int t[], int l)
{
    int i, tmp;
    for(i=0; i<l/2; i=i+1)
    {
        tmp=t[l-i-1];
        t[l-i-1]=t[i];
        t[i]=tmp;
    }
}

int main()
{
    int rozmiar, numer, i;
    time_t ts, tk;
    float dif;
    clock_t start, end;
    printf("\nPodaj rozmiar tablicy: ");
    scanf("%d", &rozmiar);
    int *tab;
    tab=(int *)malloc(rozmiar *sizeof(int));
    FILE *plik=fopen("dane.txt", "r");
    for(i=0; i<rozmiar; i=i+1)
        fscanf(plik, "%1d", &tab[i]);
    fclose(plik);
    printf("\n\t1 - Sortowanie przez wstawianie\n");
    printf("\t2 - Sortowanie przez selekcje\n");
    printf("\t3 - Sortowanie babelkowe\n");
    printf("\t4 - Sortowanie quicksort\n");
    printf("\t5 - Sortowanie Shella\n");
    printf("\t6 - Sortowanie przez kopcowanie\n\n");
    printf("\t0 - Wylacz program jezeli jest wpisany za duzy rozmiar jak na rodzaj sortowania bo moze zawiesic sie na dlugi czas\n\n");
    printf("Podaj numer: ");
    scanf("%d", &numer);
    switch(numer)
    {
        case 0:
            printf("\n");
            return 0;

        case 1:
            time(&ts);
            start=clock();
            insert_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\n\nCzas dla sortowania losowego: %f sekund\n", dif/CLOCKS_PER_SEC);

            time(&ts);
            start=clock();
            insert_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania rosnacego: %f sekund\n", dif/CLOCKS_PER_SEC);

            odwracanie(tab, rozmiar);
            time(&ts);
            start=clock();
            insert_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania malejacego: %f sekund\n\n", dif/CLOCKS_PER_SEC);
            break;

        case 2:
            time(&ts);
            start=clock();
            select_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\n\nCzas dla sortowania losowego: %f sekund\n", dif/CLOCKS_PER_SEC);

            time(&ts);
            start=clock();
            select_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania rosnacego: %f sekund\n", dif/CLOCKS_PER_SEC);

            odwracanie(tab, rozmiar);
            time(&ts);
            start=clock();
            select_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania malejacego: %f sekund\n\n", dif/CLOCKS_PER_SEC);
            break;

        case 3:
            time(&ts);
            start=clock();
            bubble_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\n\nCzas dla sortowania losowego: %f sekund\n", dif/CLOCKS_PER_SEC);

            time(&ts);
            start=clock();
            bubble_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania rosnacego: %f sekund\n", dif/CLOCKS_PER_SEC);

            odwracanie(tab, rozmiar);
            time(&ts);
            start=clock();
            bubble_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania malejacego: %f sekund\n\n", dif/CLOCKS_PER_SEC);
            break;

        case 4:
            time(&ts);
            start=clock();
            quicksort(0, rozmiar-1, tab);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\n\nCzas dla sortowania losowego: %f sekund\n", dif/CLOCKS_PER_SEC);

            time(&ts);
            start=clock();
            quicksort(0, rozmiar-1, tab);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania rosnacego: %f sekund\n", dif/CLOCKS_PER_SEC);

            odwracanie(tab, rozmiar);
            time(&ts);
            start=clock();
            quicksort(0, rozmiar-1, tab);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania malejacego: %f sekund\n\n", dif/CLOCKS_PER_SEC);
            break;

        case 5:
            time(&ts);
            start=clock();
            Shell_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\n\nCzas dla sortowania losowego: %f sekund\n", dif/CLOCKS_PER_SEC);

            time(&ts);
            start=clock();
            Shell_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania rosnacego: %f sekund\n", dif/CLOCKS_PER_SEC);

            odwracanie(tab, rozmiar);
            time(&ts);
            start=clock();
            Shell_sort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania malejacego: %f sekund\n\n", dif/CLOCKS_PER_SEC);
            break;

        case 6:
            time(&ts);
            start=clock();
            heapsort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\n\nCzas dla sortowania losowego: %f sekund\n", dif/CLOCKS_PER_SEC);

            time(&ts);
            start=clock();
            heapsort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania rosnacego: %f sekund\n", dif/CLOCKS_PER_SEC);

            odwracanie(tab, rozmiar);
            time(&ts);
            start=clock();
            heapsort(tab, rozmiar);
            time(&tk);
            end=clock();
            dif=difftime(end, start);
            printf("\nCzas dla sortowania malejacego: %f sekund\n\n", dif/CLOCKS_PER_SEC);
            break;

        default:
            printf("\nNie ma takiego numeru\n\n");
            break;
    }

    return 0;
}
