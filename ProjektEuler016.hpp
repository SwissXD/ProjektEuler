//--------------------------
// ProjektEuler 15
// Tkel
// Data 17.08.2016
//--------------------------
#include <iostream>
#include <bitset>
#include <algorithm>
namespace PE016
{
    class myBit
    {
        std::bitset<8> Data;

    public:
        myBit()
        {

        }
        myBit(unsigned long val): Data(val)
        {
        }
        unsigned long to_ulong() const
        {
            return this->Data.to_ulong();
        }

        void flip()
        {
            this->Data.flip();
        }

        myBit& operator*=(myBit const& Rhs)
        {
            myBit Result(0);
            for(unsigned i = 0; i < this->Data.size(); ++i)
            {
                myBit temp(0);
                for(unsigned j = 0; j < Rhs.Data.size(); ++j)
                {
                    temp.Data[j] = this->Data[i] & Rhs.Data[j];
                }
                temp.Data<<=i;
                Result +=temp;
            }
            *this = Result;
            return *this;
        }

        myBit& operator-=(myBit const& Rhs)
        {
           myBit tempRhs = Rhs;
           tempRhs.flip();
           ++tempRhs;
           return *this += tempRhs;
        }
        myBit& operator++()
        {
             myBit val(1);
            *this += val;
            return *this;
        }
        myBit& operator+=(myBit const& Rhs)
        {
            std::bitset<1> carry(0);
            for(unsigned i = 0; i < this->Data.size(); ++i)
            {
                std::bitset<1> atemp(this->Data[i]);
                this->Data[i] = this->Data[i] ^ Rhs.Data[i] ^ carry[0];
                carry[0] = (atemp[0] & Rhs.Data[i]) | (atemp[0] & carry[0]) | (carry[0] & Rhs.Data[i]);
            }
            return *this;
        }

        myBit& operator=(myBit const& Rhs)
        {
            this->Data = Rhs.Data;
            return *this;
        }
        friend myBit operator*(myBit Lhs, myBit const& Rhs)
        {
            return Lhs*=Rhs;
        }
        friend myBit operator+(myBit Lhs, myBit const& Rhs)
        {
            return Lhs += Rhs;
        }

        friend myBit operator-(myBit Lhs, myBit const& Rhs)
        {
            return Lhs -= Rhs;
        }

        friend std::ostream& operator<< (std::ostream& Stream, myBit const& Object)
        {
            Stream << Object.Data;
            return Stream;
        }

        friend bool operator> (myBit const& Lhs, myBit const& Rhs)
        {
        for (unsigned i = Rhs.Data.size(); i > 0; --i)
        {
            if (Lhs.Data[i] > Rhs.Data[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        }
        friend bool operator< (myBit const& Lhs, myBit const& Rhs)
        {
            return Rhs < Lhs;
        }
    };


    void _main()
    {
        const myBit a(15);
        const myBit b(16);
        myBit c(0);
        std::cout <<"s = a+b\n";
        std::cout << "a: " << a.to_ulong() << "\t Bin: " << a << '\n';
        std::cout << "b: " << b.to_ulong() << "\t Bin: " << b << '\n';
        c = a+b;
        std::cout << "S: " << c.to_ulong() << "\t Bin: " << c << "\n\n";

        std::cout <<"s = c-a\n";
        std::cout << "c: " << c.to_ulong() << "\t Bin: " << c << '\n';
        std::cout << "a: " << a.to_ulong() << "\t Bin: " << a << '\n';
        c = c-a;
        std::cout << "S: " << c.to_ulong() << "\t Bin: " << c << "\n\n";

        std::cout <<"s = a*b\n";
        std::cout << "a: " << a.to_ulong() << "\t Bin: " << a << '\n';
        std::cout << "b: " << b.to_ulong() << "\t Bin: " << b << '\n';
        c = a*b;
        std::cout << "S: " << c.to_ulong() << "\t Bin: " << c << "\n\n";
    }
}
