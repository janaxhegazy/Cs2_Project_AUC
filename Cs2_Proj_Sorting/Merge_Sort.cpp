#include "Merge_Sort.h"
#include"Fill.h"
#include<iostream>
Merge_Sort::Merge_Sort(int* ar, int left,int right) : compare(0), arr(ar), size(right)
{
    if (right > left)
    {
        int mid = (left + right) / 2;
        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }

}

void Merge_Sort::Merge(int* ar, int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    k = 0;
    int* temp = new int[right - left + 1];
    while (i <= mid && j <= right) //sorts and merges the 2 half arrays into the temporary array
    {
        if (ar[i] <= ar[j])
        {
            temp[k++] = ar[i];
            i++;
        }
        else
        {
            temp[k++] = ar[j];
            j++;
        }
        compare++;
    }
    while (i <= mid) //loop to drop the remaining contents of the left half array into the temporary array
    {
        temp[k++] = ar[i++];
    }
    while (j <= right)//loop to drop the remaining contents of the right half array into the temporary array
    {
        temp[k++] = ar[j++];
    }
    for (int i = left, k = 0; i <= right; i++,k++)//loop to copy the temp array into the original array
    {
        arr[i] = temp[k];
    }
    delete[]temp;//returns the borrowed memory to the heap

}


int Merge_Sort::get_count() const
{
	return this->compare;
}
void Merge_Sort::print_arr() const
{
    for (int i = 0; i < size+1; i++)
        std::cout << arr[i] << " ";
}

int Merge_Sort::get_Size() const
{
    return size+1;
}