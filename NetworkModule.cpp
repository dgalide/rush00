#include "NetworkModule.hpp"
#include <net/route.h>
#include <net/if.h>
#include <sys/sysctl.h>

NetworkModule::NetworkModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();

    this->_ipackets = new Item("Packets IN : ", "0");
    this->_opackets = new Item("Packets OUT : ", "0");
    this->_ibytes = new Item("Bytes IN : ", "0");
    this->_obytes = new Item("Bytes OUT : ", "0");
    this->addItem(this->_ipackets);
    this->addItem(this->_opackets);
    this->addItem(this->_ibytes);
    this->addItem(this->_obytes);
}

NetworkModule::~NetworkModule(void) {
    delete this->_opackets;
    delete this->_ipackets;
    delete this->_ibytes;
    delete this->_obytes;
    delete this->items;
}

NetworkModule::NetworkModule(NetworkModule const &ref) {
    (void)ref;
}

void            NetworkModule::refresh(void) {
    this->getNetStat();
    this->_ipackets->setValue(std::to_string(this->ipackets / 1000) + " k");
    this->_opackets->setValue(std::to_string(this->opackets / 1000) + " k");
    this->_ibytes->setValue(std::to_string(this->ibytes / 1000) + " mb");
    this->_obytes->setValue(std::to_string(this->obytes / 1000) + " mb");
}

void            NetworkModule::addItem(Item *item) {
    this->items->push_back(item);
}