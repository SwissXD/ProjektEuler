//--------------------------
// ProjektEuler 10
// Tkel
// Data xx.xx.xx
//--------------------------
#include <iostream>
namespace PE010
{
    unsigned long long PrimzahlenBerechnen(unsigned long limit)
    {
        unsigned long long SumOfPrims = 0;
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
                SumOfPrims += i;
        }
        return SumOfPrims;
    }


    void _main()
    {
        unsigned long long summe  = PrimzahlenBerechnen(200000);
        std::cout << "Summe der Primzahlen bis 2mio " << summe << std::endl;
    }
}

