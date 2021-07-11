#include<bits/stdc++.h>
#include"blackjack.hpp"
using namespace std;
int i=0;

player::player( )
{
     sum=0;
	 totalWin=0;
	 numberOfCards=0;
}

player::~player()
{
}

void result(playerWithCash &user, player &dealer, card &card1)
{
	std::cout<<"\nIn Players Hand\n";
	for(int j=0;j<user.numberOfCards;j++)
	{
		if(user.mycards[j].pointsValue==11)
				std::cout<<user.mycards[j].face<<" of "<<user.mycards[j].suit<<" of value : "<<"Best of 1 or 11"<<"\n";
	    else
				std::cout<<user.mycards[j].face<<" of "<<user.mycards[j].suit<<" of value : "<<user.mycards[j].pointsValue<<"\n";
	}
	
	std::cout<<"\nIn Dealer Hand\n";
	for(int j=0;j<dealer.numberOfCards;j++)
	{
		if(dealer.mycards[j].pointsValue==11)
				std::cout<<dealer.mycards[j].face<<" of "<<dealer.mycards[j].suit<<" of value : "<<"Best of 1 or 11"<<"\n";
		else	
				std::cout<<dealer.mycards[j].face<<" of "<<dealer.mycards[j].suit<<" of value : "<<dealer.mycards[j].pointsValue<<"\n";
	}
	cout<<"\nPlayer point : "<<user.sum<<" Dealer point : "<<dealer.sum<<"\n";
	cout<<"\nPlayer win : "<<user.totalWin<<" | Dealer win : "<<dealer.totalWin<<"\n";
	cout<<"Remaining cash in your hand :"<<user.inHand<<"\n";
}

void reset(playerWithCash &user, player &dealer,card &card1)
{
	user.mycards.clear();
	user.numberOfCards=0;
	user.sum=0;
	dealer.mycards.clear();
	dealer.numberOfCards=0;
	dealer.sum=0;
	if(i>=42)
	{
		card1.shuffle();
		i=0;
	}
}

playerWithCash:: playerWithCash()
{
	std::cout<<"\nEnter your amount $(0-1000)\n";
	cin>>totalcash;
	if(totalcash>1000)
		totalcash=1000;
	inHand=totalcash;
	bet=0;
}

playerWithCash:: ~playerWithCash()
{
}

void printDeck(playerWithCash &user,player &dealer)
{
	std::cout<<"\nPlayers collections\n";
	for(int j=0;j<user.numberOfCards;j++)
	{
		if(user.mycards[j].pointsValue==11)
				std::cout<<user.mycards[j].face<<" of "<<user.mycards[j].suit<<" of value : "<<"Best of 1 or 11"<<"\n";
	    else
				std::cout<<user.mycards[j].face<<" of "<<user.mycards[j].suit<<" of value : "<<user.mycards[j].pointsValue<<"\n";
	}
	
	std::cout<<"\nDealer collections\n";
	std::cout<<"\n1st card Hidden\n";
	for(int j=1;j<dealer.numberOfCards;j++)
	{
		if(dealer.mycards[j].pointsValue==11)
				std::cout<<dealer.mycards[j].face<<" of "<<dealer.mycards[j].suit<<" of value : "<<"Best of 1 or 11"<<"\n";
		else	
				std::cout<<dealer.mycards[j].face<<" of "<<dealer.mycards[j].suit<<" of value : "<<dealer.mycards[j].pointsValue<<"\n";
	}
	
}

	

template <typename T>
void hit(T &obj,card &card1)
{
	obj.mycards.push_back(card1.Deck[i]);
	if(card1.Deck[i].pointsValue==11 && obj.sum>10)
		obj.sum+=1;
	else
		obj.sum+=card1.Deck[i].pointsValue;
	i++;
	obj.numberOfCards++;
}


