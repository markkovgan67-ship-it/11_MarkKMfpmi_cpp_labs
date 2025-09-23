#include <iostream>
using namespace std;

int main()
{
    int a, b, min, max, sum1, sum2;
    cin >> a >> b;

    if (a > b) {
        max = a;
        min = b;
    }
    else {
        max = b;
        min = a;
    }

    int found = 0;

    for (int i = min; i <= max; i++)
    {
        sum1 = 0;
        for (int k = 1; k <= i / 2; k++)
        {
            if (i % k == 0)
                sum1 = sum1 + k;
        }

        for (int j = i + 1; j <= max; j++)
        {
            sum2 = 0;
            for (int k = 1; k <= j / 2; k++)
            {
                if (j % k == 0)
                    sum2 = sum2 + k;
            }

            if (sum1 == j && sum2 == i)
            {
                cout << i << " " << j << endl;
                found = 1;
            }
        }
    }

    if (!found) {
        cout << "Nothing";
    }

    return 0;
}