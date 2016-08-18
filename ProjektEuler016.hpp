//--------------------------
// ProjektEuler 15
// Tkel
// Data 17.08.2016
//--------------------------
#include <iostream>
#include <bitset>
#include <algorithm>
#include <stdexcept>
namespace PE016
{
	template<std::size_t N>
	class BasicInteger
	{
		std::bitset<N> Data;

	public:
		BasicInteger()
			: BasicInteger(0)
		{
		}
		BasicInteger(unsigned long long x)
			: Data(x)
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

		BasicInteger& operator+= (BasicInteger const& Rhs)
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
		BasicInteger& operator-= (BasicInteger const& Rhs)
		{
			BasicInteger tempRhs = Rhs;
			tempRhs.invert();
			++tempRhs;
			return *this += tempRhs;
		}
		BasicInteger& operator*= (BasicInteger const& Rhs)
		{
			BasicInteger Result(0);
			for(unsigned i = 0; i < this->Data.size(); ++i)
			{
				BasicInteger temp(0);
				for(unsigned j = 0; j < Rhs.Data.size(); ++j)
				{
					temp.Data[j] = this->Data[i] & Rhs.Data[j];
				}
				temp.Data <<= i;
				Result += temp;
			}
			*this = Result;
			return *this;
		}
		BasicInteger& operator/= (BasicInteger Rhs)
		{
			if(Rhs == 0)
			{
				throw std::domain_error("BasicInteger::operator/=: division by zero");
			}

			if(Rhs > *this)
			{
				return *this = 0;
			}
			else
			{
				BasicInteger Result = 0;

				std::size_t MSB;
				for(MSB = this->Data.size() - 1; MSB != 0 && !this->Data[MSB]; --MSB);

				int RhsShifts;
				for(RhsShifts = 0; !Rhs.Data[MSB]; ++RhsShifts, Rhs.Data <<= 1);
				
				for(; *this != BasicInteger(0) && RhsShifts >= 0; --RhsShifts, Rhs.Data >>= 1)
				{
					if(Rhs <= *this)
					{
						*this -= Rhs;
						Result.Data[RhsShifts] = true;
					}
				}
				return *this = Result;
			}
		}

		friend std::ostream& operator<< (std::ostream& Stream, BasicInteger const& Object)
		{
			Stream << Object.Data;
			return Stream;
		}

		bool operator== (BasicInteger const& Rhs) const
		{
			return this->Data == Rhs.Data;
		}
		bool operator< (BasicInteger const& Rhs) const
		{
			for(std::size_t i = this->Data.size(); i-- != 0;)
			{
				if(this->Data[i] && !Rhs.Data[i])
				{
					return false;
				}
				else if(!this->Data[i] && Rhs.Data[i])
				{
					return true;
				}
			}
			return false;
		}
	};

	template<std::size_t N>
	BasicInteger<N> operator+ (BasicInteger<N> Lhs, BasicInteger<N> const& Rhs)
	{
		return Lhs += Rhs;
	}
	template<std::size_t N>
	BasicInteger<N> operator- (BasicInteger<N> Lhs, BasicInteger<N> const& Rhs)
	{
		return Lhs -= Rhs;
	}
	template<std::size_t N>
	BasicInteger<N> operator* (BasicInteger<N> Lhs, BasicInteger<N> const& Rhs)
	{
		return Lhs *= Rhs;
	}
	template<std::size_t N>
	BasicInteger<N> operator/ (BasicInteger<N> Lhs, BasicInteger<N> const& Rhs)
	{
		return Lhs /= Rhs;
	}

	template<std::size_t N>
	BasicInteger<N>& operator++ (BasicInteger<N>& Object)
	{
		return Object += 1;
	}
	template<std::size_t N>
	BasicInteger<N> operator++ (BasicInteger<N>& Object, int)
	{
		const BasicInteger<N> Result = Object;
		++Object;
		return Result;
	}

	template<std::size_t N>
	BasicInteger<N>& operator-- (BasicInteger<N>& Object)
	{
		return Object -= 1;
	}
	template<std::size_t N>
	BasicInteger<N> operator-- (BasicInteger<N>& Object, int)
	{
		const BasicInteger<N> Result = Object;
		--Object;
		return Result;
	}

	template<std::size_t N>
	bool operator!= (BasicInteger<N> const& Lhs, BasicInteger<N> const& Rhs)
	{
		return !(Lhs == Rhs);
	}
	template<std::size_t N>
	bool operator> (BasicInteger<N> const& Lhs, BasicInteger<N> const& Rhs)
	{
		return Rhs < Lhs;
	}
	template<std::size_t N>
	bool operator<= (BasicInteger<N> const& Lhs, BasicInteger<N> const& Rhs)
	{
		return !(Lhs > Rhs);
	}
	template<std::size_t N>
	bool operator>= (BasicInteger<N> const& Lhs, BasicInteger<N> const& Rhs)
	{
		return !(Lhs < Rhs);
	}

	typedef BasicInteger<8> Int8;

	void _main()
	{
		auto Div = [&](Int8 const& Lhs, Int8 const& Rhs)
		{
			std::cout << Lhs.to_ulong() << '/' << Rhs.to_ulong() << " = " << (Lhs / Rhs).to_ulong() << '\n';
		};
		Div(0, 1);
		Div(8, 2);
		Div(2, 8);
		Div(29, 5);
		Div(29, 29);

		auto Less = [&](Int8 const& Lhs, Int8 const& Rhs)
		{
			std::cout << Lhs.to_ulong() << '<' << Rhs.to_ulong() << " ? " << (Lhs < Rhs ? "yea" : "nah") << '\n';
		};
		Less(0, 0);
		Less(0, 1);
		Less(3, 4);
		Less(4, 4);
		Less(5, 4);

		/*
		const myBit a(15);
		const myBit b(16);
		myBit c(240);
		*/

		/*
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

		std::cout << "a < b\n";
		std::cout <<  a.to_ulong() << " < " <<  b.to_ulong() << " : ";
		bool asdf = a<b;
		std::cout << asdf << "\n";
		std::cout << "a > b\n";
		std::cout <<  a.to_ulong() << " > " <<  b.to_ulong() << " : ";
		asdf = a>b;
		std::cout << asdf << "\n";
		*/

		/*
		std::cout <<"s=s/b\n";
		std::cout << "s: " << c.to_ulong() << "\t Bin: " << c << '\n';
		std::cout << "b: " << b.to_ulong() << "\t Bin: " << b << '\n';
		c/=b;
		std::cout << "S: " << c.to_ulong() << "\t Bin: " << c << "\n\n";
		*/

		/*
		unsigned sum = 0;
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
		std::cout << sum ;
		*/
	}
}
