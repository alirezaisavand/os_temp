#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream file_reader;
    file_reader.open("/proc/version");

    string file_out;
    string output = " ";

    // read from version
    if (file_reader.is_open()) {
  for (int i = 0; i < 18; i++) {
      file_reader >> file_out;
      output += file_out;
            output += " ";
  }
    }

    file_reader.close();

    // write in .txt
    ofstream file_writer;
    file_writer.open("linux_version.txt");
    file_writer << output;
    file_writer << "\n";

    return 0;
}