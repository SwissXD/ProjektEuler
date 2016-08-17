//--------------------------
// ProjektEuler 5
// Tkel
// Data xx.xx.xx
//--------------------------

#include <iostream>
#include <vector>

//kgV berechnen von 1 bis 20
namespace PE005
{
    class ZahlMitPotenz
    {
        public:
        unsigned Zahl,Potenz;
        ZahlMitPotenz(unsigned z, unsigned p): Zahl(z), Potenz(p)
        {}
        ZahlMitPotenz(unsigned z): Zahl(z), Potenz(1)
        {}

        friend std::ostream& operator<<(std::ostream& os, const ZahlMitPotenz& zahlmitpot)
        {
            os << zahlmitpot.Zahl << '^' << zahlmitpot.Potenz;
            return os;
        }
    };

    std::vector<ZahlMitPotenz> PrimzahlenBerechnen(unsigned limit)
    {
        std::vector<ZahlMitPotenz> Prims;
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
            {
                ZahlMitPotenz i2(i);
                Prims.push_back(i2);
            }
        }
        return Prims;
    }

    std::vector<ZahlMitPotenz> Primfaktorzerlegung(unsigned Zahl)
    {
        std::vector<ZahlMitPotenz> Primzahlen = PrimzahlenBerechnen(20);
        std::vector<ZahlMitPotenz> Faktoren;

        unsigned counter = 0;
        unsigned rest = Zahl;
        while(Zahl > 1  && counter < Primzahlen.size())
        {
            rest = Zahl/Primzahlen[counter].Zahl;
            if(rest*Primzahlen[counter].Zahl == Zahl)
            {
                bool FaktornBereitsVorhanden = false;
                for(std::size_t i = 0; i < Faktoren.size(); ++i)
                {
                    if(Primzahlen[counter].Zahl == Faktoren[i].Zahl)
                    {
                        ++Faktoren[i].Potenz;
                        FaktornBereitsVorhanden = true;
                    }
                }
                if(!FaktornBereitsVorhanden)
                {
                    Faktoren.push_back(Primzahlen[counter]);
                }

                Zahl /= Primzahlen[counter].Zahl;
                counter = 0;
            }
            else
            {
                ++counter;
            }
        }
        return Faktoren;
    }

    unsigned getkgV(unsigned start, unsigned end)
    {
        std::vector<ZahlMitPotenz> FaktorenkgV;

        for(std::size_t i = start; i <= end; ++i)
        {
            std::vector<ZahlMitPotenz> Faktoren = Primfaktorzerlegung(i);

            if(FaktorenkgV.size() < 1)
            {
                FaktorenkgV = Faktoren;
            }
            else
            {
                for(std::size_t j = 0; j <  Faktoren.size(); ++j)
                {
                    bool FaktorNichtVorhanden = true;
                    unsigned counter = 0;
                    while(FaktorNichtVorhanden)
                    {
                        if(Faktoren[j].Zahl == FaktorenkgV[counter].Zahl)
                        {
                            if(Faktoren[j].Potenz > FaktorenkgV[counter].Potenz)
                            {
                                 FaktorenkgV[counter].Potenz = Faktoren[j].Potenz;
                            }
                            FaktorNichtVorhanden = false;
                        }
                        else if(counter < FaktorenkgV.size()-1)
                        {
                            ++counter;
                        }
                        else
                        {
                            FaktorenkgV.push_back(Faktoren[j]);
                            FaktorNichtVorhanden = false;
                        }
                    }
                }
            }
        }
        unsigned kgv = 1;
        for(std::size_t i = 0; i < FaktorenkgV.size(); ++i)
        {
            std::cout << "> POS 3 < " << FaktorenkgV[i];
            std::cout << std::endl;
            for(std::size_t j = 0; j < FaktorenkgV[i].Potenz; ++j)
            {
                kgv *= FaktorenkgV[i].Zahl;
            }
        }
        return kgv;
    }

    void _main()
    {
        unsigned kgV = getkgV(2,20);
        std::cout << "kgV: " << kgV << std::endl;
    }
}
