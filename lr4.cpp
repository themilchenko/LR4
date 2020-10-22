#include <iostream>
#include <ctime>
#include <vector>

void vecprint(std::vector <int>& a) // printing of our array
{
    for (int v : a)
        std::cout << v << " ";
    std::cout << std::endl;
}

void swap(int& a, int& b) // change places of two elements of array
{
    int t = a;
    a = b;
    b = t;
}

void bubblesort(std::vector <int>& a)
{
    std::cout << "Bubble sort array: ";
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    vecprint(a);
}

void insertionsort(std::vector <int>& a)
{
    std::cout << "Insertion sort array: ";
    for (int i = 1; i < a.size(); i++)
        for (int j = i; ((j > 0) && (a[j - 1] > a[j])); j--)
            swap(a[j], a[j + 1]);
    vecprint(a);
}

void merge(std::vector<int>& a, int left, int middle, int right)
{
    int i, j, k, nl, nr;
    nl = middle - left + 1;
    nr = right - middle;
    std::vector<int> larr(nl);
    std::vector<int> rarr(nr);
    for (i = 0; i < nl; i++)
        larr[i] = a[left + i];
    for (j = 0; j < nr; j++)
        rarr[i] = a[middle + 1 + j];
    i = 0; j = 0; k = left;
    while ((i < nl) && (j < nr))
    {
        if (larr[i] <= rarr[j])
        {
            a[k] = larr[i];
            i++;
        }
        else
        {
            a[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        a[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        a[k] = rarr[j];
        j++;
        k++;
    }
}

void mergesort(std::vector <int>& a, int left, int right)
{
    int middle;
    if (left < right)
    {
        middle = left + (right - left) / 2;
        mergesort(a, left, middle);
        mergesort(a, middle + 1, right);
        merge(a, left, middle, right);
    }
    vecprint(a);
}

int main()
{
    int n;
    std::cout << "Number digits in array: ";
    std::cin >> n;
    std::srand(std::time(nullptr));
    std::cout << "Random digits before sorting: ";
    std::vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = std::rand() % 201 - 100;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    bubblesort(a);
    insertionsort(a);
    mergesort(a, 0, n - 1);
    return 0;
}
