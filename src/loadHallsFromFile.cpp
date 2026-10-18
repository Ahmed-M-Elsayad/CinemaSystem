#include "loadHallsFromFile.h"
#include "fileUtils.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static bool parseHall(const string& line, Hall& h) {
    const auto f = splitLine(line);
    int vip = 0;
    if (f.size() < 5 || !parseInt(f[0], h.hallId) || !parseInt(f[2], h.rows)
        || !parseInt(f[3], h.cols) || !parseInt(f[4], vip)) {
        return false;
    }
    h.name = f[1];
    h.isVip = (vip != 0);
    return true;
}

void loadHallsFromFile(vector<Hall>& halls) {
    halls.clear();

    ifstream file("data/halls.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open the halls file for loading!\n";
        return;
    }

    string line;
    int lineNo = 0;
    while (readLine(file, line)) {
        ++lineNo;
        if (line.empty()) continue;

        Hall h;
        if (!parseHall(line, h)) {
            cerr << "Warning: invalid hall at line " << lineNo << ", skipped.\n";
            continue;
        }
        halls.push_back(h);
    }
    cout << "The halls were successfully loaded from the halls file.\n";
}
