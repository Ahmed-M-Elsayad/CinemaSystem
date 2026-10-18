#include "find_hall.h"
#include <algorithm>

const Hall* findHallById(const vector<Hall>& halls, int hallId) {
    const auto it = find_if(halls.begin(), halls.end(),
        [hallId](const Hall& h) { return h.hallId == hallId; });
    return it != halls.end() ? &*it : nullptr;
}
