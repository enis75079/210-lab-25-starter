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
int sortingSet(set<string>&);

void insertingVec(vector<string>&, string);
void insertingList(list<string>&, string);
void insertingSet(set<string>&, string);

int main() {
    vector<string> testv;
    list<string> testl;
    set<string> tests;

    // header
    cout << left << setw(10) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    
    // reading
    auto start = high_resolution_clock::now();
    readingVec(testv);
    auto end = high_resolution_clock::now();
    auto durationV = duration_cast<milliseconds>(end - start);

    start = high_resolution_clock::now();
    readingList(testl);
    end = high_resolution_clock::now();
    auto durationL = duration_cast<milliseconds>(end - start);

    start = high_resolution_clock::now();
    readingSet(tests);
    end = high_resolution_clock::now();
    auto durationS = duration_cast<milliseconds>(end - start);

    cout << left << setw(10) << "Read" << setw(10) << durationV.count() << setw(10) << durationL.count() << setw(10) << durationS.count() << endl;

    // sorting
    start = high_resolution_clock::now();
    sortingVec(testv);
    end = high_resolution_clock::now();
    auto sortDurationV = duration_cast<milliseconds>(end - start);

    start = high_resolution_clock::now();
    sortingList(testl);
    end = high_resolution_clock::now();
    auto sortDurationL = duration_cast<milliseconds>(end - start);

    cout << left << setw(10) << "Sort" << setw(10) << sortDurationV.count() << setw(10) << sortDurationL.count() << setw(10) << sortingSet(tests) << endl;

    cout << endl;

    // inserting
    insertingVec(testv, "TESTCODE");
    insertingList(testl, "TESTCODE");


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

int sortingSet(set<string>& s) {
    return -1;
}

void insertingVec(vector<string>& v, string stringInsert) {
    int middle = v.size() / 2;
    v.insert(v.begin() + middle, stringInsert);
}

void insertingList(list<string>& l, string stringInsert) {
    int middle = l.size() / 2;
    auto it = l.begin();
    advance(it, middle);
    l.insert(it, stringInsert);
}

void insertingSet(set<string>& s, string stringInsert) {
    s.insert(stringInsert);
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/