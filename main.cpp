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
#include <algorithm>
using namespace std;
using namespace std::chrono;

// function prototypes
void readingVec(vector<string>&);
void readingList(list<string>&);
void readingSet(set<string>&);

void sortingVec(vector<string>&);
void sortingList(list<string>&);
void sortingSet(set<string>&);

void insertingVec(vector<string>&, string);
void insertingList(list<string>&, string);
void insertingSet(set<string>&, string);

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

    // sorting
    start = high_resolution_clock::now();
    sortingVec(testv);
    end = high_resolution_clock::now();
    auto sortDurationV = duration_cast<milliseconds>(end - start);
    cout << sortDurationV.count() << endl;

    start = high_resolution_clock::now();
    sortingList(testl);
    end = high_resolution_clock::now();
    auto sortDurationL = duration_cast<milliseconds>(end - start);
    cout << sortDurationL.count() << endl;

    sortingSet(tests);

    cout << endl;

    // inserting
    insertingVec(testv, "TESTCODE");

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

void sortingVec(vector<string>& v) {
    sort(v.begin(), v.end());
}

void sortingList(list<string>& s) {
    s.sort();
}

void sortingSet(set<string>& s) {
    cout << "-1" << endl;
}

void insertingVec(vector<string>& v, string stringInsert) {
    int middle = v.size() / 2;
    v.insert(v.begin() + middle, stringInsert);
}

void insertingList(list<string>&, string stringInsert) {

}

void insertingSet(set<string>&, string stringInsert) {

}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/