#include "UserModule.hpp"

UserModule::UserModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();
}

UserModule::~UserModule(void) {
    delete this->items;
}

UserModule::UserModule(UserModule const &ref) {
    (void)ref;
}

void            UserModule::refresh(void) {
}

void            UserModule::addItem(Item *item) {
    this->items->push_back(item);
}