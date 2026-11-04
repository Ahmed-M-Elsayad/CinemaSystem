#pragma once

#include <istream>
#include <string>
#include <vector>

std::vector<std::string> splitLine(const std::string& line, char delim = '|');

bool readLine(std::istream& in, std::string& line);

bool parseInt(const std::string& text, int& out);
bool parseDouble(const std::string& text, double& out);

void ensureDataDirectory();
