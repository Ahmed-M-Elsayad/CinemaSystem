#pragma once

#include "CinemaData.h"

const Movie* findMovieById(const std::vector<Movie>& movies, int movieId);
Movie* findMovieById(std::vector<Movie>& movies, int movieId);
