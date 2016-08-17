//--------------------------
// ProjektEuler 4
// Tkel
// Data xx.xx.xx
//--------------------------

#include <iostream>
#include <vector>
//grösstes Palindrom von term2(100-1000) * term1=(100-1000)
namespace PE004
{
    bool isPalindrom(unsigned Number)
    {
        unsigned Orginal = Number, Palindrom = 0;
        std::vector<unsigned> Ziffern;
        unsigned Faktor = 10;
        while(Number > 0)
        {
            unsigned Ziffer = Number%Faktor;
            Ziffern.push_back(Ziffer);
            Number -= Ziffer;
            Number /= Faktor;
        }

        Faktor = 1;
        for(std::size_t i = 1; i < Ziffern.size(); ++i)
        {
            Faktor *= 10;
        }

        for(std::size_t i = 0; i < Ziffern.size(); ++i)
        {
            Palindrom += Ziffern[i]*Faktor;
            Faktor /= 10;
        }
        if(Palindrom == Orginal)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    void _main()
    {
        unsigned savePalindrom = 0;
        for(std::size_t i = 100; i < 1000; ++i)
        {
            for(std::size_t j = 100; j < 1000; ++j)
            {
                if(isPalindrom(i*j))
                {
                    if(savePalindrom < i*j)
                    {
                        savePalindrom = i*j;
                    }
                }
            }
        }
        std::cout << savePalindrom <<std::endl;
    }
}
