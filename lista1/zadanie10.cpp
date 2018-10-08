#include <iostream>

using namespace std;

template<class T>
class stack
{
    int length,topIndex;
    T *p;
public:
    stack(int _length = 1)
    :length(_length)
    {
        topIndex = -1;
        if(length >= 1)
            p = new T[length];
        else
        {
            cout << "You are trying to make stack 0 or less size...\n";
        }
    }

    ~stack()
    {
        delete [] p;
    }

    bool isEmpty()
    {
        if(topIndex == -1)
        {
            //cout << "True" << endl;
            return true;
        }
        else
        {
           // cout << "False" << endl;
            return false;
        }
    }

    void push(T element)
    {
        if(topIndex == (length - 1))
        {
            cout << "Stack i full.\n";
            return;
        }
        else
        {
            topIndex++;
            p[topIndex]=element;
        }
    }

    T pop()
    {
        if(topIndex == -1)
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        T ret = p[topIndex];
        p[topIndex] == NULL;
        topIndex--;
        return ret;
    }
    void display()
    {
        for(int i = 0; i <= topIndex; i++)
        {
            if(i == topIndex)
                cout << "["<<p[i]<<"]";
            else
                cout<<p[i]<<" ";
        }
        cout<<endl;
    }
    T top()
    {
        if(topIndex > -1)
            return p[topIndex];
        else
        {
            cout << "Stack is empty.\n";
            return false;
        }
    }

};

template<class T>
class queue
{
    int last;
    T *p;
public:
    queue()
    {
        last = -1;
        p = new T[1];
    }

    ~queue()
    {
        delete [] p;
    }

    bool isEmpty()
    {
        if(last == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return last+1;
    }

    T front()
    {
        if(last == -1)
            return p[0];
        return p[last];
    }

    T back()
    {
        return p[0];
    }

    void push(T element)
    {
        T temp1=p[0];
        T temp2;
        last++;
        p[0] = element;
        for(int i = 1; i <= last; i++)
        {
            temp2 = p[i];
            p[i] = temp1;
            temp1 = temp2;
        }
    }

    T pop()
    {
        T ret = p[last];
        p[last] = NULL;
        last--;
        return ret;
    }

    void display()
    {
        for(int i = 0; i <= last; i++)
        {
            if(last == 0)
                cout << "{[" << p[i] << "]} ";
            else if(i == 0)
                cout << "{" << p[i] << "} ";
            else if(i == last)
                cout << "[" << p[i] << "] ";
            else
                cout<<p[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{

}
