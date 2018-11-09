#include "namelist.h"

template<typename type>
NAME_LIST<type>::NAME_LIST(){
        list = NULL;
        bottomList = NULL;
}

template<typename type>
NAME_LIST<type>::~NAME_LIST(){
    //  std::cout<< "NameList Deletion"<< std::endl;
    ///*
    while(list){
        temp = list->nextBlock;
        delete list;
        list = temp;
    }    
    //*/
}

template<typename type>
void NAME_LIST<type>::Add(std::string name, type *data){
    if(list == NULL){
        list = new BLOCK;
        bottomList = list;
        bottomList->name = name;
        bottomList->pData = data;
        bottomList->nextBlock = NULL;
    }
    else{
        bottomList->nextBlock = new BLOCK;
        bottomList = bottomList->nextBlock;
        bottomList->name = name;
        bottomList->pData = data;
        bottomList->nextBlock = NULL;
    }
}

template<typename type>
void NAME_LIST<type>::Remove(std::string name){
    //WIP
}

template<typename type>
void NAME_LIST<type>::Save(){
    std::fstream nameListFile;
    nameListFile.open(".name_list.txt", std::ios::in | std::ios::out | std::ios::trunc);
    if(!nameListFile.is_open()){
        //  File cannot be made
    }
    else{
        //  BLOCK *bottomList;
        bottomList = list;
        while(1){
            if(list == NULL){
                //  Empty name list
                break;
            }
            nameListFile<< bottomList-> name<< std::endl;
            bottomList->pData->OutStream(nameListFile);//<<std::endl;
            if(bottomList->nextBlock == NULL){
                //  End of list
                break;
            }
            bottomList = bottomList-> nextBlock;
        }
    }
    nameListFile.close();
}

template<typename type>
void NAME_LIST<type>::Load(){
    ///*  WIP
        
    //*/
}

template<typename type>
type &NAME_LIST<type>::Search(std::string name){
    temp = list;
    while(temp != NULL){
        if(temp->name == name){
            break;
        }
        temp = temp->nextBlock;
    }
    return *temp->pData;
}



/*  Temporary function only to declare objects
void TemporaryFunction(){
    NAME_LIST<Matrix::MATRIX> nameList;
}
//*/
/*
//  Test main program:>>
    int main(int argc, char const *argv[])
    {
        std::string a[] = {"dfasf", "This ", "shit. ", "is my "};
        NAME_LIST<std::string> nameList;
        nameList.Add("first_number", a + 1);
        nameList.Add("second_number", a + 3);
    //  const std::string fileName = ".name_list";
        nameList.Save();
        nameList.Add("third_number", a + 2);
        nameList.Save();
        NAME_LIST<Matrix::MATRIX> nameList2;
        int m = 1, n = 1;
        std::cout<< "Enter the size of matrices (m, n):"<< std::endl;
        std::cin>> m;
        std::cin>> n;
        Matrix::MATRIX ab(m, n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ab.element(i, j) = double(i) * double(j)/3 + 1;
        nameList2.Add("first_matrix", &ab);
        ab.display(4);
        return 0;
    }
//*/