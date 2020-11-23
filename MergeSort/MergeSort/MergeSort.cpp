/*
* Title: Merge Sort
* Author: Edgar Podvezko
* Date: 2020
* Software: Visual Studio 2019
*/

#include <iostream>
#include <list>

using namespace std;

void Merge(int *arr, int min, int max, int med) {

    int i = min,
        j = med+1,
        k = 0,
        temp[20];

    // Merge 2 parts into temp[]
    while (i <= med && j <= max)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
			k++;
			j++;
        }
    }

    // Insert remaining values from left into temp[]
    while (i <= med)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    // Now right side to temp[]
    while (j <= max)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    //Now move data to arr[]
    for (i = min; i <= max; i++)
    {
        arr[i] = temp[i-min];
    }


}

void MergeSort(int *arr, int min, int max)
{
    int med;
    if (min < max)
    {
        med = (min+max)/2;
        MergeSort(arr, min, med);
        MergeSort(arr, med+1, max);
        Merge(arr, min, max, med);
    }
}

int main()
{
    int n;
    cout << "Enter the amount of numbers to sort (up to 20): ";
    cin >> n;
    int arr[21];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i+1 << "th element: ";
        cin >> arr[i];
    }

    MergeSort(arr, 0, n-1);

    // Print
    cout << "\nSorted Data: ";
    for (int i = 0; i < n; i++)
        cout << "-" << arr[i];

    return 0;
}