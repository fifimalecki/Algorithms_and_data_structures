#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<int, int> GenerateASCIImap()
{
    map<int, int> ASCII;
    for(int i = 32; i < 127; i++)
        ASCII[i] = 0;
    return ASCII;
}

void AsciiCounter(map<int, int> & ASCII, string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        int CHAR = s[i];
        ASCII[CHAR] += 1;
    }
}

void load(string file, string & s)
{
    ifstream f(file);
    char znak;
    while(!f.eof())
    {
        f >> znak;
        s += znak;
    }
}

int main(int argc, char *argv[])
{
    string chars;
    map<int, int> ASCII = GenerateASCIImap();
    load(argv[1],chars);
    AsciiCounter(ASCII,chars);
    for(int i = 32; i < 127; i++)
        cout << (char)i << " : " << ASCII[i] << "\n";
}
