#include "CpuModule.hpp"

CpuModule::CpuModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();

    this->brand = new Item("Brand :", this->getInfoByName(M_BRAND));
    this->model = new Item("Model :", this->getInfoByNameInt(M_MODEL));
    this->coreCount = new Item("Core Count :", this->getInfoByNameInt(M_CORE_COUNT));
    this->threadCount = new Item("Thread Count :", this->getInfoByNameInt(M_THREAD_COUNT));
    this->cacheSize = new Item("Cache Size :", this->getInfoByNameInt(M_CACHE_SIZE));

    this->addItem(this->brand);
    this->addItem(this->model);
    this->addItem(this->coreCount);
    this->addItem(this->threadCount);
    this->addItem(this->cacheSize);
}

CpuModule::~CpuModule(void) {
    delete this->items;
}

void            CpuModule::refresh(void) {
    this->brand->setValue(this->getInfoByName(M_BRAND));
    this->model->setValue(this->getInfoByNameInt(M_MODEL));
    this->coreCount->setValue(this->getInfoByNameInt(M_CORE_COUNT));
    this->threadCount->setValue(this->getInfoByNameInt(M_THREAD_COUNT));
    this->cacheSize->setValue(this->getInfoByNameInt(M_CACHE_SIZE));
}

void            CpuModule::addItem(Item *item) {
    this->items->push_back(item);
}