//--------------------------
// ProjektEuler 15
// Tkel
// Data xx.xx.xx
//--------------------------

#include <iostream>

namespace PE015
{
    void _main()
    {
        unsigned long long counter = 1;
        unsigned long long counter2 = 1;
        for(std::size_t i = 0; i < 1050; ++i )
        {
            counter  *=3;
            counter2 *=2;
        }
        std::cout << "counter1: " << counter << std::endl;
        std::cout << "counter2: " << counter2 << std::endl;
    }
}


