#include<bits/stdc++.h>
#include"blackjack.hpp"

int main()
{
    int choice;
    while(1)
    {
        show();
        std::cout<<"Enter your choice\n";
        std::cin>>choice;
        switch(choice)
        {
            case 1:
                newGame();
                break;
            case 2:
                std::cout<<"\nThanks For Playing\n";
                exit(0);
            default:
                std::cout<<"Enter valid number\n";

        }
    }

    return 0;
}
 