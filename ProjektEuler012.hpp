//--------------------------
// ProjektEuler 12
// Tkel
// Data xx.xx.xx
//--------------------------
#include <iostream>
#include <cmath>

namespace PE012
{
    unsigned Dreickszahl(unsigned n)
    {
        return ((n+1)*n)/2;
    }

    void _main()
    {
        unsigned Anzahlteiler = 1;
        unsigned Dz = 1; // Dreieckszahl

        for(std::size_t i = 2; Anzahlteiler < 5; i+=1)
        {
            Anzahlteiler = 1;

            Dz = Dreickszahl(i);

            const std::size_t Limit = static_cast<std::size_t>(std::sqrt(Dz));

            for(std::size_t j = 2; j <= Limit; ++j)
            {
                if(Dz%j == 0)
                {
                    ++Anzahlteiler;
                }
            }
            Anzahlteiler *=2;
           std::cout << "Dreieckszahl: " << Dz << "\t\t\tAnzahlteiler: " << Anzahlteiler << std::endl;
        }
         std::cout << "Dreieckszahl: " << Dz << "\t Anzahlteiler: " << Anzahlteiler << std::endl;
    }

}
