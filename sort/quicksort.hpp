#ifndef _QUICKSORT_HPP
#define _QUICKSORT_HPP

#include <stdlib.h>
#include <time.h>
#include <functional>
#include "wrap.hpp"


/*****************************************************************************************
*                                       快速排序
* ---------------------------------------------------------------------------------------
* 1. 从数列中挑出一个元素，称为"基准"（pivot）
* 2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面
* 3. 在这个分区结束之后，该基准就处于数列的中间位置。这个称为分区（partition）操作
* 4. 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序
* 5. 递归的最底部情形，是数列的大小是零或一，也就是永远都已经被排序好了
* 6. 虽然一直递归下去，但是这个算法总会结束，因为在每次的迭代（iteration）中，它至少会把
*		一个元素摆到它最后的位置去
*****************************************************************************************/

template<typename _Ty, typename _Comp>
int Partition(_Ty *arr, int left, int right, _Comp comp)
{
    _Ty mid = arr[left];
    while(left < right)
    {
        while(comp(arr[right], mid) && left < right)
        {
            --right;
        }
        if(left < right)
            arr[left] = arr[right];
        while(comp(mid, arr[left]) && left < right)
        {
            ++left;
        }
        if(left < right)
            arr[right] = arr[left];
    }
    arr[left] = mid;
    return left;
}

template<typename _Ty, typename _Comp>
int RandomPartition(_Ty *arr, int left, int right, _Comp comp)
{
    srand((int)time(NULL));
    int pos = rand() % (right - left) + left;
    Swap(arr[left], arr[pos]);
    return Partition(arr, left, right, comp);

}

template<typename _Ty, typename _Comp>
void QuickSort(_Ty *arr, int left, int right, _Comp comp = greater<_Ty>())
{
    if(left >= right)
        return;
    int pos = RandomPartition(arr, left, right, comp);
    QuickSort(arr, left, pos - 1, comp);
    QuickSort(arr, pos + 1, right, comp);
}

template<typename _Ty, typename _Comp>
void QuickSort(_Ty *arr, int size, _Comp comp = greater<_Ty>())
{
    QuickSort(arr, 0, size - 1, comp);
}

#endif
