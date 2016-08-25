//--------------------------
// ProjektEuler 19
// Tkel
// Date_start 25.08.2016
// Date_End xx.08.2016
//--------------------------

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

namespace PE019
{
    class Datum
    {
        private:                            //1   2   3
            unsigned day,month,year;        //0   1   2
            const unsigned MonthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        public:
            Datum(unsigned day, unsigned month, unsigned year): day(day), month(month), year(year)
            {
            }

            void addDays(unsigned days)
            {
                //this->day += days;

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

              /*  this->day += days;
                while(this->day > this->MonthDays[this->month-1])
                {
                    if(this->month < 12)
                    {
                        if(this->IsLeapYear() && this->month == 2)
                        {
                            this->day -= (this->MonthDays[this->month-1]+1); // Schaltjahr
                            ++this->month;
                        }
                        else
                        {
                            this->day -= this->MonthDays[this->month-1];
                            ++this->month;
                        }
                    }
                    else
                    {
                        this->month = 1;
                        this->day -= this->MonthDays[this->month-1];
                        ++this->year;
                    }
                }*/
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

            friend std::ostream& operator<<(std::ostream& os, Datum const& Obj)
            {
                os << Obj.day << '.' << Obj.month << '.' << Obj.year;
                return os;
            }

    };

	void _main()
	{
	    Datum t1(18,3,1995);
	    std::cout << t1 << '\n';
	    t1.addDays(3000);
	    std::cout << t1 << '\n';
        t1.subDays(3000);
	    std::cout << t1 << '\n';

	}
}
