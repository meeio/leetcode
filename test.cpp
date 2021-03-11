#include <cstdio>
#include <iostream>
#include <stdlib.h>
union demo
{
    int  type_int;
    char type_char;
};

bool is_big_end()
{
    static demo a{
        .type_int = 1
    };

    return (int)a.type_char == 1;
}

int main()
{
    int   a  = 0x11223344;
    int*  pi = &a;
    char* pc = (char*)pi; //指针强转
    printf("is_big_end %d", is_big_end());  //输出 44 ，得到证实
    return 0;
}

