/*
 * comment pairs  cannot nest.
 * ‘‘cannot nest’’ is considered source code,
 * as is the rest of the program
 */
#include<iostream>

int main()
{
    std::cout << "/* s */";
    std::cout << "*/";
    //std::cout << /* "*/ " */;
    std::cout<< /* "*/ " /* " /*" */;
    return 0;
}