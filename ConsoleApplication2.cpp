

#include <iostream>
using namespace std;

int main()
{
	int n, c, min,i;
	cin >> n >> c;
	min = n;
	if (c < n) min = c;
		for (int i = 1; i <= min; i++)
		{
			if (n % i == 0 && c % i == 0) 
			{
				cout << i << " ";
			}
		 


		}
			cout << "Your answer";
				

	return 0;   
}

