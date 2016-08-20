#ifndef Fractaller_Stopwatch_hpp_included
#define Fractaller_Stopwatch_hpp_included

#include <chrono>

namespace Fractaller
{
	class Stopwatch
	{
		typedef std::chrono::high_resolution_clock MyClockType;
		std::chrono::time_point<MyClockType> MyStart, MyEnd;

		bool MyRunning = false;

	public:
		void Start()
		{
			/*
			if(this->IsRunning())
			{
			// ...
			}
			*/

			this->MyStart = MyClockType::now();
			this->MyRunning = true;
		}
		void Stop()
		{
			/*
			if(!this->IsRunning())
			{
			// ...
			}
			*/

			this->MyEnd = MyClockType::now();
			this->MyRunning = false;
		}
		bool IsRunning() const
		{
			return this->MyRunning;
		}

		template<typename DurationT>
		DurationT ElapsedTime() const
		{
			if (this->IsRunning())
			{
				const std::chrono::time_point<MyClockType> Now = MyClockType::now();
				return std::chrono::duration_cast<DurationT>(Now - this->MyStart);
			}
			else
			{
				return std::chrono::duration_cast<DurationT>(this->MyEnd - this->MyStart);
			}
		}
		std::chrono::nanoseconds::rep ElapsedTimeNanoseconds() const
		{
			return this->ElapsedTime<std::chrono::nanoseconds>().count();
		}
		long double ElapsedTimeNanosecondsFlt() const
		{
			return this->ElapsedTime<std::chrono::duration<long double, std::chrono::nanoseconds::period>>().count();
		}
		std::chrono::microseconds::rep ElapsedTimeMicroseconds() const
		{
			return this->ElapsedTime<std::chrono::microseconds>().count();
		}
		long double ElapsedTimeMicrosecondsFlt() const
		{
			return this->ElapsedTime<std::chrono::duration<long double, std::chrono::microseconds::period>>().count();
		}
		std::chrono::milliseconds::rep ElapsedTimeMilliseconds() const
		{
			return this->ElapsedTime<std::chrono::milliseconds>().count();
		}
		long double ElapsedTimeMillisecondsFlt() const
		{
			return this->ElapsedTime<std::chrono::duration<long double, std::chrono::milliseconds::period>>().count();
		}
		std::chrono::seconds::rep ElapsedTimeSeconds() const
		{
			return this->ElapsedTime<std::chrono::seconds>().count();
		}
		long double ElapsedTimeSecondsFlt() const
		{
			return this->ElapsedTime<std::chrono::duration<long double, std::chrono::seconds::period>>().count();
		}
	};
}

#endif // !Fractaller_Stopwatch_hpp_included