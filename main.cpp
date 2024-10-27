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
using namespace std::chrono;

// function prototypes
void reading(vector<string>&, list<string>&, set<string>&);
void sorting(vector<string>&, list<string>&, set<string>&);

int main() {
    vector<string> testv;
    list<string> testl;
    set<string> tests;

    auto start = high_resolution_clock::now();
    reading(testv, testl, tests);

    
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

void sorting(vector<string>&, list<string>&, set<string>&) {

}


/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/