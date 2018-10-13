#ifndef INFO_HPP
 #define INFO_HPP

#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>

class Info {

    public:

        /**
         * Constructor / Destructor
         */
        Info(void);
        Info(Info const &ref);
        ~Info(void);

        Info &operator=(Info const &ref);

        std::string         getInfoByName(std::string name);
};

#endif