//--------------------------
// TicTactoe
// Tkel
// Data xx.xx.xx
//--------------------------
#include <iostream>
#include <vector>
namespace TicTacToe
{
    enum Symbols{SymbolSpieler1,SymbolSpieler2,SymbolDefault};
    enum Spielstand{SiegSpieler1,SiegSpieler2,Unentschieden,NochNichtGeendet};
     class Koordinaten2d
     {
        public:
        int x,y;
        Koordinaten2d(int x, int y): x(x),y(y)
        {}
     };

     class Spielstein
     {
         public:
         Koordinaten2d Koordinate2D;
         Symbols Symbol;
         Spielstein(int x, int y, Symbols Symbol): Koordinate2D(x,y), Symbol(Symbol)
         {}
         Spielstein(Koordinaten2d Koord2d, Symbols Symbol): Koordinate2D(Koord2d), Symbol(Symbol)
         {}
     };

    class Spielfeld
    {
        private:
    //	int BreiteX, LaengeY;


        public:
        std::vector<Spielstein> Map; //muss unter Private member
        int BreiteX, LaengeY; 		 //muss unter Private member
        Koordinaten2d Cursor;
        Spielfeld(int FeldgroesseX , int FeldgroesseY): BreiteX(FeldgroesseX), LaengeY(FeldgroesseY), Cursor(0,0)
        {
            for(int counterX = 0; counterX < FeldgroesseX; ++counterX)
            {
                for(int counterY = 0; counterY < FeldgroesseY; ++counterY)
                {
                    Spielstein Temp(counterX,counterY,SymbolDefault);
                    Map.push_back(Temp);
                }
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Spielfeld& Spielfeld)
        {
            for(int counterY = 0; counterY < Spielfeld.LaengeY; ++counterY)
            {
                for(int counterX = 0; counterX < Spielfeld.BreiteX; ++counterX)
                {
                    if(counterX == Spielfeld.Cursor.x && counterY == Spielfeld.Cursor.y)
                        os << ' ';
                    else
                        os << '[';

                    switch(Spielfeld.Map[counterY * Spielfeld.BreiteX + counterX].Symbol)
                    {
                        case SymbolSpieler1:
                            os << 'x';
                            break;
                        case SymbolSpieler2:
                            os << 'o';
                            break;
                        case SymbolDefault:
                            os << ' ';
                            break;
                    }

                    if(counterX == Spielfeld.Cursor.x && counterY == Spielfeld.Cursor.y)
                        os << ' ';
                    else
                        os << ']';

                }
                os << '\n';
            }
        }
    };

