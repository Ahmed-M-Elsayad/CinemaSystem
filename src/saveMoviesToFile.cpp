#include "saveMoviesToFile.h"
#include "fileUtils.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void saveMoviesToFile(const vector<Movie>& movies) {
    ensureDataDirectory();
    ofstream file("data/movies.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open the movies file for saving!\n";
        return;
    }

    file << fixed << setprecision(2);   // عشان السعر ما يتقصّش (12345.67 -> 12345.7)

    for (const auto& m : movies) {
        file << m.movieId << "|" << m.name << "|" << m.genre << "|"
             << m.showtime << "|" << m.price << "|" << m.hallId << "|" << m.status << "\n";

        const size_t rows = m.seats.size();
        const size_t cols = (rows > 0) ? m.seats[0].size() : 0;
        file << rows << "|" << cols << "\n";

        for (const auto& row : m.seats) {
            for (char seat : row) {
                file << seat;
            }
            file << "\n";
        }
    }

    if (!file) {
        cout << "Error: Failed while writing the movies file!\n";
        return;
    }
    cout << "Movies saved successfully.\n";
}
