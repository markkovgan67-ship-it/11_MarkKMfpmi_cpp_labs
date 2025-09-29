
#include <iostream>
using namespace std;
int main()

{
    int n;
	cin >> n;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << "F" << i << " = " << a << endl;
        int next = a + b; // Fn = Fn-1 + Fn-2
        a = b;
        b = next;
    }

    return 0;

}

