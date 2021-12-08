#include <iostream>
#include "matrix/lib.h"

using namespace std;

void addMatrix(int r, int c) {
    double m1[10][10], m2[10][10], s[10][10];
    cout << endl << "Wprowadz elementy pierwszej macierzy:" << endl; //wprowadzenie pierwszej macierzy ktora chcemy dodac
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m1[i][j];
        }
    }
    cout << "Wprowadz elementy drugiej macierzy:" << endl; //wprowadzenie drugiej macierzy ktora chcemy dodac
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m2[i][j];
        }
    }
    for (int i = 0; i < r; i++) { //operacja dodawania macierzy
        for (int j = 0; j < c; j++) {
            s[i][j] = m1[i][j] + m2[i][j];
        }
    }
    cout << endl << "Wynik: ";
    cout << endl;
    for (int i = 0; i < r; ++i) { //wyswietlenie wyniku
        for (int j = 0; j < c; ++j)
        {
            cout << s[i][j] << "  ";
            if (j == c - 1)
                cout << endl;
        }
    }
}

void subtractMatrix(int r, int c) {
    double m1[10][10], m2[10][10], s[10][10];
    cout << endl << "Wprowadz elementy pierwszej macierzy:" << endl; //wprowadzenie pierwszej macierzy ktora chcemy odjac
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m1[i][j];
        }
    }
    cout << "Wprowadz elementy drugiej macierzy:" << endl; //wprowadzenie drugiej macierzy ktora chcemy odjac
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m2[i][j];
        }
    }
    for (int i = 0; i < r; i++) { //operacja odejmowania macierzy
        for (int j = 0; j < c; j++) {
            s[i][j] = m1[i][j] - m2[i][j];
        }
    }
    cout << endl << "Wynik: ";
    cout << endl;
    for (int i = 0; i < r; ++i) { //wyswietlenie wyniku
        for (int j = 0; j < c; ++j)
        {
            cout << s[i][j] << "  ";
            if (j == c - 1)
                cout << endl;
        }
    }
}

void multiplyMatrix() {
    double a[10][10], b[10][10], mult[10][10];
    int r1, c1, r2, c2, i, j, k;

    cout << "Wprowadz liczbe wierszy i liczbe kolumn pierwszej macierzy: ";
    cin >> r1 >> c1;
    cout << "Wprowadz liczbe kolumn drugiej macierzy: ";
    r2 = c1; //aby mnozyc macierze, liczba kolumn pierwszej macierzy musi byc rowna liczbie wierszy drugiej macierzy
    cin >> c2;

    cout << endl << "Wprowadz elementy pierwszej macierzy:" << endl; //wprowadzenie pierwszej macierzy ktora chcemy pomnozyc
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
        {
            cout << "Wprowadz element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    cout << endl << "Wprowadz elementy drugiej macierzy:" << endl; //wprowadzenie drugiej macierzy ktora chcemy pomnozyc
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
        {
            cout << "Wprowadz element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    for (i = 0; i < r1; ++i){ //wyzerowanie elementow macierzy pomocniczej
        for (j = 0; j < c2; ++j)
        {
            mult[i][j] = 0;
        }
    }

    for (i = 0; i < r1; ++i) //operacja mnozenia macierzy
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    cout << endl << "Wynik: " << endl;
    for (i = 0; i < r1; ++i){ //wyswietlenie wyniku
        for (j = 0; j < c2; ++j)
        {
            cout << " " << mult[i][j];
            if (j == c2 - 1)
                cout << endl;
        }
    }
}

void multiplyByScalar() {
    int i, j, rows, columns;

    cout << "Wprowadz liczbe wierszy i liczbe kolumn macierzy: ";
    cin >> i >> j;

    double scalarMulArr[10][10], multi[10][10], number;

    cout << endl << "Wprowadz elementy macierzy: "; //wprowadzenie macierzy ktora chcemy pomnozyc
    for (rows = 0; rows < i; rows++) {
        for (columns = 0; columns < j; columns++) {
            cin >> scalarMulArr[rows][columns];
        }
    }

    cout << endl << "Wprowadz skalar:" << endl;
    cin >> number;

    for (rows = 0; rows < i; rows++){ //operacja mnozenia macierzy przez skalar
        for (columns = 0; columns < j; columns++)
        {
            multi[rows][columns] = number * scalarMulArr[rows][columns];
        }
    }

    cout << endl << "Wynik:" << endl;
    for (rows = 0; rows < i; rows++){ //wyswietlenie wyniku
        for (columns = 0; columns < j; columns++)
        {
            cout << multi[rows][columns] << " ";
        }
        cout << endl;
    }
}

void transpozeMatrix() {
    double matrix[10][10], transMatrix[10][10];
    int row, col;

    cout << "Wprowadz liczbe wierszy macierzy: ";
    cin >> row;

    cout << "Wprowadz liczbe kolumn macierzy: ";
    cin >> col;

    cout << "Wprowadz elementy macierzy:" << endl; //wprowadzenie macierzy ktora chcemy transponowac
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Przed transpozycja macierzy:" << endl;
    for (int i = 0; i < row; i++) { //wyswietlenie wyniku przed transpozycja
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
            if (j == col - 1)
                cout << endl;

        }
    }

    for (int i = 0; i < row; i++) { //operacja transpozycji macierzy
        for (int j = 0; j < col; j++) {
            transMatrix[j][i] = matrix[i][j];
        }
    }

    cout << "Po transpozycji macierzy:" << endl;
    for (int i = 0; i < col; i++) { //wyswietlenie wyniku po transpozycji
        for (int j = 0; j < row; j++) {
            cout << transMatrix[i][j] << " ";

            if (j == row - 1)
                cout << endl;
        }
    }   
}

