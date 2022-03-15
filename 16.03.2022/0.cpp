#include <iostream>

void printline(int n, int padding)
{
    if(padding > 0)
    {
        std::cout << ' ';
        printline(n, padding - 1);
    }
    else if(n > 1)
    {
        std::cout << "**";
        printline(n - 1, padding);
    }
    else if(n == 1)
    {
        std::cout << "*\n";
    }
}

void printlevel(int n, int padding)
{
    if(n > 1)
        printlevel(n - 1, padding); 
    printline(n, padding - n + 1);
}

void t(int n, int padding)
{
    if(n > 1)
    {
        t(n - 1, padding);
        printlevel(n, padding);
    }

}

void tree(int n)
{
    t(n + 1, n);
}

int main()
{
    tree(4);
}
