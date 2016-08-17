//--------------------------
// ProjektEuler 6
// Tkel
// Data xx.xx.xx
//--------------------------

#include <iostream>
#include <vector>
namespace PE006
{
    long square(long number)
    {
        return number*number;
    }

    void _main()
    {
        unsigned long long sum1 = 0;
        unsigned long long sum2 = 0;
        for(std::size_t i = 1; i < 101; ++i)
        {
            sum1 += square(i);
            sum2 += i;
        }
        sum2 = square(sum2);
        std::cout << "sum1 = " << sum1 << std::endl;
        std::cout << "sum2 = " << sum2 << std::endl;
        std::cout << "Differenz sum2 smu1 = " << sum2-sum1 << std::endl;
    }
}
