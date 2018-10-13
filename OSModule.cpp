#include "OSModule.hpp"

OSModule::OSModule(void): Info() {
    this->refresh();
}

OSModule::~OSModule(void) {}

OSModule::OSModule(OSModule const &ref) {
    (void)ref;
}

void            OSModule::refresh(void) {
    this->release = this->getInfoByName(M_KERN_RELEASE);
    this->version = this->getInfoByName(M_KERN_VERSION);
    this->type = this->getInfoByName(M_KERN_TYPE);
}

std::string     OSModule::getRelease(void) const {
    return this->release;
}

std::string     OSModule::getVersion(void) const {
    return this->version;
}

std::string     OSModule::getType(void) const {
    return this->type;
}