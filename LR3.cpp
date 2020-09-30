#include <iostream>
#include <ctime>
#include <vector>

void vecprint(std::vector <int>& a)
{
    for (int v : a)
        std::cout << v << " ";
    std::cout << std::endl;
}


int bubblesort(std::vector <int>& a)
{
    std::cout << "Bubble sort array: ";
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    }
    vecprint(a);
}

int insertionsort(std::vector <int>& a)
{
    std::cout << "Insertion sort array: ";
    for(int i = 1; i < a.size(); i++)
        for(int j = i; ((j > 0) && (a[j - 1] > a[j])); j--)
        {
            int t = a[j];
            a[j] = a[j + 1];
            a[j + 1] = t;
        }
    vecprint(a);
}




int main()
{
    int n;
    std::cout << "Nummer digits in array: ";
    std::cin >> n;
    std::srand(std::time(0));
    std::cout << "Random digits: ";
    std::vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = std::rand()%201 - 100;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    bubblesort(a);
    insertionsort(a);
   // mergesort(a);
    return 0;
}