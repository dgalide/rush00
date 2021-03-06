#include "Item.hpp"
#include <iomanip>

std::vector<Item> allItem;

Item::Item(std::string label, std::string value): label(label), value(value) {}

Item::~Item(void) {};

void            Item::setValue(std::string value) {
    this->value = value;
}

std::string     Item::getFormat(void) {
    std::stringstream ss;

    ss << std::setfill (' ') << std::setw (20);
    ss << this->label;
    ss << "\t\t";
    ss << this->value;

    return ss.str();
}