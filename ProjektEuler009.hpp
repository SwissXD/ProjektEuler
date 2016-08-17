//--------------------------
// ProjektEuler 9
// Tkel
// Data xx.xx.xx
//--------------------------

#include <iostream>
#include <vector>
#include <string>

namespace PE009
{
    void _main()
    {
        for(std::size_t a = 0; a <= 1000; ++a)
        {
            for(std::size_t b = 0; b <= 1000; ++b)
            {
                for(std::size_t c = 0; c <= 1000; ++c)
                {
                    if(a+b+c == 1000 && ((a*a)+(b*b) == c*c) && ((c*c)-(a*a) == b*b) && ((c*c)-(b*b) == a*a))
                        std::cout << "a: " << a << "\tb: " << b << "\tc: " << c << "\tProdukt: " << a*b*c << std::endl;
                }
            }
        }
    }
}

