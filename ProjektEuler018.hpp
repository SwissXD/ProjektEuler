//--------------------------
// ProjektEuler 18
// Tkel
// Date_start 22.08.2016
// Date_End xx.08.2016
//--------------------------

#include <vector>
#include <iostream>
#include <algorithm>

namespace PE018
{
    class NumberRow
    {
        private:
            std::vector<unsigned> Numbers;

        public:
            NumberRow(std::vector<unsigned> const& val)
            {
                this->Numbers = val;
            }

            NumberRow(unsigned val)
            {
                this->Numbers.push_back(val);
            }

            std::vector<unsigned> IndexesSortetBySize() const
            {
                std::vector<unsigned> temp(this->Numbers.begin(),this->Numbers.end());

                std::sort(temp.begin(), temp.end(),std::greater<unsigned>());

                std::vector<unsigned> IndexBySize;

                for(std::vector<unsigned>::const_iterator it = temp.begin(); it != temp.end() ; ++it)
                {
                    for(unsigned j = 0; j < this->Numbers.size(); ++j)
                    {
                        if(*it == this->Numbers[j])
                        {
                            bool flag = true;
                            for(std::vector<unsigned>::const_iterator it2 = IndexBySize.begin(); IndexBySize.size() > 0 && it2 < IndexBySize.end(); ++it2)
                            {
                                if(*it2 == j)
                                {
                                    flag = false;
                                }
                            }
                            if(flag)
                            {
                                IndexBySize.push_back(j);
                                j = this->Numbers.size();
                            }
                        }
                    }
                }
                return IndexBySize;
            }
    };

	void _main()
	{
	    const unsigned CodBlockSucks[10] = {5,1,623,564,866,52,412,132,188,865};
        const std::vector<unsigned> sadf(&CodBlockSucks[0], &CodBlockSucks[0]+10);

        NumberRow bla(sadf);

        std::vector<unsigned> myvector = bla.IndexesSortetBySize();

        std::cout << "myvector.size(): " << myvector.size() << '\n';

        for (std::size_t i = 0; i < myvector.size(); ++i)
        {
            std::cout << myvector[i] << "\t" << sadf[myvector[i]] << '\n';
        }
	}
}
