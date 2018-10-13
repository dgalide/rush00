#ifndef RAMMODULE_HPP
 #define RAMMODULE_HPP

#include "Info.hpp"
#include "Item.hpp"

class Info;

class RamModule: public Info {

    public:

        RamModule(std::string title);
        ~RamModule(void);

        /**
         * Methods
         */
        void        refresh(void);
        void        addItem(Item *item);

        std::vector<Item*>  *items;
        std::string         title;

    private:

        RamModule    &operator=(RamModule &ref);
        RamModule(RamModule const &ref);

        Item *freeCount;
        Item *activeCount;
        Item *inactiveCount;
        Item *wiredCount;
};

#endif