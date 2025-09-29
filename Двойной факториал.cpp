#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;

    int chet = 1;  
    int nechet = 1; 

    for (int i = 1; i <= k; i++)
    {
        if (i % 2 == 0) {
            chet *= i;
        }
        else {
            nechet *= i;
        }
    }

    cout << "mult chet: " << chet << endl;
    cout << "mult nechet: " << nechet << endl;

    return 0;
}