#include "namelist.h"
#include "namelist.cpp"

int WIDTH = 13;

int main(int argc, char const *argv[])
{   
///*
    int m , n;
///*
    sscanf(argv[1], "%d", &m);
    sscanf(argv[2], "%d", &n);
    //  std::cout<< m<< n<< std::endl;
/*
    std::cout<< "Enter the size of matrices (m, n):"<< std::endl;
    const char *input0;
    if(input0 != "\n"){
        sscanf(input0, "%lf", &m);
        std::cin>> n;
    }
//*
    std::cin>> m;
    std::cin>> n;
//*/
    Matrix::MATRIX a(m, n);
    Matrix::MATRIX b(m, n);
    Matrix::MATRIX c(m, n);
    Matrix::MATRIX d(n, m);
    Matrix::MATRIX e(m, m);
    Matrix::MATRIX f(m, m);
//  Fill matrices
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            a.element(i, j) = double(i) +- double(j) + 4;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            b.element(i, j) = double(i)*double(i) - double(j);
    c = a + b;
    d = ~b;
    e = -c * d;
    f = (a + b) * ~b;
/*  Display matrices
    a.display(WIDTH);
    b.display(WIDTH);
    c.display(WIDTH);
    d.display(WIDTH);
    e.display(WIDTH);
    f.display(WIDTH);
//*/
    ///*
    NAME_LIST<Matrix::MATRIX> nameList;
    nameList.Add("first_matrix", &a);
///*
    nameList.Add("second_matrix", &b);
    nameList.Add("third_matrix", &c);
    nameList.Add("fourth_matrix", &d);
    nameList.Add("fifth_matrix", &e);
    nameList.Add("sixth_matrix", &f);
    nameList.Save();
    nameList.Search("fourth_matrix").element(0, 0) = 754;
//*/
    nameList.Save();
    //  nameList.Search("fourth_matrix").display(WIDTH);
//*/
    return 0;
}
