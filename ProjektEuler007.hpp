//--------------------------
// ProjektEuler 7
// Tkel
// Data xx.xx.xx
//--------------------------

#include <iostream>
#include <vector>
namespace PE007
{
    unsigned PrimzahlenBerechnen(unsigned NumberOFPrims)
    {
        unsigned currPrim = 1;
        unsigned detectetPrims = 0;
        for(unsigned i  = 2; NumberOFPrims != detectetPrims; ++i)
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
            {
                currPrim = i;
                ++detectetPrims;
            }
        }
        return currPrim;
    }

    void _main()
    {
        std::cout << "Prim :" << PrimzahlenBerechnen(10001) << std::endl;
    }
}

