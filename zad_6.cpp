#include <iostream>

void reverseTab(char *tablica)
{
    if (*tablica == '\0')
        return;
    else
    {
        reverseTab(tablica + 1);
        std::cout << *tablica;
    }
}
int main()
{
    std::cout << "--------- ZADANIE 6 --------- \n";
    char tablica[] = {"a,b,c,d,e,f,g,h,i,j"};
    reverseTab(tablica);
    return 0;
}