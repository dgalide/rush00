#ifndef INFO_HPP
 #define INFO_HPP

#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <limits.h>
#include <mach/vm_statistics.h>
#include <mach/mach_init.h>
#include <mach/mach_types.h>
#include <mach/mach_host.h>

class Info {

    public:

        /**
         * Constructor / Destructor
         */
        Info(void);
        ~Info(void);

        std::string             getInfoByName(std::string name);
        std::string             getUsername(void);
        std::string             getHostname(void);
        vm_statistics_data_t    getVmStat(void);

    private:
        Info &operator=(Info const &ref);
        Info(Info const &ref);

};

#endif