#include "UserModule.hpp"

UserModule::UserModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();

    this->hostname = new Item(static_cast<std::string>("Hostname :"), this->getHostname());
    this->username = new Item(static_cast<std::string>("Username :"), this->getUsername());

    this->addItem(this->hostname);
    this->addItem(this->username);
}

UserModule::~UserModule(void) {
    delete this->hostname;
    delete this->username;
    delete this->items;
}

UserModule::UserModule(UserModule const &ref) {
    (void)ref;
}

void            UserModule::refresh(void) {
    this->hostname->setValue(this->getHostname());
    this->username->setValue(this->getUsername());
}

void            UserModule::addItem(Item *item) {
    this->items->push_back(item);
}