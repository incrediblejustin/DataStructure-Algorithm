#ifndef _INSERTION_HPP_
#define _INSERTION_HPP_

#include <functional>

#include "wrap.hpp"


/************************************************************
 *                     交换排序算法描述：
 * 1. 从第一个元素开始，钙元素可以认为已经被排序
 * 2. 取出下一个元素，在已经排序的元素中从后向前扫描
 * 3. 如果该元素小于已经排好序的元素，将已经排好序的元素向后移动一位
 * 4. 重复3步骤，知道找到已经排好序的元素小于等于该元素的位置
 * 5. 把该元素插入到这个位置之后
 * 6. 重复步骤2-5
 * **********************************************************/



template <typename _Ty, typename _Comp>
void InsertionSort(_Ty *arr, int size, _Comp comp = greater<_Ty>(), int gap = 1)
{
    _Ty temp = arr[gap];
    int next = gap;
    for(int i = 0; i < gap; ++i)
    {
        for(int cur = i + gap; cur < size; cur += gap)
        {
            temp = arr[cur];
            int prev = cur - gap;
            for(; prev >= 0 && comp(arr[prev], temp); prev -= gap)
            {
                arr[prev + gap] = arr[prev];
            }
            arr[prev + gap] = temp;
        }
    }
}



#endif
