//--------------------------
// ProjektEuler 14
// Tkel
// Data xx.xx.xx
//--------------------------
#include <iostream>
namespace PE014
{
    void _main()
    {
        unsigned StartNumberWithLongestChain = 0;
        unsigned LongestChain = 1;
        for(std::size_t i  = 1; i < 1000000; ++i)
        {
            unsigned CurrStartNumber = i;
            unsigned ChainCounter = 1;
            while(CurrStartNumber != 1)
            {
               // std::cout << CurrStartNumber << std::endl;
                if((CurrStartNumber/2) * 2 == CurrStartNumber)
                //if(CurrStartNumber%2 == 0)
                {
                    CurrStartNumber /= 2;
                }
                else
                {
                    CurrStartNumber = CurrStartNumber * 3 + 1;
                }
                ++ChainCounter;
            }
            if(ChainCounter > LongestChain)
            {
                StartNumberWithLongestChain = i;
                LongestChain = ChainCounter;
            }
        }
        std::cout << "Starting Number: " << StartNumberWithLongestChain << std::endl;
        std::cout << "Chain size: " << LongestChain << std::endl;
    }
}

