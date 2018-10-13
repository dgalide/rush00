#include "Info.hpp"

Info::Info(void) {}

Info::~Info(void) {}

Info        &Info::operator=(Info const &ref) {
    if (this != &ref) {
        *this = ref;
    }
    return *this;
}

std::string        Info::getInfoByName(std::string name) {
    char *_name = new char[name.length() + 1];
    char out[256];
    size_t s = sizeof(out);
    
    std::strcpy(_name, name.c_str());
    sysctlbyname(_name, &out, &s, NULL, 256);
    return out;
}

std::string         Info::getHostname(void) {
    char hostname[256];
    int result;
    result = gethostname(hostname, 256);
    return std::string(hostname);
}

std::string         Info::getUsername(void) {
    struct passwd *pw;
    uid_t uid;

    uid = getuid();
    pw = getpwuid(uid);
    if (pw)
        return (pw->pw_name);
  return (NULL);
}