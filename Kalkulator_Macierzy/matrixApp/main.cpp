#include <iostream>
#include "matrix/lib.h"
#include <limits> //biblioteka do rozszerzonego uzycia funkcji cin.ignore()

using namespace std;

int main()
{
    int numerek;
    cout << "1 - addMatrix, 2 - subtractMatrix, 3 - multiplyMatrix, 4 - multiplyByScalar" << endl
         << "5 - transpozeMatrix, 6 - powerMatrix, 7 - determinantMatrix, 8 - matrixIsDiagonal" << endl
         << "9 - swap, 10 - sortRow, 11 - sortRowsInMatrix" << endl
         << "0 - help" << endl;
    do{
        cin >> numerek;
        cin.clear(); //czyszczenie zle wpisanych znakow
        cin.ignore(numeric_limits < streamsize >::max(), '\n'); //ignorowanie wszystkich zle wpisanych znakow az do konca linii
        cout << endl;
        int row, col, i, j, n;
        switch(numerek)
        {
        case 0:
            cout << endl << "======" << endl << "|HELP|" << endl << "======" << endl << endl << "Wprowadz liczbe calkowita z zakresu (1-11), "
                 << "zeby wybrac operacje, ktora chcesz dokonac." << endl << "Nastepnie wprowadz odpowiednie wartosci, takie jak rozmiar macierzy, "
                 << "liczbe wierszy," << endl << "liczbe kolumn. Na koncu wprowadz elementy macierzy i zobacz wynik operacji." << endl << endl
                 << "Wprowadz liczbe calkowita z zakresu [1-11]: "; //interfejs HELP
            break;
        case 1:
            cout << endl << "===========" << endl << "|ADDMATRIX|" << endl << "===========" << endl << endl;
            cout << "Wprowadz liczbe wierszy macierzy: ";
            cin >> row;
            cout << "Wprowadz liczbe kolumn macierzy: ";
            cin >> col;
            addMatrix(row, col); //uzycie funkcji
            break;
        case 2:
            cout << endl << "================" << endl << "|SUBTRACTMATRIX|" << endl << "================" << endl << endl;
            cout << "Wprowadz liczbe wierszy macierzy: ";
            cin >> row;
            cout << "Wprowadz liczbe kolumn macierzy: ";
            cin >> col;
            subtractMatrix(row, col); //uzycie funkcji
            break;
        case 3:
            cout << endl << "================" << endl << "|MULTIPLYMATRIX|" << endl << "================" << endl << endl;
            multiplyMatrix(); //uzycie funkcji
            break;
        case 4:
            cout << endl << "==================" << endl << "|MULTIPLYBYSCALAR|" << endl << "==================" << endl << endl;
            multiplyByScalar(); //uzycie funkcji
            break;
        case 5:
            cout << endl << "=================" << endl << "|TRANSPOZEMATRIX|" << endl << "=================" << endl << endl;
            transpozeMatrix(); //uzycie funkcji
            break;
        case 6:
            cout << endl << "=============" << endl << "|POWERMATRIX|" << endl << "=============" << endl << endl;
            powerMatrix(); //uzycie funkcji
            break;
        case 7:
            cout << endl << "===================" << endl << "|DETERMINANTMATRIX|" << endl << "===================" << endl << endl;
            double matrix[10][10];
            cout << "Wprowadz rozmiar macierzy:" << endl;
            cin >> n;
            cout << "Wprowadz elementy macierzy:" << endl;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    cin >> matrix[i][j];
            cout << endl << "Wprowadzona macierz:" << endl;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++)
                    cout << matrix[i][j] << " ";
                cout << endl;
            }
            cout << "Wyznacznik tej macierzy to: " << determinantMatrix(matrix, n) << endl; //uzycie funkcji
            break;
        case 8:
            cout << endl << "==================" << endl << "|MATRIXISDIAGONAL|" << endl << "==================" << endl << endl;
            if (matrixIsDiagonal()) //uzycie funkcji
                cout << endl << "Ta macierz jest diagonalna";
            else
                cout << endl << "Ta macierz nie jest diagonalna";
            break;
        case 9:
            cout << endl << "======" << endl << "|SORT|" << endl << "======" << endl << endl;
            double a, b;
            cout << "Wprowadz wartosc a: ";
            cin >> a;
            cout << "Wprowadz wartosc b: ";
            cin >> b;
            cout << endl << "Przed zamiana: ";
            cout << "a = " << a << " , b = " << b;
            cout << endl << endl << "Zamiana przez referencje..." << endl;
            swap(a, b); //uzycie funkcji
            cout << endl << "Po zamianie: ";
            cout << "a = " << a << " , b = " << b;
            cout << endl;
            break;
        case 10:
            cout << endl << "=========" << endl << "|SORTROW|" << endl << "=========" << endl << endl;
            sortRow(); //uzycie funkcji
            break;
        case 11:
            cout << endl << "==================" << endl << "|SORTROWSINMATRIX|" << endl << "==================" << endl << endl;
            int m;
            double arr[20][20];
            cout << "Wprowadz liczbe wierszy macierzy: ";
            cin >> n;
            cout << "Wprowadz liczbe kolumn macierzy: ";
            cin >> m;
            cout << "Wprowadz elementy macierzy:" << endl;
            for (i = 0; i < n; ++i) {
                for (j = 0; j < m; ++j) {
                    cin >> arr[i][j];
                }
            }
            cout << endl << "Macierz po posortowaniu rosnaco kazdego wiersza osobno:" << endl;
            sortRowsInMatrix(arr, n, m); //uzycie funkcji
            break;
        default:
            cout << endl << "======" << endl << "|HELP|" << endl << "======" << endl << endl << "Wprowadz liczbe calkowita z zakresu (1-11), "
                 << "zeby wybrac operacje, ktora chcesz dokonac." << endl << "Nastepnie wprowadz odpowiednie wartosci, takie jak rozmiar macierzy, "
                 << "liczbe wierszy," << endl << "liczbe kolumn. Na koncu wprowadz elementy macierzy i zobacz wynik operacji." << endl << endl
                 << "Wprowadz liczbe calkowita z zakresu [1-11]: "; //interfejs HELP
            break;
        }
    }while(numerek<1 || numerek>11);

    return 0;
}