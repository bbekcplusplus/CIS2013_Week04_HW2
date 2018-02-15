#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int dealer = 0;
int player = 0;
int jack = 0;
int queen = 0;
int king = 0;
int ace = 0;

int djack = 0;
int dqueen = 0;
int dking = 0;
int dace = 0;

int draw()
{
	int a;
	a = rand() % 13+1;
	return a;
}

void totald()
{
	cout << "Total a dealer has " << dealer << endl;
	if (djack >=1)
	{
			cout << "with " << djack << " J" << endl;
	}
	if (dqueen >=1)
	{
			cout << "with " << dqueen << " Q" << endl;
	}
	if (dking >=1)
	{
			cout << "with " << dking << " K" << endl;
	}
	if (dace >=1)
	{
			cout << "with " << dace << " A" << endl;
	}
	if (dace == 0, djack == 0, dqueen == 0, dking == 0)
	{
		cout << "with no face cards" << endl;
	}
}
void totalp()
{
	cout << " Total You have " << player << endl;
	if (jack >=1)
	{
			cout << "with " << jack << " J" << endl;
	}
	if (queen >=1)
	{
			cout << "with " << queen << " Q" << endl;
	}
	if (king >=1)
	{
			cout << "with " << king << " K" << endl;
	}
	if (ace >=1)
	{
			cout << "with " << ace << " A" << endl;
	}
	if (ace == 0, jack == 0, queen == 0, king == 0)
	{
		cout << "with no face cards" << endl;
	}
	
}


int main () {

char cont;


srand (time(NULL));

player = rand() % 10+1;
dealer = rand() % 10+1;



do
{

	
	int card = draw();
	if (card == 11)
	{
		card = 10;
		jack++;
	}
		else if (card == 12)
	{
		card = 10;
		queen++;
	}
		else if (card == 13)
	{
		card = 10;
		king++;
	}
		else if (card == 1)
	{
		ace++;
	}
	
	player = card + player;
		totalp();
		totald();
	
	if (player <= 21)
	
	{
		cout << "Wanna Hit or Stick? h/s" << endl;
		cin >> cont;
	}
	
	else 
	
	{
		cont = 'n';
		cout << "You Bust!" << endl;
	}
	
	

	
}
while (cont == 'h');

if (cont == 's')
{
	do 
	{
		int card2 = draw();
		
		if (card2 == 11)
	{
		card2 = 10;
		djack++;
	}
		else if (card2 == 12)
	{
		card2 = 10;
		dqueen++;
	}
		else if (card2 == 13)
	{
		card2 = 10;
		dking++;
	}
		else if (card2 == 1)
	{
		dace++;
	}
		dealer = card2 + dealer;
		totald();
		
		if (dealer <= 16)
		{
			do
			{
			int card3 = draw();
					if (card2 == 11)
						{
							card2 = 10;
							djack++;
						}
							else if (card2 == 12)
						{
							card2 = 10;
							dqueen++;
						}
							else if (card2 == 13)
						{
							card2 = 10;
							dking++;
						}
							else if (card2 == 1)
						{
							dace++;
						}
			dealer = card3 + dealer;
			cout << "dealer hits" << endl;
			totald();
			}
			while (dealer <= 16);
			
			if (dealer >= 22)
			{
				cout << "The Dealer Busts" << endl;
				cout << "Hurray! you win!" << endl;
				cont = 'n';
			}
			
			else if (dealer>=player)
				{
					cout << "The Dealer Wins" << endl;
					cont = 'n';
				}
			
			else 
				{
					cout << "Hurray! you win!" << endl;
					cont = 'n';
				}
		}
		else if (dealer >= 17)
		{
			
			if (dealer >= 22)
			{
				cout << "The Dealer Busts" << endl;
				cout << "Hurray! you win!" << endl;
				cont = 'n';
				
			}
			
			else 
			{
				cout << "The Dealer Sticks" << endl;
				
				if (dealer>=player)
				{
					cout << "The Dealer Wins" << endl;
					cont = 'n';
				}
				
				else 
				{
					cout << "Hurray! you win!" << endl;
					cont = 'n';
				}
			}
		}
	}
	while (cont == 's');
}


return 0;
}