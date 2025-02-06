#include <stdio.h>

#include "commun.h"

int main()
{
    unsigned int ip = entreeIp();
    unsigned int masque = entreeMasque();
    adresseBroadcast(ip, masque);
    return 0;
}