#pragma once
#include "namelist.h"

template<typename type>
class EVALUATOR{
    std::string inputStream;
    NAME_LIST<type> &nameList;
    public:
        EVALUATOR(NAME_LIST<type> &);
        ~EVALUATOR();
        void CleanStream();
        void Evaluate();
        void Display();
};