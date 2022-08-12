#include <iostream>
#include <fstream>



using namespace std;

int main() {

    ifstream myReadFile;
    myReadFile.open("/proc/cpuinfo");
    string  output;
    string str = "";
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            str += output + " ";
        }
    }
    myReadFile.close();

    if (str.find("cache size"))
    {
        int idx = str.find("cache size");
        int i = 0;
        while(i < 20) {
            cout << str[idx + i];
            i++;
        }
        cout << "B" << endl;
    }

    if (str.find("model name"))
    {
        int idx = str.find("model name");
        int i = 0;
        while(i < 54) {
            cout << str[idx + i];
            i++;
        }
        cout << endl;
    }

    if (str.find("cpu MHz"))
    {
        int idx = str.find("cpu MHz");
        int i = 0;
        while(i < 18) {
            cout << str[idx + i];
            i++;
        }
  cout << endl;

    }
}