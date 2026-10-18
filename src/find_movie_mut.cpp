#include "find_movie.h"
#include <algorithm>

Movie* findMovieById(vector<Movie>& movies, int movieId) {
    const auto it = find_if(movies.begin(), movies.end(),
        [movieId](const Movie& m) { return m.movieId == movieId; });
    return it != movies.end() ? &*it : nullptr;
}
