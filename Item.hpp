#ifndef ITEM_HPP
 #define ITEM_HPP

#include <iostream>
#include <vector>
#include <sstream>

class Item {

    public:

        Item(std::string label, std::string value);
        ~Item(void);
        Item(Item const &ref);
        
        Item                             &operator=(Item const &ref);

        std::vector<Item>        *allItem;
        void                     setValue(std::string);
        std::string              getFormat(void);

    private:

        std::string                     format;
        std::string                     label;
        std::string                     value;
};

#endif