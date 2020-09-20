#include <iostream>
using namespace std;
int main() 
{
    int n; // номер числа фибоначи
    int a = 0,b = 1;
    cin>>n;
    if(n == 0)cout<<0;
    else
    {
        int counter = 1;
        while(a + b < n)
        {
            int temp = b;
            b = a + b;
            a = temp;
            //cout<<b<<" ";
            counter++;
        }
        if(a + b != n)cout<<-1;
        else cout<<counter+1;
    }
    /*
    1 2 3 4 5 6 7 8 9
    1 1 2 3 5 8 13 21.  
    */
    return 0;
}