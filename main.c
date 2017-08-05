/*pascal.c*/

/*
Projekt: pascal
*/

/*
History:
	FS 13.04.2015 erstellt
	FS 20.04.2015 entwickelt
*/


#include <stdio.h>
#include <stdlib.h>


int Binominalkoeffizienten(int iN /*Variable fuer Zeile*/, int iK /*Variable fuer Spalte*/);    //Parametertypliste
int Binominalkoeffizienten(int iN /*Variable fuer Zeile*/, int iK /*Variable fuer Spalte*/)     //Funktion
{
    int iErg;    //Ergebniss Variable
    int iTemp1;  //Zwischenvariable
    int iTemp2;  //Zwischenvariable

    if(iN == iK || iK == 0)
    {
        iErg = 1;       //Rekursionsende
    }
    else
    {
        iTemp1 = Binominalkoeffizienten(iN -1, iK -1);  //Rekursionsschritt
        iTemp2 = Binominalkoeffizienten(iN -1, iK);     //Rekursionsschritt

        iErg = iTemp1 + iTemp2;     //Berechnung (Pascalsche Dreieck)
    }

    return(iErg);       //Rueckgabewert ist Ergebnis
}


int main(void);
int main()
{
    /*
    Dieses Modul soll rekursiv Binominalkoeffizienten mit
    Hilfe des Pascalische Dreieck berechnen.
    */

    /*
    Variablen deklarationen
    */
    int iN;       //Variable fuer Zeile n
    int iK;       //Variable fuer Spalte k
    int iBinom;   //Variable fuer Binominalkoeffizenten




    /*
    Einlesen der Zeile und Spalte
    */
    printf("+++ Binominalkoeffizienten Berechnung +++\n\n");

    do
    {
        printf("Geben Sie nun die Spalte k ein: ");
        scanf("%d", &iK);
        printf("Geben Sie die Zeile n ein: ");
        scanf("%d", &iN);

        if(iN < iK)
        {
            printf("!!! Die Spalte k darf nicht groesser sein als die Zeile n !!!\n\n");    //Fehlermeldung
        }
    }while(iN < iK);       //Sicherrung, die Spalte darf nicht groeßer als die Zeile sein




    /*
    Funktionsaufrufe und Ausgabe
    */
    iBinom = Binominalkoeffizienten(iN , iK);       //Funktionsaufruf

    printf("\n\nDer Binominalkoeffizient fuer n = %d und k = %d lautet: %d\n\n\n", iN, iK, iBinom);


    return 0;
}
