#ifndef OSMODULE_HPP
 #define OSMODULE_HPP

#include "Info.hpp"

#define M_KERN_TYPE "kern.ostype"
#define M_KERN_VERSION "kern.version"
#define M_KERN_RELEASE "kern.osrelease"

class Info;

class OSModule: public Info {

    public:

        OSModule(void);
        ~OSModule(void);
        OSModule(OSModule const &ref);

        OSModule    &operator=(OSModule &ref);

        /**
         * Methods
         */
        void        refresh(void);

        /**
         * Getters
         */
        std::string         getVersion(void) const;
        std::string         getRelease(void) const;
        std::string         getType(void) const;

    private:

        std::string         version;
        std::string         release;
        std::string         type;
};

#endif