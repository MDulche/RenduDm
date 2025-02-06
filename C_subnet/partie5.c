#include <stdio.h>

#include "commun.h"

int main()
{
    unsigned int masque = entreeMasque();
    CIDR(masque);
    return 0;
}