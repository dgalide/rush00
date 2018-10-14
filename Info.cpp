#include "Info.hpp"
#include <net/route.h>
#include <net/if.h>
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
    char _name[name.length()+1];
    unsigned int       result;
    size_t  len = sizeof(result);

    std::strcpy (_name, name.c_str());
    sysctlbyname(_name, &result, &len, NULL, 256);
    return std::to_string(result);
}

void                Info::getNetStat(void) {
    int         mib[6] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0};
    char        *last;
    char        *tmp;
    size_t      size;
    struct      if_msghdr *ifm;

    this->ipackets = 0;
    this->opackets = 0;
    this->ibytes = 0;
    this->obytes = 0;

    sysctl(mib, 6, NULL, &size, NULL, 0);
    char buff[size];
    sysctl(mib, 6, buff, &size, NULL, 0);

    last = buff + size;

    for (tmp = buff; tmp < last; ) {
        ifm = (struct if_msghdr *)tmp;
        tmp += ifm->ifm_msglen;

        if (ifm->ifm_type == RTM_IFINFO2) {
            struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;

                this->opackets += if2m->ifm_data.ifi_opackets;
                this->ipackets += if2m->ifm_data.ifi_ipackets;
                this->obytes += if2m->ifm_data.ifi_obytes;
                this->ibytes  += if2m->ifm_data.ifi_ibytes;
        }
    }
}

struct tcpstat        Info::getNetTcpStat(std::string name) {
    char _name[name.length()+1];
    struct tcpstat stat;
    size_t oldlen = sizeof(struct ipstat);

	sysctlbyname(_name, &stat, &oldlen, NULL, 256);
    return stat;
}

std::string         Info::getDate(void) {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return (std::string(buf));
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