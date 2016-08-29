//--------------------------
// ProjektEuler 20
// Tkel
// Date_start 24.08.2016
// Date_End 24.08.2016
//--------------------------
#include <iostream>
#include <bitset>
#include <algorithm>
#include <stdexcept>

namespace PE020
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
			if (this->Data.any() && Rhs.Data.any())
			{
				BasicInteger Result(0);
				for (std::size_t i = 0; i < Rhs.Data.size(); i++)
				{
					if (Rhs.Data[i])
					{
						Result += *this;
					}
					this->Data <<= 1;
				}
				return *this = Result;
			}
			else
			{
				return *this = 0;
			}
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
	typedef BasicInteger<1024> Int1024;

	void _main()
	{

		unsigned sum = 0;
		Int1024 _x(1);
		Int1024 RTemp(1);

	//	Fractaller::Stopwatch sw;

		//sw.Start();
		for(unsigned i = 100; i > 0; --i)
		{
			_x*= Int1024(i);
		}
		//sw.Stop();
		//std::cout << "2^1000 " << sw.ElapsedTimeMicrosecondsFlt() << "ms\n";

		//sw.Start();
		while(_x > RTemp)
		{
			RTemp *= 10;
		}
		//sw.Stop();
		//std::cout << "Rtemp erste Anpassung " << sw.ElapsedTimeMicrosecondsFlt() << "ms\n";

		//sw.Start();
		RTemp /= 10;
		//sw.Stop();
		//std::cout << "RTemp/10 " << sw.ElapsedTimeMicrosecondsFlt() << "ms\n";

		//sw.Start();
		while(_x > Int1024(0))
		{
			while(_x >= RTemp)
			{
				_x -= RTemp;
				++sum;
			}
			RTemp /= 10;
		}
		//sw.Stop();
		//std::cout << "quersumme bilden " << sw.ElapsedTimeMicrosecondsFlt() << "ms\n";
		std::cout << "Quersumme: " << sum << '\n';
	}
}
