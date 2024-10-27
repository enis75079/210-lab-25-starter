/*

lab25: data structures races
COMSC-210
Naveen Islam

*/
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;

int main() {
    vector<string> v;
    ifstream("codes.txt");
    while(getline())

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/