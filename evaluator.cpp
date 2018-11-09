#include "evaluator.h"

template<typename type>
EVALUATOR<type>::EVALUATOR(NAME_LIST<type> &nameList){
    inputStream = "";
    this->nameList = nameList;
}

template<typename type>
EVALUATOR<type>::~EVALUATOR(){
    //  WIP
};

template<typename type>
void EVALUATOR<type>::CleanStream(){
    //  STL string manipulation to clean the "inputStream" string of
    //      any white spaces.
    
}