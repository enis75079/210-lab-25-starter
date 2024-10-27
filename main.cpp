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
#include <iomanip>
using namespace std;
using namespace std::chrono;

// function prototypes
void readingVec(vector<string>&);
void readingList(list<string>&);
void readingSet(set<string>&);

void sortingVec(vector<string>&);
void sorthingList(list<string>&);
void sortingSet(set<string>&);

int main() {
    vector<string> testv;
    list<string> testl;
    set<string> tests;

    // reading
    auto start = high_resolution_clock::now();
    readingVec(testv);
    auto end = high_resolution_clock::now();
    auto durationV = duration_cast<milliseconds>(end - start);
    cout << durationV.count() << endl;

    start = high_resolution_clock::now();
    readingList(testl);
    end = high_resolution_clock::now();
    auto durationL = duration_cast<milliseconds>(end - start);
    cout << durationL.count() << endl;

    start = high_resolution_clock::now();
    readingSet(tests);
    end = high_resolution_clock::now();
    auto durationS = duration_cast<milliseconds>(end - start);
    cout << durationS.count() << endl;

    cout << endl;



    return 0;
}

void readingVec(vector<string>& v) {
    string read;
    ifstream file("codes.txt");
    while(getline(file, read)) {
        v.push_back(read);
    }
    file.close();
}

void readingList(list<string>& l) {
    string read;
    ifstream file("codes.txt");
    while(getline(file, read)) {
        l.push_back(read);
    }
    file.close();
}

void readingSet(set<string>& s) {
    string read;
    ifstream file("codes.txt");
    while(getline(file, read)) {
        s.insert(read);
    }
    file.close();
}

void sorting


/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/