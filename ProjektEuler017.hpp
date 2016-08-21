//--------------------------
// ProjektEuler 17
// Tkel
// Date_start 21.08.2016
// Date_End 21.08.2016
//--------------------------
#include <string>
#include <iostream>



namespace PE017
{
	std::string Numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
							"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
							"thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand"};
	
	Fractaller::Stopwatch sw;


	unsigned CountedLetters(unsigned val)
	{
		unsigned LetterSum = 0;
		unsigned SplittetNumber[4];

		for (std::size_t i = 0; i < 4; ++i)
		{
			SplittetNumber[i] = val % 10;
			val -= SplittetNumber[i];
			val /= 10;
		//	std::cout << "i: " << i << "Number: " << SplittetNumber[i] << "\n";
		}

		if (SplittetNumber[3] >= 1)
		{
			LetterSum += Numbers[0].size() + Numbers[28].size();
		//	std::cout << "Number3: " << SplittetNumber[3] << Numbers[0] + Numbers[28] << "\n";
		}
		
		if (SplittetNumber[2] >= 1)
		{
			LetterSum += Numbers[SplittetNumber[2]-1].size() + Numbers[27].size();
			if (SplittetNumber[1] >= 1 || SplittetNumber[0] >= 1)
			{
				LetterSum += 3; //bc of "and"
			}


			//std::cout << "Number2: " << SplittetNumber[2] << Numbers[SplittetNumber[2] - 1] + Numbers[27] << " and \n";
		}

		if (SplittetNumber[1] == 1)
		{
			unsigned index = SplittetNumber[1] * 10 + SplittetNumber[0] - 1;
			LetterSum += Numbers[index].size();
		//	std::cout << "Number1: " << SplittetNumber[1] << Numbers[index] << "\n";
		}
		else if(SplittetNumber[1] >= 2)
		{
			unsigned index = SplittetNumber[1] + 17 ;
			LetterSum += Numbers[index].size();
		//	std::cout << "Number1: " << SplittetNumber[1] << Numbers[index] << "\n";
		}

		if (SplittetNumber[0] && (SplittetNumber[1] > 1 || SplittetNumber[1] == 0))
		{
			unsigned index = SplittetNumber[0] -1;
			LetterSum += Numbers[index].size();
		//	std::cout << "Number0: " << SplittetNumber[0] << Numbers[index] << "\n";
		}
		return 	LetterSum;
	}


	void _main()
	{
		unsigned x = 0;
		sw.Start();
		for (size_t i = 1; i < 1001; ++i)
		{
			x += CountedLetters(i);
		//	std::cout << "---------------\n";
		}

		sw.Stop();

		std::cout << "CountedLetters " << sw.ElapsedTimeMicrosecondsFlt() << "ms\n";

		std::cout << "Letters: " << x << '\n';
	}
}