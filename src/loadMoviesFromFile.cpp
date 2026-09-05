#include "loadMoviesFromFile.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void loadMoviesFromFile(vector<Movie>& movies) { 

	movies.clear(); // مسح البيانات 

    ifstream moviesFile("data/movies.txt");

    if (moviesFile.is_open()) { 
        string line; //قراه الملف سطر بسطر

        while (getline(moviesFile, line))  {

            if (line.empty()) continue; // تخطي الأسطر الفارغة

            stringstream ss(line); // تقسيم السطر إلى أجزاء باستخدام '|' كفاصل
            string segment;

            Movie m;

            // 1. قراءة البيانات الأساسية للفيلم (مفصولة بـ |)
			getline(ss, segment, '|'); m.movieId = stoi(segment); // تحويل النص إلى عدد صحيح
            getline(ss, segment, '|'); m.name = segment;
            getline(ss, segment, '|'); m.genre = segment;
            getline(ss, segment, '|'); m.showtime = segment;
            getline(ss, segment, '|'); m.price = stod(segment);
            getline(ss, segment, '|'); m.hallId = stoi(segment);
            getline(ss, segment, '|'); m.status = segment;

            // 2. قراءة أبعاد مصفوفة المقاعد (سطر الأبعاد: rows|cols)
            string dimLine;
            getline(moviesFile, dimLine);
            stringstream dimss(dimLine);
            string dimSegment;
            int rows, cols;
            getline(dimss, dimSegment, '|'); rows = stoi(dimSegment);
            getline(dimss, dimSegment, '|'); cols = stoi(dimSegment);

            
            m.seats.clear();
			for (int i = 0; i < rows; i++) { 
                string rowStr;
                getline(moviesFile, rowStr); 
				vector<char> rowVec(rowStr.begin(), rowStr.end()); // تحويل السطر إلى مصفوفة من الأحرف
				m.seats.push_back(rowVec);  // إضافة الصف إلى مصفوفة المقاعد
            }

            movies.push_back(m);
        }
        moviesFile.close();
        cout << "Movies loaded successfully from movies\n";
    }
    else {
        cout << "Error: Could not open movies for reading!\n";
    }
}