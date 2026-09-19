#include<iostream>
#include "add.h"
#include "sub.h"

int main()
{
    std::cout<<"this is my first cmake program"<<std::endl;
    std::cout<<"add function,1+2="<<add(1,2)<<std::endl;
    std::cout<<"add function,1-2="<<sub(1,2)<<std::endl;

    return 0;
}