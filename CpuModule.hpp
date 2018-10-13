#ifndef CPUMODULE_HPP
 #define CPUMODULE_HPP

#include "Info.hpp"
#include "Item.hpp"

#define M_BRAND "machdep.cpu.brand_string"
#define M_CACHE_SIZE "machdep.cpu.cache.size"
#define M_CORE_COUNT "machdep.cpu.core_count"
#define M_MODEL "machdep.cpu.model"
#define M_THREAD_COUNT "machdep.cpu.thread_count"
#define M_FREQUENCY "machdep.tsc.frequency"

class Info;

class CpuModule: public Info {

    public:

        CpuModule(std::string title);
        ~CpuModule(void);

        /**
         * Methods
         */
        void        refresh(void);
        void        addItem(Item *item);

        std::vector<Item*>  *items;
        std::string         title;

    private:

        CpuModule    &operator=(CpuModule &ref);
        CpuModule(CpuModule const &ref);

        Item        *brand;
        Item        *cacheSize;
        Item        *coreCount;
        Item        *model;
        Item        *threadCount;
        Item        *frequency;

};

#endif