    bool GueltigkeitsKontrolle(Spielfeld* Spielfeld2d)
    {
        for(int counterY = 0; counterY < Spielfeld2d->LaengeY; ++counterY)
        {
            for(int counterX = 0; counterX < Spielfeld2d->BreiteX; ++counterX)
            {
                if(counterX == Spielfeld2d->Cursor.x && counterY == Spielfeld2d->Cursor.y)
                {
                    if(Spielfeld2d->Map[counterY * Spielfeld2d->BreiteX + counterX].Symbol == SymbolDefault)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }

    void SpielsteinLegen(bool Spieler, Spielfeld* Spielfeld2d)
    {
        for(int counterY = 0; counterY < Spielfeld2d->LaengeY; ++counterY)
        {
            for(int counterX = 0; counterX < Spielfeld2d->BreiteX; ++counterX)
            {
                if(counterX == Spielfeld2d->Cursor.x && counterY == Spielfeld2d->Cursor.y)
                {
                    if(Spieler)
                    {
                        Spielfeld2d->Map[counterY * Spielfeld2d->BreiteX + counterX].Symbol = SymbolSpieler1;
                    }
                    else
                    {
                        Spielfeld2d->Map[counterY * Spielfeld2d->BreiteX + counterX].Symbol = SymbolSpieler2;
                    }
                }
            }
        }
    }

    void Spielzug(bool Spieler, Spielfeld* Spielfeld2d)
    {
        char EingabeBewegung;

        bool ZugEnde = false;
        bool SpielstandAenderung = false;

        while(!ZugEnde)
        {
            std::cin >> EingabeBewegung;

            switch(EingabeBewegung)
            {
                case 'w':
                    Spielfeld2d->Cursor.y == 0 ? Spielfeld2d->Cursor.y = Spielfeld2d->LaengeY - 1 : --Spielfeld2d->Cursor.y;
                    SpielstandAenderung = true;
                    break;
                case 's':
                    Spielfeld2d->Cursor.y < Spielfeld2d->LaengeY-1 ? ++Spielfeld2d->Cursor.y : Spielfeld2d->Cursor.y = 0;
                    SpielstandAenderung = true;
                    break;
                case 'a':
                    Spielfeld2d->Cursor.x == 0 ? Spielfeld2d->Cursor.x = Spielfeld2d->BreiteX - 1 : --Spielfeld2d->Cursor.x;
                    SpielstandAenderung = true;
                    break;
                case 'd':
                    Spielfeld2d->Cursor.x < Spielfeld2d->BreiteX-1 ? ++Spielfeld2d->Cursor.x : Spielfeld2d->Cursor.x = 0;
                    SpielstandAenderung = true;
                    break;
                case 'r':
                    if(GueltigkeitsKontrolle(Spielfeld2d))
                        ZugEnde = true;
                    break;
            }
            if(SpielstandAenderung)
            {
                std::cout << *Spielfeld2d;
                SpielstandAenderung = false;
            }
        }
        SpielsteinLegen(Spieler,Spielfeld2d);
        std::cout << *Spielfeld2d;
    }

    Spielstand TestAufSpielende(Spielfeld* Spielfeld2d)
    {
        //Anzahl Freierfelder zählen
        auto AnzahlDefaultFelder = 0;
        for(auto i = 0; i < Spielfeld2d->LaengeY * Spielfeld2d->BreiteX; ++i)
        {
            if(Spielfeld2d->Map[i].Symbol == SymbolDefault)
            {
                ++AnzahlDefaultFelder;
            }
        }
    //Waagrecht
        if(Spielfeld2d->Map[0].Symbol == Spielfeld2d->Map[1].Symbol == Spielfeld2d->Map[2].Symbol != SymbolDefault)
            return Spielfeld2d->Map[0].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;

        if(Spielfeld2d->Map[3].Symbol == Spielfeld2d->Map[4].Symbol == Spielfeld2d->Map[5].Symbol != SymbolDefault)
            return Spielfeld2d->Map[3].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;

        if(Spielfeld2d->Map[6].Symbol == Spielfeld2d->Map[7].Symbol == Spielfeld2d->Map[8].Symbol != SymbolDefault)
            return Spielfeld2d->Map[6].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;
    //Senkrecht
        if(Spielfeld2d->Map[0].Symbol == Spielfeld2d->Map[3].Symbol == Spielfeld2d->Map[6].Symbol != SymbolDefault)
            return Spielfeld2d->Map[0].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;

        if(Spielfeld2d->Map[1].Symbol == Spielfeld2d->Map[4].Symbol == Spielfeld2d->Map[7].Symbol != SymbolDefault)
            return Spielfeld2d->Map[0].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;

        if(Spielfeld2d->Map[2].Symbol == Spielfeld2d->Map[5].Symbol == Spielfeld2d->Map[8].Symbol != SymbolDefault)
            return Spielfeld2d->Map[0].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;
    //Digonal
        if(Spielfeld2d->Map[0].Symbol == Spielfeld2d->Map[4].Symbol == Spielfeld2d->Map[8].Symbol != SymbolDefault)
            return Spielfeld2d->Map[0].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;

        if(Spielfeld2d->Map[2].Symbol == Spielfeld2d->Map[4].Symbol == Spielfeld2d->Map[6].Symbol != SymbolDefault)
            return Spielfeld2d->Map[0].Symbol == SymbolSpieler1 ? SiegSpieler1 : SiegSpieler2;

        if(AnzahlDefaultFelder == 0)
            return Unentschieden;
        else
            return NochNichtGeendet;
    }




    void _main()
    {
        Spielfeld TicTacToeFeld(3,3);
        std::cout << TicTacToeFeld;

        for(int i = 1; i < TicTacToeFeld.LaengeY * TicTacToeFeld.BreiteX+1; ++i)
        {
            Spielzug(i%2,&TicTacToeFeld);
            if(i >= 5)
            {
                Spielstand Check = TestAufSpielende(&TicTacToeFeld);
                switch(Check)
                {
                    case SiegSpieler1:
                        std::cout << "Sieg: Spieler 1\n";
                        break;
                    case SiegSpieler2:
                        std::cout << "Sieg: Spieler 2\n";
                        break;
                    case Unentschieden:
                        std::cout << "Unentschieden!\n";
                        break;
                    case NochNichtGeendet:
                        break;
                }
            }
        }
    }
}

