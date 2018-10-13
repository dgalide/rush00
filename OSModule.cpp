#include "OSModule.hpp"

OSModule::OSModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();

    this->release = new Item("Release :", this->getInfoByName(M_KERN_RELEASE));
    this->version = new Item("Version :", this->getInfoByName(M_KERN_VERSION));
    this->type = new Item("Type :", this->getInfoByName(M_KERN_TYPE));

    this->addItem(this->release);
    this->addItem(this->version);
    this->addItem(this->type);
}

OSModule::~OSModule(void) {
    delete this->release;
    delete this->type;
    delete this->version;
    delete this->items;
}

void            OSModule::refresh(void) {
    this->version->setValue(this->getInfoByName(M_KERN_VERSION));
    this->release->setValue(this->getInfoByName(M_KERN_RELEASE));
    this->type->setValue(this->getInfoByName(M_KERN_TYPE));
}

Item     *OSModule::getRelease(void) const {
    return this->release;
}

Item     *OSModule::getVersion(void) const {
    return this->version;
}

Item     *OSModule::getType(void) const {
    return this->type;
}

void            OSModule::addItem(Item *item) {
    this->items->push_back(item);
}