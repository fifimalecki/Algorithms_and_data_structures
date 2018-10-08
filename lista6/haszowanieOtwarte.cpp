#include <iostream>
#include <vector>

using namespace std;

const int m = 16;

int h1(int k)
{
    return k % m;
}

int h2(int k)
{
    return (10 * k + 1) % m;
}

int Ha(int x, int k)
{
    return (h1(x) + k) % m;
}

int Hb(int x, int k)
{
    return (h1(x) + h2(x) * k) % m;
}

int main()
{
    int arr[] = {3,20,25,98,120,213,2131,99,131,9,129};

//    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int arrN = 11;
    int hasz[m] = {NULL};

    int counter = 0;
    for(int id=0; id < arrN; id++)
    {

        for(int i=0; i < m; i++)
        {
            int index = Ha(arr[id],i);
            cout << index << " " << hasz[index] << " " << arr[id] <<endl;
            if(hasz[index] == NULL){ hasz[index] = arr[id]; break;}
            else counter++;
        }
    }
    for(int i = 0; i < m; i++)
        cout << "T["<<i<<"] = "<<hasz[i] << " \n";
cout << endl <<counter<< endl;
counter =0;
    int hasz2[m] = {NULL};

    for(int id=0; id < arrN; id++)
    {
        for(int i=0; i < m; i++)
        {
            int index = Hb(arr[id],i);
            cout << index << " " << hasz2[index] << " " << arr[id] <<endl;
            if(hasz2[index] == NULL){ hasz2[index] = arr[id]; break;}
            else counter++;
        }
    }
    for(int i = 0; i < m; i++)
        cout << "T["<<i<<"] = "<<hasz2[i] << " \n";
cout << endl <<counter<< endl;

}
