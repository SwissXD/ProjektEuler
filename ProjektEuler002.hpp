//--------------------------
// ProjektEuler 2
// Tkel
// Data xx.xx.xx
//--------------------------
#include <iostream>
namespace PE002
{
    void _main()
    {
        unsigned FibSum = 0, oldTerm = 0, newTerm = 1;
        unsigned SummeGeraderFibonacciTerme = 0;
        while( newTerm < 4000000)
        {
            FibSum = newTerm + oldTerm;
        //	std::cout << FibSum << std::endl;
            oldTerm = newTerm;
            newTerm = FibSum;
            if(FibSum%2 == 0)
            {
                SummeGeraderFibonacciTerme += FibSum;
            }
        }
        std::cout << SummeGeraderFibonacciTerme << std::endl;
    }
}
