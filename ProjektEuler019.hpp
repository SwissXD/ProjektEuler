//--------------------------
// ProjektEuler 19
// Tkel
// Date_start 25.08.2016
// Date_End xx.08.2016
//--------------------------

#include <vector>
#include <iostream>
#include <string>


namespace PE019
{
    class Datum
    {
        private:                          //1  2  3  4  5  6  7  8  9 10  11 12 Monat
            unsigned day,month,year;      //0  1  2  3  4  5  6  7  8  9  10 11 Index
            const unsigned MonthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        public:
            Datum(unsigned day, unsigned month, unsigned year): day(day), month(month), year(year)
            {
            }

            void addDays(unsigned days)
            {
                for(std::size_t i = days; i > 0; --i)
                {
                    if(this->day < this->MonthDays[this->month-1] || ((this->day < this->MonthDays[this->month-1]+1) && this->IsLeapYear() && this->month == 2))
                    {
                        ++this->day;
                    }
                    else
                    {
                        if(this->month < 12)
                        {
                            ++this->month;
                            this->day = 1;
                        }
                        else
                        {
                            ++this->year;
                            this->month = 1;
                            this->day = 1;
                        }
                    }
                }
            }

            void subDays(unsigned days)
            {
                for(std::size_t i = days; i > 0; --i)
                {
                    if(this->day > 1)
                    {
                        --this->day;
                    }
                    else
                    {
                        if(this->month > 1)
                        {
                            --this->month;
                            if(this->IsLeapYear() && this->month == 2)
                            {
                                this->day = this->MonthDays[this->month-1]+1; // Schaltjahr
                            }
                            else
                            {
                                this->day = this->MonthDays[this->month-1];
                            }
                        }
                        else
                        {
                            --this->year;
                            this->month = 12;
                            this->day = this->MonthDays[this->month-1];
                        }
                    }
                }
            }

            bool IsLeapYear()
            {
                if(this->year%4 == 0 && (this->year%100 != 0 || this->year%400 == 0))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            unsigned DifferentInDays(Datum val)
            {
                unsigned i = 0;
                if(val < *this)
                {
                    for(; *this != val; ++i)
                    {
                        val.addDays(1);
                    }
                }
                else if(val > *this)
                {
                    for(; *this != val; ++i)
                    {
                        val.subDays(1);
                    }
                }
                return i;
            }


           unsigned getSundaysSince1901on(unsigned DayOfMonth)
           {
               Datum Start(1,1,1901); // Monday

               unsigned counter = 0;
               for(std::size_t i = 1; Start != *this; ++i)
               {
                   if(Start.day == DayOfMonth && i%7 == 6)
                   {
                       ++counter;
                   }
                   Start.addDays(1);
               }
               return counter;
           }


//operatoren
            friend std::ostream& operator<< (std::ostream& os, Datum const& Obj)
            {
                os << Obj.day << '.' << Obj.month << '.' << Obj.year;
                return os;
            }

            bool operator== (Datum const& Val) const
            {
                if(this->day == Val.day && this->month == Val.month && this->year == Val.year)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            bool operator!= (Datum const& Rhs) const
            {
                return !(*this == Rhs);
            }

            bool operator <(Datum const& Rhs) const
            {
                if(this->day < Rhs.day && this->month == Rhs.month && this->year == Rhs.year ||
                   this->month < Rhs.month && this->year == Rhs.year || this->year < Rhs.year)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            bool operator >(Datum const& Rhs) const
            {
                return Rhs < *this;
            }

            bool operator<=(Datum const& Rhs) const
            {
                return !(*this > Rhs);
            }

            bool operator>=(Datum const& Rhs) const
            {
                return !(*this < Rhs);
            }
    };


	void _main()
	{
	    Datum t1(31,12,2000);

	    std::cout << t1.getSundaysSince1901on(1) << '\n';

	}
}