card::card()
{
    int New_Suit = 0;
    string faces[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    string suits[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
    int CardValue[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
    for (int x = 0; x < 52; x++)
    {

	    Deck[x].face = faces[x % 13];
	    Deck[x].suit = suits[New_Suit];
	    Deck[x].pointsValue = CardValue[x % 13];
	    if ((x + 1) % 13 == 0)
		    New_Suit++;
    }
}

card::~card()
{
}

void isplay(playerWithCash &user,player &dealer,card &card1)
{
	while(1)
	{
		int ch;
		cout<<"\n1.HIT\t2.STAY\n";
		std::cin>>ch;
		if(ch==1)
		{
			hit(user,card1);
			if(user.sum==21)
			{
				user.inHand+=2.5*user.bet;
				std::cout<<"\nBlackJack....\n";
				return ;
			}
			else if(user.sum>21)
			{
				//dealer.totalWin++;
				std::cout<<"\nPlayer Busted.\nDealer win\n";
				return ;
			}
			printDeck(user,dealer);
		}
		else if(ch==2)
		{
			std::cout<<"\nStayed\n";
			return ;
		}
		else
			std::cout<<"\nPress 1 or 2\n";
	}
} 

void play(playerWithCash &user, player &dealer,card &card1)
{
	std::cout<<"\nEnter amount for bet\n";
	cin>>user.bet;
	if(user.bet==0){
		cout<<"LOL........\n";
		return ;
	}
	else if(user.inHand>=user.bet){
		user.inHand-=user.bet;
	}
	else
	{
		std::cout<<"\nOut of Money\n";
		return;
	}
	
	dealer.mycards.push_back(card1.Deck[i]);
	dealer.sum+=card1.Deck[i++].pointsValue;
	dealer.mycards.push_back(card1.Deck[i]);
	dealer.sum+=card1.Deck[i++].pointsValue;
	dealer.numberOfCards=2;
	
	user.mycards.push_back(card1.Deck[i]);
	user.sum+=card1.Deck[i++].pointsValue;
	user.mycards.push_back(card1.Deck[i]);
	user.sum+=card1.Deck[i++].pointsValue;
	user.numberOfCards=2;
	
	printDeck(user,dealer);
	
	if(user.sum==21)
	{
		user.inHand+=2.5*user.bet;
		user.totalWin++;
		std::cout<<"\nBlackJack....\n";
		result(user,dealer,card1);
		return ;
	}

	
	isplay(user,dealer,card1);
	
	if(user.sum>21)
	{
		dealer.totalWin++;
		std::cout<<"\nPlayer Busted.\nDealer win\n";
		result(user,dealer,card1);
		return ;
	}
	while(dealer.sum<=17)
	{
		hit(dealer,card1);
		printDeck(user,dealer);
	}
	if(dealer.sum>21)
	{
		user.totalWin++;
		user.inHand+=2*user.bet;
		std::cout<<"\nDealer Bust.\nPlayer win\n";
		result(user,dealer,card1);
		return ;
	}

	if(user.sum>dealer.sum)
	{
		user.totalWin++;
		user.inHand+=2*user.bet;
		std::cout<<"\nPlayer win\n";
		result(user,dealer,card1);
	}
	else if(user.sum<dealer.sum)
	{
		dealer.totalWin++;
		std::cout<<"\nDealer win\n";
		result(user,dealer,card1);
	}
	else
	{
		user.inHand+=user.bet;
		std::cout<<"\nMatch....Draw.........\n";
		result(user,dealer,card1);
	}
	return ;

}

void iscontinue(playerWithCash &user, player &dealer, card &card1)
{
	while(1)
	{
		int t;
		std::cout<<"\n1.Play \n2.Quit\n";
		reset(user,dealer,card1);
		cout<<std::endl;
		cin>>t;
		if(t==1)
		{
			if(user.inHand<=0)
			{
				std::cout<<"\nOops.....out of MONEY\n";
				return ;
			}
			play(user,dealer,card1);
		}
		else if(t==2)
		{
			return ;
		}
		else{
			std::cout<<"\nPress 1 or 2\n";
		}
	}
}

void newGame()
{
	playerWithCash user;
	player dealer;
	card card1;
	card1.shuffle();
	
	// for (int x = 0; x < 52; x ++)
	// {
	// 	cout << card1.Deck[x].face << " of " << card1.Deck[x].suit << " : Value of " << card1.Deck[x].pointsValue << " : " << endl;
	// }
	

	iscontinue(user,dealer,card1);
}



void card::shuffle()
{
	srand(time(0));
    for (int x = 0; x < 999; x++)
	{
		int a = rand() % 52;
		int b = rand() % 52;

       swap(Deck[a],Deck[b]);

	}
}




void show()
{
    std::cout<<"1.Start New Game\n";
    std::cout<<"2.Exit From Game\n";
}









