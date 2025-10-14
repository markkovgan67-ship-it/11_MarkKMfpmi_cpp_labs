
#include <iostream>

int main()
{
    int n;
    int result;
    const int max_lenght = 1000;
    int arr[max_lenght];
    std::cout << "Enter number element nassive";
    std::cin >> n;
    for ( int i = 0; i < n; i++)
    {
    }
    


    

             for (int i = 0; i < n ; i++)
             {
                 for (int j = 0; j < n-1-i; j++)
                 {
                     if (arr[j] > arr[j + 1]) 
                     {

                         std::swap(j, j + 1);
                     }
                     std::cout << arr[i];
                 }

             }
              
    return 0;
}

