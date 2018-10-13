#include "DateModule.hpp"

DateModule::DateModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();
    this->date = new Item("Date :", this->getDate());

    this->addItem(this->date);
}

DateModule::~DateModule(void) {
    delete this->date;
    delete this->items;
}

void            DateModule::refresh(void) {
    this->date->setValue(this->getDate());
}

void            DateModule::addItem(Item *item) {
    this->items->push_back(item);
}