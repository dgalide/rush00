#ifndef NETWORKMODULE_HPP
 #define NETWORKMODULE_HPP

#include "Info.hpp"
#include "Item.hpp"

#define M_NET_STAT "net.inet.ip.stats"
#define M_NET_TCP_STAT "net.inet.tcp.stats"

class Info;

class NetworkModule: public Info {

    public:

        NetworkModule(std::string title);
        ~NetworkModule(void);

        /**
         * Methods
         */
        void        refresh(void);
        void        addItem(Item *item);

        std::vector<Item*>  *items;
        std::string         title;

    private:

        NetworkModule    &operator=(NetworkModule &ref);
        NetworkModule(NetworkModule const &ref);

        Item        *received;
        Item        *generatedHere;
        Item        *tcpTotalIn;
        Item        *tcpTotalOut;
};

#endif