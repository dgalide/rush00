#ifndef DATEMODULE_HPP
 #define DATEMODULE_HPP

#include "Info.hpp"
#include "Item.hpp"

class Info;

class DateModule: public Info {

    public:

        DateModule(std::string title);
        ~DateModule(void);

        /**
         * Methods
         */
        void        refresh(void);
        void        addItem(Item *item);

        std::vector<Item*>  *items;
        std::string         title;

    private:

        DateModule    &operator=(DateModule &ref);
        DateModule(DateModule const &ref);
};

#endif