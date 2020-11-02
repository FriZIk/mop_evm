//  подготовка к собеседованию
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//typedef + vector + map(асоциативный массив/словарь) + sort + string + const& + set(множество) + сount_if + lambda= public library system 

void PrintVector(vector<string> *vec1)
{
    for(auto str:*vec1)
        cout<<str<<" ";
    cout<<endl;
}

void PrintVector1(vector<string> &vec1)
{
    for(int i = 0;i < vec1.size();i++)
        cout<<vec1[i]<<" ";
    cout<<endl;
}

void EnterVector(vector<string> *vec1,int *n) // Первый способ ввода вектора
{
    for(int i = 0;i < *n;i++)
    {
        string str;
        cin>>str;
        vec1->push_back(str);
    }
}

int main()
{
    int n = 0;
    cin>>n;
    vector<string> vec1;

    EnterVector(&vec1,&n);
    PrintVector(&vec1);
    PrintVector1(vec1);
}