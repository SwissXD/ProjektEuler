//--------------------------
// ProjektEuler 3
// Tkel
// Data xx.xx.xx
//--------------------------

#include <iostream>
#include <vector>

namespace PE003
{
    std::vector<unsigned> PrimzahlenBerechnen(unsigned limit)
    {
        std::vector<unsigned> Prims;
        for(unsigned i  = 2; i < limit; ++i)
        {
            bool primzahl = true;
            for(unsigned j = 2; j <= i/2 && primzahl == true; ++j)
            {
                if(i%j == 0)
                {
                    primzahl = false;
                }
            }
            if(primzahl)
                Prims.push_back(i);
        }
        return Prims;
    }

    std::vector<unsigned> Primfaktorzerlegung(unsigned long long Zahl)
    {
        std::cout << Zahl << std::endl;
        std::vector<unsigned> Primzahlen = PrimzahlenBerechnen(20000);
        std::vector<unsigned> Faktoren;

        unsigned counter = 0;
        unsigned long long rest = Zahl;
        while(Zahl > 1  && counter < Primzahlen.size())
        {
            rest = Zahl/Primzahlen[counter];
            if(rest*Primzahlen[counter] == Zahl)
            {
                Faktoren.push_back(Primzahlen[counter]);
                Zahl /= Primzahlen[counter];
                counter = 0;
            }
            else
            {
                ++counter;
            }
        }
        return Faktoren;
    }


    void _main()
    {
        std::vector<unsigned> Faktoren = Primfaktorzerlegung(600851475143);
        for(std::size_t i = 0; i < Faktoren.size(); ++i)
        {
            std::cout << Faktoren[i] << ' ';
        }
        std::cout <<  std::endl;
    }


}
