#pragma once
#include<bits/stdc++.h>

class card
{    
public:
    struct DefineCard
    {
	    std::string suit;
	    std::string face;
	    int pointsValue;    
    } Deck[53];
    card();
    void shuffle();
    ~card();
};

 
 
class player
{    
public:
    int sum;
    int numberOfCards;
    int totalWin;
    std::vector<card::DefineCard> mycards;
    player();
    ~player();
};


class playerWithCash: public player{
    public:
        int totalcash;
        int bet;
        int inHand;

        playerWithCash();
        ~ playerWithCash();
};

void newGame();
void show();

