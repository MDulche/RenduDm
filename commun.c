#include <stdio.h>
#include <stdbool.h>
#include "commun.h"

// partie 1


bool verifIp(unsigned int octetIp1, unsigned int octetIp2, unsigned int octetIp3, unsigned int octetIp4)
{

/*
Vérifie si les octets d'une adresse IP sont valides.
Une adresse IP est valide si chaque octet est compris entre 0 et 255.
  
param octetIp1 Premier octet de l'adresse IP.
param octetIp2 Deuxième octet de l'adresse IP.
param octetIp3 Troisième octet de l'adresse IP.
param octetIp4 Quatrième octet de l'adresse IP.

return true si l'adresse IP est valide, false sinon.
*/

    //Vérification des Octets de l'Ip
    if ((octetIp1 <= 255 && octetIp1 >= 0) && (octetIp2 <= 255 && octetIp2 >= 0) && (octetIp3 <= 255 && octetIp3 >= 0) && (octetIp4 <= 255 && octetIp4 >= 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int entreeIp()
{

/*
Saisie et affichage d'une adresse IP en 32 bits si elle est valide.
*/

    //Initialisation des variables des Octets de l'Ip
    unsigned int octetIp1 = -1, octetIp2 = -1, octetIp3 = -1, octetIp4 = -1,ip;
    int compteur, bit, bit_precedent = 1;

    //Récupération des Octets de l'Ip
    printf("Saisir une adresse IP: ");
    scanf("%u.%u.%u.%u", &octetIp1, &octetIp2, &octetIp3, &octetIp4);
    printf("\n%u.%u.%u.%u\n", octetIp1, octetIp2, octetIp3, octetIp4);

    ip = (octetIp1 << 24)|(octetIp2 << 16)|(octetIp3 << 8)|octetIp4;

    //Vérification des Octet de l'Ip
    if (verifIp(octetIp1, octetIp2, octetIp3, octetIp4))
    {
        printf("adresse IP (32 bits): ");

        //Affichage en binaire
        for (int i = 31; i >= 0; i--)
        {
            bit = (ip >> i) & 1;
            printf("%d", bit);
            bit_precedent = bit;
        }
    }
    else
    {
        
        printf("Erreur saisie incorrecte\n");

    }
    
    //Retour a la ligne
    printf("\n");
    
    return ip;
}


//Partie 2

bool verifMasque(unsigned int octetMasque1, unsigned int octetMasque2, unsigned int octetMasque3, unsigned int octetMasque4, unsigned int masque)
{

/*
Vérifie si un masque de sous-réseau est valide.
Un masque valide a des bits consécutifs à 1 suivis de bits à 0 (pas de transition 1 -> 0 -> 1).
 
param octetMasque1 Premier octet du masque.
param octetMasque2 Deuxième octet du masque.
param octetMasque3 Troisième octet du masque.
param octetMasque4 Quatrième octet du masque.
param masque Représentation sur 32 bits du masque.

return true si le masque est valide, false sinon.
 */

    //Initialisation des variables de vérification
    int compteur, decompte = 0, bit, bit_precedent = 1;

    //Vérification des Octets du Masque
    if ((octetMasque1 <= 255 && octetMasque1 >= 0) && (octetMasque2 <= 255 && octetMasque2 >= 0) && (octetMasque3 <= 255 && octetMasque3 >= 0) && (octetMasque4 <= 255 && octetMasque4 >= 0))
    {

        for (int i = 31; i >= 0; i--)
        {
            bit = (masque >> i) & 1;

            if (bit != bit_precedent)
            {
                decompte++;
            }
            
            bit_precedent = bit;
        }

        // a changer par rapport a la classe de l'ip
        if (decompte > 2)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
    else
    {

        return false;

    }
}

unsigned int entreeMasque()
{

/*
Saisie et affichage d'un masque de sous-réseau si valide.
*/

    //Initialisation des variables des Octets du Masque
    unsigned int octetMasque1 = -1, octetMasque2 = -1, octetMasque3 = -1, octetMasque4 = -1,masque;
    int compteur, bit, bit_precedent = 1;
    

    //Récupération des Octets du Masque
    printf("Saisir un masque de sous-réseau: ");
    scanf("%u.%u.%u.%u", &octetMasque1, &octetMasque2, &octetMasque3, &octetMasque4);
    printf("\n%u.%u.%u.%u\n", octetMasque1, octetMasque2, octetMasque3, octetMasque4);

    masque = (octetMasque1 << 24)|(octetMasque2 << 16)|(octetMasque3 << 8)|octetMasque4;

    //Vérification des Octets du Masque
    if (verifMasque(octetMasque1, octetMasque2, octetMasque3, octetMasque4, masque))
    {
        printf("masque sous-réseau (32 bits): ");

        //Affichage en binaire
        for (int i = 31; i >= 0; i--)
        {
            bit = (masque >> i) & 1;
            printf("%d", bit);
            bit_precedent = bit;
        }
    }
    else
    {
        
        printf("Erreur saisie incorrecte");

    }
    
    //Retour a la ligne
    printf("\n");

    return masque;
}


//Partie 3

void ipReseau(unsigned int ip, unsigned int masque)
{
    //Initialisation des variables des Octets de l'Ip réseau
    unsigned int octetReseau1 = 0, octetReseau2 = 0, octetReseau3 = 0, octetReseau4 = 0;
    int octetIp, octetMasque;

    for (int i = 24; i >= 0; i -= 8)
        {
            octetIp = (ip >> i) & 255;
            octetMasque = (masque >> i) & 255;

            switch (i)
            {

            case 24:

                octetReseau1 = octetIp & octetMasque;

                break;
            
            case 16:
                
                octetReseau2 = octetIp & octetMasque;

                break;

            case 8:

                octetReseau3 = octetIp & octetMasque;

                break;

            case 0:
                
                octetReseau4 = octetIp & octetMasque;                

                break;

            default:
                break;
            }
        }

    printf("Adresse réseau: %u.%u.%u.%u\n", octetReseau1, octetReseau2, octetReseau3, octetReseau4);

}