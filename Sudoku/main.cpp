#include<bits/stdc++.h>
#include"sudoku.hpp"

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
                std::cout<<"Lets solve\n";
                solve();
            case 2:
                std::cout<<"\nThanks For Playing\n";
                exit(0);
            default:
                std::cout<<"Enter valid number\n";

        }
    }

    return 0;
}
 