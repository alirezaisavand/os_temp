#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    string s;
    cin >> s;
    string cmd = "cat /proc/" + s + "/cmdline";
    const char* str = &cmd[0u];
    system(str);

    cmd = "cat /proc/" + s + "/environ";
    str = &cmd[0u];
    system(str);

    cmd = "`cut -d \' \' -f1 /proc/" + s + "/statm`";
    str = &cmd[0u];
    system(str);

    cmd = "cat /proc/" + s + "/status";
    str = &cmd[0u];
    system(str);

    return 0;
}