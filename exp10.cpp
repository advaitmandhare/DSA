#include <iostream>
using namespace std;

void insertMinHeap(int arr[], int i)
{
    int parent = (i - 1) / 2;
    int current = i;

    while (parent >= 0 && arr[parent] > arr[current])
    {
        swap(arr[parent], arr[current]);
        current = parent;
        parent = (current - 1) / 2;
    }
}

void insertMaxHeap(int arr[], int i)
{
    int parent = (i - 1) / 2;
    int current = i;

    while (parent >= 0 && arr[parent] < arr[current])
    {
        swap(arr[parent], arr[current]);
        current = parent;
        parent = (current - 1) / 2;
    }
}

int main()
{
    int arr[] = {20, 30, 15, 2, 5, 10};

    cout << "INTEGER ARRAY: " << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 1; i < 6; i++)
    {
        insertMinHeap(arr, i);
    }
    cout << "\n\nAfter Inserting in min heap: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nmin element: " << arr[0] << endl;

    for (int i = 1; i < 6; i++)
    {
        insertMaxHeap(arr, i);
    }
    cout << "\n\nAfter Inserting in max heap: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nmax element: " << arr[0] << endl;
}