void powerMatrix() {
    double a[10][10], mult[10][10], power;
    int r1, c1, i, j, k;

    cout << "Wprowadz liczbe wierszy i liczbe kolumn macierzy: ";
    cin >> r1;
    c1 = r1;

    cout << endl << "Wprowadz elementy macierzy:" << endl; //wprowadzenie macierzy ktora chcemy potegowac
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
        {
            cout << "Wprowadz element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    for (i = 0; i < r1; ++i){ //wyzerowanie elementow macierzy pomocniczej
        for (j = 0; j < c1; ++j)
        {
            mult[i][j] = 0;
        }
    }

    cout << "Wprowadz wykladnik: ";
    cin >> power;
    while (power != 2) {
        cout << "Niestety dziala tylko dla wykladnika = 2" << endl;
        cout << "Wprowadz wykladnik: ";
        cin >> power;
    }
    {
        for (i = 0; i < r1; ++i){ //operacja potegowania macierzy
            for (j = 0; j < c1; ++j)
                for (k = 0; k < c1; ++k)
                {
                    mult[i][j] += a[i][k] * a[k][j];
                }
        }

        cout << endl << "Wynik:" << endl;
        for (i = 0; i < r1; ++i){ //wyswietlenie wyniku
            for (j = 0; j < c1; ++j)
            {
                cout << " " << mult[i][j];
                if (j == c1 - 1)
                    cout << endl;
            }
        }
    }
}

double determinantMatrix(double matrix[10][10], int n) {
    double det = 0, submatrix[10][10];
    if (n == 2) //operacja liczenia wyznacznika macierzy 2x2
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else{ //operacja liczenia wyznacznika macierzy o wiekszych rozmiarach
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinantMatrix(submatrix, n - 1));
        }
    }
    return det; //zwrocenie wartosci wyznacznika
}

bool matrixIsDiagonal()
{
    int m, i, j, z = 0;
    cout << "Wprowadz rozmiar macierzy: ";
    cin >> m;
    double arr[10][10];
    cout << "Wprowadz elementy macierzy: "; //wprowadzenie macierzy, ktora chcemy sprawdzic, czy jest diagonalna
    for (i = 0; i <= (m - 1); i++)
        for (j = 0; j <= (m - 1); j++)
            cin >> arr[i][j];
    for (i = 0; i <= (m - 1); i++) //operacje sprawdzajace czy macierz jest diagonalna
    {
        for (j = 0; j <= (m - 1); j++)
            if (i != j && arr[i][j] == 0)
            {
                z++;
            }
    }
    if(z == m * m - m) //zwrocenie wartosci bool
        return true;
    else
        return false;
}

void swap(double& x, double& y) //zamiana dwoch wartosci przez referencje
{
    double temp;
    temp = x;
    x = y;
    y = temp;
}

void sortRow() {
    int n;
    cout << "Wprowadz liczbe elementow ktore chcesz posortowac: ";
    cin >> n;
    int i, j;
    double * arr = new double[n]; //tablica alokowana dynamicznie
    cout << "Wprowadz elementy:" << endl; //wprowadzenie tablicy ktora chcemy posortowac

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < n - 1; i++) //algorytm sortowania babelkowego
    {
        for (j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << endl << "Po posortowaniu babelkowym:" << endl;
    for (i = 0; i < n; i++) //wyswietlenie wyniku
        cout << arr[i] << " ";
    cout << endl;
    delete [] arr; //zwolnienie tablicy alokowanej dynamicznie
}

void sortRowsInMatrix(double arr[][20], int n, int m) {
    int i, j, k;
    for (k = 0; k < n; ++k){ //algorytm sortowania kazdego wiersza macierzy osobno
        for (i = 0; i < m; ++i){
            for (j = 0; j < m - 1 - i; ++j){
                if (arr[k][j] > arr[k][j + 1]){
                    double temp = arr[k][j + 1];
                    arr[k][j + 1] = arr[k][j];
                    arr[k][j] = temp;
                }
            }
        }
    }
    for (i = 0; i < n; ++i){ //wyswietlenie wyniku
        for (j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}