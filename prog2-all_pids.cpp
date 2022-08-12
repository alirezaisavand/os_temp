#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    const char* str;

    string cmd = "pstree -cp";
    str = &cmd[0u];
    system(str);

    cmd = "ps -aux";
    str = &cmd[0u];
    system(str);

    return 0;
}