#include "RamModule.hpp"

RamModule::RamModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();

    this->freeCount = new Item("Free Ram :", std::to_string(this->getVmStat().free_count));
    this->activeCount = new Item("Active Ram :", std::to_string(this->getVmStat().active_count));
    this->inactiveCount = new Item("Inactive Ram :", std::to_string(this->getVmStat().inactive_count));
    this->wiredCount = new Item("Wired Ram :", std::to_string(this->getVmStat().wire_count));

    this->addItem(this->freeCount);
    this->addItem(this->activeCount);
    this->addItem(this->inactiveCount);
    this->addItem(this->wiredCount);
}

RamModule::~RamModule(void) {
    delete this->freeCount;
    delete this->activeCount;
    delete this->inactiveCount;
    delete this->wiredCount;
    delete this->items;
}

RamModule::RamModule(RamModule const &ref) {
    (void)ref;
}

void            RamModule::refresh(void) {
    this->freeCount->setValue(std::to_string(this->getVmStat().free_count));
    this->activeCount->setValue(std::to_string(this->getVmStat().active_count));
    this->inactiveCount->setValue(std::to_string(this->getVmStat().inactive_count));
    this->wiredCount->setValue(std::to_string(this->getVmStat().wire_count));
}

void            RamModule::addItem(Item *item) {
    this->items->push_back(item);
}