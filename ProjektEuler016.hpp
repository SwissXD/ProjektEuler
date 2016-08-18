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

        void invert()
        {
            this->Data.flip();
        }

        myBit& operator/=(myBit const& Rhs)
        {
            unsigned counter = this->Data.size()-1;
            while(this->Data[counter] != 1)
            {
                --counter;
            }
            std::cout << "\ncounter: " << counter << "\n\n";

            myBit Result(0);
            std::cout << "Result:   " << Result << '\n';
            myBit Quotient(1);
            //--counter;
            std::cout << "Quotient: " << Quotient << '\n';
            std::cout << "-------------------------------\n";
            while(counter > 1)
            {
                std::cout << "this:     " << *this << '\n';
                std::cout << "Rhs:      " << Rhs << '\n';
                std::cout << "Quotient: " << Quotient << '\n';
                std::cout << "Result:   " << Result << '\n';
                std::cout << "-------------------------------\n";
                while(Rhs > Quotient)
                {
                    if(counter > 1)
                        --counter;
                    else
                        break;
                    Quotient.Data<<=1;
                    Quotient.Data[0] = this->Data[counter];
                    Result.Data<<=1;
                    std::cout << "Rhs:      " << Rhs << '\n';
                    std::cout << "Quotient: " << Quotient << '\n';
                    std::cout << "Result:   " << Result << '\n';
                    std::cout << "-------------------------------\n";
                }

             //   Quotient-=Rhs;
              //  Result.Data[0] = true;
               // --counter;*/
            }

            return  *this = Result;
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
           tempRhs.invert();
           ++tempRhs;
           return *this += tempRhs;
        }
        myBit& operator++()
        {
            return *this += myBit(1);
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

        friend myBit operator/(myBit Lhs, myBit const& Rhs)
        {
            return Lhs/=Rhs;
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
            return !(Rhs > Lhs);
        }

    };


    void _main()
    {
        const myBit a(15);
        const myBit b(16);
        myBit c(240);
      /*  std::cout <<"s = a+b\n";
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

        std::cout << "a < b\n";
        std::cout <<  a.to_ulong() << " < " <<  b.to_ulong() << " : ";
        bool asdf = a<b;
        std::cout << asdf << "\n";
        std::cout << "a > b\n";
        std::cout <<  a.to_ulong() << " > " <<  b.to_ulong() << " : ";
        asdf = a>b;
        std::cout << asdf << "\n";*/

        std::cout <<"s=s/b\n";
        std::cout << "s: " << c.to_ulong() << "\t Bin: " << c << '\n';
        std::cout << "b: " << b.to_ulong() << "\t Bin: " << b << '\n';
        c/=b;
        std::cout << "S: " << c.to_ulong() << "\t Bin: " << c << "\n\n";


   /*     unsigned sum = 0;
        unsigned counter = 0;
        myBit _x(2);
        myBit RTemp(1);

        for(unsigned i = 0; i <1000; ++i)
        {
            _x*=myBit(2);
        }

        while(_x > RTemp)
        {
            RTemp *= myBit(10);
            ++counter;
        }
        --counter;
        RTemp = myBit(0);

        for(unsigned i = 0; i <counter; ++i)
        {
            RTemp *= myBit(10);
        }

        while(_x > 0)
        {
            while(_x > RTemp)
            {
                _x -= RTemp;
                ++sum;
            }
            --counter;
            RTemp = myBit(0);

            for(unsigned i = 0; i <counter; ++i)
            {
                RTemp *= myBit(10);
            }
        }
        std::cout << sum ;*/
    }
}
