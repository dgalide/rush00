#include "NetworkModule.hpp"

NetworkModule::NetworkModule(std::string title): Info(), title(title) {
    this->items = new std::vector<Item*>();

    this->received = new Item("Total Packets Received : ", std::to_string(this->getNetStat(M_NET_STAT).ips_total));
    this->generatedHere = new Item("Total Packets Generated Here : ", std::to_string(this->getNetStat(M_NET_STAT).ips_localout));
    this->tcpTotalIn = new Item("Total TCP in : ", std::to_string(this->getNetTcpStat(M_NET_TCP_STAT).tcps_sndtotal));
    this->tcpTotalOut = new Item("Total TCP out : ", std::to_string(this->getNetTcpStat(M_NET_TCP_STAT).tcps_rcvtotal));

    this->addItem(this->received);
    this->addItem(this->generatedHere);
    this->addItem(this->tcpTotalIn);
    this->addItem(this->tcpTotalOut);
}

NetworkModule::~NetworkModule(void) {
    delete this->generatedHere;
    delete this->received;
    delete this->tcpTotalIn;
    delete this->tcpTotalOut;
    delete this->items;
}

NetworkModule::NetworkModule(NetworkModule const &ref) {
    (void)ref;
}

void            NetworkModule::refresh(void) {
    this->received->setValue(std::to_string(this->getNetStat(M_NET_STAT).ips_total));
    this->generatedHere->setValue(std::to_string(this->getNetStat(M_NET_STAT).ips_localout));
    this->tcpTotalIn->setValue(std::to_string(this->getNetTcpStat(M_NET_TCP_STAT).tcps_sndtotal));
    this->tcpTotalOut->setValue(std::to_string(this->getNetTcpStat(M_NET_TCP_STAT).tcps_rcvtotal));
}

void            NetworkModule::addItem(Item *item) {
    this->items->push_back(item);
}