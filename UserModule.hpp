#ifndef USERMODULE_HPP
 #define USERMODULE_HPP

#include "Info.hpp"
#include "Item.hpp"

class Info;

class UserModule: public Info {

    public:

        UserModule(std::string title);
        ~UserModule(void);

        /**
         * Methods
         */
        void        refresh(void);
        void        addItem(Item *item);

        std::vector<Item*>  *items;
        std::string         title;

    private:

        UserModule    &operator=(UserModule &ref);
        UserModule(UserModule const &ref);

        Item        *hostname;
        Item        *username;
};

#endif