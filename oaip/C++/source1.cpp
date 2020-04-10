#include <iostream> 
using namespace std; 
void foo(int a) 
{ 
    int res=1; 
    if (a>0) 
    { 
        static int res = 1000; 
        res = res * a * 1000; 
        cout << res << endl; 
    } 
    return;
} 
int main() 
{ 
    foo(1); 
    return 0; 
}