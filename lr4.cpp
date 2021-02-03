#include <ctime>
#include <iostream>
#include <vector>

void print_vec(std::vector <int>& a)
{
    for (int v : a)
        std::cout << v << " ";
    std::cout << std::endl;
}

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void bubble_sort(std::vector <int>& a)
{
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void insertion_sort(std::vector <int>& a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int current = a[i];         /*создаю временную переменную, чтобы запомнить переменную для вставки (если она будет)*/
        int j = i - 1;              /*создаю индекс для сранения "вставочного" элемента с предыдущими значениями*/

        while (a[j] > current)      /*пока предыдущий элемент больше вставочного*/
        {
            a[j + 1] = a[j];        /*сдвигаю элементы вправо для корректной вставки*/
            j--;

            if (j == -1)            /*проверяю, не вышел ли я из цикла*/
                break;
        }

        a[j + 1] = current;         /*вставляю элемент на нужную позицию*/
    }
}

void merge(std::vector<int>& vec, std::vector<int>& vec1, std::vector<int>& vec2)
{
    int min1 = 0;     /*номер элемента минимального значения в левом массиве */
    int min2 = 0;     /*номер элемента минимального значения в правом массиве*/
    int min = 0;      /*номер элемента основного вектора*/

    while ((min1 < vec1.size()) && (min2 < vec2.size())) /*сравниваем позиции элементов и кладем их в основной массив     */
    {                                                    /*пока элементы хотя бы из одного масссива не перейдут в основной*/
        if (vec1[min1] < vec2[min2])
        {
            vec[min] = vec1[min1];
            min1++;
        }
        else
        {
            vec[min] = vec2[min2];
            min2++;
        }
        min++;
    }

    while (min1 < vec1.size())   /*кладем оставшиеся элементы из кусочных массивов в основной*/
    {
        vec[min] = vec1[min1];
        min1++;
        min++;
    }

    while (min2 < vec2.size())
    {
        vec[min] = vec2[min2];
        min2++;
        min++;
    }
}

void merge_sort(std::vector<int>& a)
{
    if (a.size() < 2)
        return;

    int middle = a.size() / 2;
    std::vector<int> left(middle);
    std::vector<int> right(a.size() - middle);

    for (int i = 0; i < middle; i++) 
        left[i] = a[i];

    for (int i = middle; i < a.size(); i++)
        right[i - middle] = a[i];

    merge_sort(left);       /*рекурсивно делим левую часть массива, пока его размер не будет равен 1 */
    merge_sort(right);      /*рекурсивно делим правую часть массива, пока его размер не будет равен 1*/
    merge(a, left, right);  /*соединяем отсортированные части массива */
}

int main()
{
    int size;
    std::cout << "Enter the size of vector: ";
    std::cin >> size;

    std::srand(std::time(nullptr));

    std::vector<int> array(size);
    std::cout << "Not sorted array: ";
    for (int i = 0; i < array.size(); i++)
    {
        array[i] = std::rand() % 201 - 100;
        std::cout << array[i] << " ";
    }

    std::cout << std::endl << std::endl << "Merge sort: ";
    merge_sort(array);
    print_vec(array);

    std::cout << std::endl << "Bubble sort: ";
    bubble_sort(array);
    print_vec(array);
   
    std::cout << std::endl << "Insertion sort: ";
    insertion_sort(array);
    print_vec(array);

    return 0;
}
