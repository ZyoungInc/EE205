#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

  ifstream infile;
  infile.open("../story/op.txt");
  if (infile.fail()) {
    cout<<"file failed to read"<<endl;
  }
    else {
      string s;
      while(getline(infile, s)) {
        cout<<s<<endl;
      }
      infile.close();
    }
  return 0;
}
