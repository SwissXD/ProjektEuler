//--------------------------
// ProjektEuler 1
// Tkel
// Data xx.xx.xx
//--------------------------
#include <iostream>
namespace PE001
{
    void _main()
    {
        unsigned sum = 0;
        for(unsigned i = 0; i < 1000; ++i)
        {
            if(i%3 == 0 || i%5 == 0)
                sum += i;
        }
        std::cout << sum << std::endl;
    }
}

