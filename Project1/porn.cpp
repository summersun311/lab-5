#include <locale>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    
    setlocale(LC_ALL, "ru");
    
    int n, m;
    
    cout << "vvedite kolvo strok and stolbtsov" << endl;
    cout << " N: ";
    cin >> n;
    cout << endl;
    cout << " M: ";
    cin >> m;

    int** mtrx = new int* [n];
    for (int i = 0; i < n; i++)
        mtrx[i] = new int[m];

    cout << "vvedite elements matritsi: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mtrx[i][j];

    int osobi;
    osobi = 0;

    //áåðåì sum êîòîðûé áóäåò õðîàíèòü ñóììó ñòîëáöóà      berem sum that will save sum stolbtsa
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int chislo = mtrx[i][j];
            int sum = 0;

            //row çàíîâî ïåðåáèðàåò âñå ñòðîêè ñòîëáöà è ñóììèðóåò åãî ýëåìåíòû êîðî÷    row  zanogo perebiraet vse stroki stolbtsa & summiruet ego elemenets krch
            for (int row = 0; row < n; row++) {
                sum += mtrx[row][j];
            }

            // Ïðîâåðÿåì óñëîâèå "îñîáîãî" ýëåìåíòà     checking uslovia osobogo element
            if (chislo > (sum - chislo)) {
                osobi++;
            }
        }
    }

    cout << "kolvo osobih elements: " << osobi << endl;

    // Îñâîáîæäåíèå ïàìÿòè
    for (int i = 0; i < n; i++)
        delete[] mtrx[i];
    delete[] mtrx;

    return 0;
}
