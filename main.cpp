/*

lab25: data structures races
COMSC-210
Naveen Islam

*/
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;

// function prototypes
void reading(vector<string>&);

int main() {
    vector<string> testv;
    reading(testv);
    cout << testv[5] << endl;
    return 0;
}

void reading(vector<string>& v) {
    string test;
    ifstream file("codes.txt");
    while(getline(file, test)) {
        v.push_back(test);
    }
    file.close();
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/