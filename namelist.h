#pragma once
#include "matrix.h"

template<typename type>
class NAME_LIST{
    struct BLOCK{
        std::string name;
        type *pData;
        BLOCK *nextBlock;
    };
    BLOCK *list, *bottomList, *temp;
    public:
        NAME_LIST();
        ~NAME_LIST();
        void Add(std::string, type *);
        void Remove(std::string);
        void Save();
        void Load();    //WIP
        type &Search(std::string);
        //  inline void Assign(std::string, type *);
        
};