#ifndef SHA256_H
#define SHA256_H

#include <string>

// SHA-256 كنص hex (64 حرف). تنفيذ تعليمي بدون مكتبات خارجية.
std::string sha256Hex(const std::string& data);

#endif
