#include <locale>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    
    setlocale(LC_ALL, "ru");
    
    int n, m;
    
    cout << "Введите количество строк и столбцов" << endl;
    cout << "Введите N: ";
    cin >> n;
    cout << endl;
    cout << "Введите M: ";
    cin >> m;

    int** mtrx = new int* [n];
    for (int i = 0; i < n; i++)
        mtrx[i] = new int[m];

    cout << "Введи элементы матрицы: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mtrx[i][j];

    int osobi;
    osobi = 0;

    //берем sum который будет хроанить сумму столбцуа      berem sum that will save sum stolbtsa
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int chislo = mtrx[i][j];
            int sum = 0;

            //row заново перебирает все строки столбца и суммирует его элементы короч    row  zanogo perebiraet vse stroki stolbtsa & summiruet ego elemenets krch
            for (int row = 0; row < n; row++) {
                sum += mtrx[row][j];
            }

            // Проверяем условие "особого" элемента     checking uslovia osobogo element
            if (chislo > (sum - chislo)) {
                osobi++;
            }
        }
    }

    cout << "Количество особых элементов: " << osobi << endl;

    // Освобождение памяти
    for (int i = 0; i < n; i++)
        delete[] mtrx[i];
    delete[] mtrx;

    return 0;
}