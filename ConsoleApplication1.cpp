
#include <iostream>
using namespace std;

int main()
{
	int n, a, sum, mult;
	cin >> n ;
	cin >> a;
	sum = 0;
	for ( int i=0; i<=n ; i+=2)//четные чисал
	{

		sum = sum + i;
		
	
    }
	
	mult = 1;
	for (int i = 1; i <= a; i += 2)
	{

		 mult= mult * i;


	}
	cout << sum << endl;
	cout << mult << endl;

return 0;
}