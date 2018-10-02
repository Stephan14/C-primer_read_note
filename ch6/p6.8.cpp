#include <iostream>
int generate()
{
    static int ctr = 0;
    return ctr++;
}
