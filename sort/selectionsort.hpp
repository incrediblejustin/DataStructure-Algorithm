#ifndef _SELECTIONSORT_HPP_
#define _SELECTIONSORT_HPP_

#include <functional>
#include "wrap.hpp"


/*************************************************************************************
*                              选择排序（Selection sort）
* -----------------------------------------------------------------------------------
* 1. 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
* 2. 然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
* 3. 以此类推，直到所有元素均排序完毕。
*************************************************************************************/
template<typename _Ty, typename _Comp>
void SelectionSort(_Ty *arr, int len, _Comp comp = greater<_Ty>())
{
    int min_index = 0;
    for(int i = 0; i < len - 1; ++i)
    {
        min_index = i;
        for(int j = i + 1; j < len; ++j)
        {
            if(comp(arr[min_index], arr[j]))
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            Swap(arr[i], arr[min_index]);
        }
    }
}
#endif
