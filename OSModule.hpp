#ifndef OSMODULE_HPP
 #define OSMODULE_HPP

#include "Info.hpp"
#include "Item.hpp"

#define M_KERN_TYPE "kern.ostype"
#define M_KERN_VERSION "kern.version"
#define M_KERN_RELEASE "kern.osrelease"

class Info;

class OSModule: public Info {

    public:

        OSModule(std::string title);
        ~OSModule(void);
        OSModule(OSModule const &ref);

        /**
         * Methods
         */
        void        refresh(void);
        void        addItem(Item *item);

        /**
         * Getters
         */
        Item         *getVersion(void) const;
        Item         *getRelease(void) const;
        Item         *getType(void) const;

        std::vector<Item*>  *items;
        std::string         title;

    private:

        OSModule    &operator=(OSModule &ref);

        Item        *version;
        Item        *release;
        Item        *type;
};

#endif