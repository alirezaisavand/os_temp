#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string line;
	ifstream ini_file;
	ini_file.open("/proc/version");
	ofstream out_file;
	out_file.open("linux_version.txt");
	if (ini_file && out_file) {
		while(getline(ini_file, line)){
			out_file << line << "\n";
		}
	}
	ini_file.close();
	out_file.close();
	return 0;
}
