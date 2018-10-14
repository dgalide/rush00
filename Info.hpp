#ifndef INFO_HPP
 #define INFO_HPP

#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <limits.h>
#include <mach/vm_statistics.h>
#include <mach/mach_init.h>
#include <mach/mach_types.h>
#include <mach/mach_host.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>

class Info {

    public:

        /**
         * Constructor / Destructor
         */
        Info(void);
        ~Info(void);

        std::string             getInfoByName(std::string name);
        std::string             getInfoByNameInt(std::string name);
        std::string             getUsername(void);
        std::string             getHostname(void);
        vm_statistics_data_t    getVmStat(void);
        void                    getNetStat(void);
        struct tcpstat          getNetTcpStat(std::string name);
        std::string             getDate(void);

        long int    ipackets;
        long int    opackets;
        long int    ibytes;
        long int    obytes;

    private:
        Info &operator=(Info const &ref);
        Info(Info const &ref);

};

#endif