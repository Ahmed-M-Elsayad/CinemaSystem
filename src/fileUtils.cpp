#include "fileUtils.h"
#include <exception>
#include <filesystem>

std::vector<std::string> splitLine(const std::string& line, char delim) {
    std::vector<std::string> parts;
    std::size_t start = 0;
    while (true) {
        const std::size_t pos = line.find(delim, start);
        if (pos == std::string::npos) {
            parts.push_back(line.substr(start));
            break;
        }
        parts.push_back(line.substr(start, pos - start));
        start = pos + 1;
    }
    return parts;
}

bool readLine(std::istream& in, std::string& line) {
    if (!std::getline(in, line)) {
        return false;
    }
    if (!line.empty() && line.back() == '\r') {
        line.pop_back();
    }
    return true;
}

bool parseInt(const std::string& text, int& out) {
    try {
        std::size_t pos = 0;
        const int value = std::stoi(text, &pos);
        if (pos != text.size()) {
            return false;
        }
        out = value;
        return true;
    }
    catch (const std::exception&) {
        return false;
    }
}

bool parseDouble(const std::string& text, double& out) {
    try {
        std::size_t pos = 0;
        const double value = std::stod(text, &pos);
        if (pos != text.size()) {
            return false;
        }
        out = value;
        return true;
    }
    catch (const std::exception&) {
        return false;
    }
}

void ensureDataDirectory() {
    std::error_code ec;
    std::filesystem::create_directories("data", ec);
}
