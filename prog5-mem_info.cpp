#include <iostream>
#include <fstream>



using namespace std;

int main() {

    ifstream myReadFile;
    myReadFile.open("/proc/meminfo");
    string  output;
    string str = "";
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) { 
            myReadFile >> output;
            str += output + " ";
        }
    }
    myReadFile.close();

    for (int i = 0; i < str.size() - 7; i++)
    {
        if (str[i] == 'M' && str[i+1] == 'e' && str[i+2] == 'm' && str[i+3] == 'T' && str[i+4] == 'o' && str[i+5] == 't' && str[i+6] == 'a' && str[i+7] == 'l')
        {
            int s = i;
            while(str[s] != 'B'){
                cout<<str[s];
                s++;
            }
            cout<<"B"<<endl;
        }
    }
    for (int i = 0; i < str.size() - 6; i++)
    {
        if (str[i] == 'M' && str[i+1] == 'e' && str[i+2] == 'm' && str[i+3] == 'F' && str[i+4] == 'r' && str[i+5] == 'e' && str[i+6] == 'e')
        {
            int s = i;
            while(str[s] != 'B'){
                cout<<str[s];
                s++;
            }
            cout<<"B"<<endl;
        }
    }
    for (int i = 0; i < str.size() - 5; i++)
    {
        if (str[i] == 'A' && str[i+1] == 'c' && str[i+2] == 't' && str[i+3] == 'i' && str[i+4] == 'v' && str[i+5] == 'e' && str[i+6] != '(')
        {
            int s = i;
            while(str[s] != 'B'){
                cout<<str[s];
                s++;
            }
            cout<<"B"<<endl;
        }
    }
}

