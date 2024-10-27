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
void reading(vector<string>&, list<string>&, set<string>&);

int main() {
    vector<string> testv;
    list<string> testl;
    set<string> tests;

    reading(testv, testl, tests);

    cout << testv[5] << endl;
    
    for (const string &x : testl) {
        cout << x << endl;
    }
    return 0;
}

void reading(vector<string>& v, list<string>& l, set<string>& s) {
    string test;
    ifstream file("codes.txt");
    while(getline(file, test)) {
        v.push_back(test);
        l.push_back(test);
        s.insert(test); 
    }
    file.close();
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/