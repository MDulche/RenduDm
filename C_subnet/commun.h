#include <stdbool.h>

bool verifIp(unsigned int octetIp1, unsigned int octetIp2, unsigned int octetIp3, unsigned int octetIp4);
unsigned int entreeIp();

bool verifMasque(unsigned int octetMasque1, unsigned int octetMasque2, unsigned int octetMasque3, unsigned int octetMasque4, unsigned int masque);
unsigned int entreeMasque();

void adresseReseau(unsigned int ip, unsigned int masque);

void adresseBroadcast(unsigned int ip, unsigned int masque);

void CIDR(unsigned int masque);