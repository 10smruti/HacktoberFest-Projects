/* Computer guesses user number in range (1, 2000000) in 32 tries  
The idea of this game is binary search. 
Here is an example of it : https://www.geeksforgeeks.org/binary-search/ .
*/

#include <iostream>
#include <algorithm>
#include <random>

void binarysearch(bool &won)
{
    int guesses = 32;
    int l = 1, r = 2000000;
    while (l <= r && guesses > 0 && !won)
    {
        int guess = l + (r - l) / 2;
        std::cout << "Computer guess is " << guess << ".\n";
        std::flush(std::cout);
        std::string user;
        std::getline(std::cin, user);
        std::for_each(user.begin(), user.end(), [](char &c) { return tolower(c); });
        if (user == "equal")
        {
            std::cout << "The number was " << guess << ".\n";
            won = true;
        }
        else if (user == "smaller")
        {
            r = guess - 1;
        }
        else
        {
            l = guess + 1;
        }
        guesses--;
        if (!won)
            std::cout << "The computer has " << guesses << " guesses left.\n";
    }
}

void random(bool &won)
{
    int guesses = 32;
    int l = 1, r = 2000000;
    while (l <= r && guesses > 0 && !won)
    {
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist(l, r);
        int guess = dist(mt);
        std::cout << "Computer guess is " << guess << ".\n";
        std::flush(std::cout);
        std::string user;
        std::getline(std::cin, user);
        std::for_each(user.begin(), user.end(), [](char &c) { return tolower(c); });
        if (user == "equal")
        {
            std::cout << "The number was " << guess << ".\n";
            won = true;
        }
        else if (user == "smaller")
        {
            r = guess - 1;
        }
        else
        {
            l = guess + 1;
        }
        guesses--;
        if (!won)
            std::cout << "The computer has " << guesses << " guesses left.\n";
    }
}

int main()
{
    int num;
    system("clear");
    std::cout << "\033[1;33m";
    std::cout << "Rules:\n1.If the guess is bigger than your number, write smaller, if it is equal, write equal, otherwise bigger.\n";
    std::cout << "You can choose from searching a number using binary search or by using random.\n";
    std::cout << "1. Binary\n2. Random\n";
    int choice;
    bool won = false;
    std::cin >> choice;
    std::cin.ignore();
    if(choice == 1)
    {
        binarysearch(won);
    }
    else 
    {
        random(won);
    }
    if (won)
    {
        std::cout << "Computer knew it.\n";
    }
    else
    {
        std::cout << "Somehow, I was mistaken.\n";
    }
    std::cout << "\033[0m";
    std::cin.ignore();
    return 0;
}