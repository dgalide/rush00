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
    char _name[name.length() + 1];
    char out[256];
    size_t s = sizeof(out);
    
    std::strcpy(_name, name.c_str());
    sysctlbyname(_name, &out, &s, NULL, 256);
    return out;
}

std::string        Info::getInfoByNameInt(std::string name) {
    char cstr[name.length()+1];
    unsigned int       result;
    size_t  len = sizeof(result);

    std::strcpy (cstr, name.c_str());
    sysctlbyname(cstr, &result, &len, 0, 256);
    return std::to_string(result);
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

vm_statistics_data_t    Info::getVmStat(void) {
    mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
    vm_statistics_data_t vmstat;

    host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count);
    return vmstat;
}