#include "loadMoviesFromFile.h"
#include "fileUtils.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static constexpr int MAX_DIMENSION = 100;

static bool parseMovieHeader(const string& line, Movie& m) {
    const auto f = splitLine(line);
    if (f.size() < 7 || !parseInt(f[0], m.movieId) || !parseDouble(f[4], m.price)
        || !parseInt(f[5], m.hallId)) {
        return false;
    }
    m.name = f[1];
    m.genre = f[2];
    m.showtime = f[3];
    m.status = f[6];
    return true;
}

static bool readSeatMap(istream& in, Movie& m) {
    string line;
    if (!readLine(in, line)) return false;

    const auto d = splitLine(line);
    int rows = 0;
    int cols = 0;
    if (d.size() < 2 || !parseInt(d[0], rows) || !parseInt(d[1], cols)
        || rows < 0 || rows > MAX_DIMENSION || cols < 0 || cols > MAX_DIMENSION) {
        return false;
    }

    m.seats.clear();
    for (int i = 0; i < rows; ++i) {
        string rowStr;
        if (!readLine(in, rowStr) || rowStr.size() != static_cast<size_t>(cols)) {
            return false;
        }
        m.seats.emplace_back(rowStr.begin(), rowStr.end());
    }
    return true;
}

void loadMoviesFromFile(vector<Movie>& movies) {
    movies.clear();

    ifstream file("data/movies.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open movies file for reading!\n";
        return;
    }

    string line;
    while (readLine(file, line)) {
        if (line.empty()) continue;

        Movie m;
        if (!parseMovieHeader(line, m) || !readSeatMap(file, m)) {
            cerr << "Warning: movies file is corrupted, stopped loading.\n";
            break;
        }
        movies.push_back(m);
    }
    cout << "Movies loaded successfully from movies file.\n";
}
