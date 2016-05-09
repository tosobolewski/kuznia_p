#include <iostream>
using namespace std;

/*

*/


    int kwadrat(int x) 
    {
        return x * x;
    }

    bool parzysta(int x)
    {
        return (x % 2) == 0;
    }
    
    
    int main() 
    {
        int i;
        for (i = 1; i <= 10; i++)
        {
            cout << i << "   " << kwadrat(i) << "   " << parzysta(i) << endl;
        }
        return 0;
    }
