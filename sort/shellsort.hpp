#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

#include <functional>
#include "insertionsort.hpp"

/********************************************************************************
 *                            希尔排序(SHELLSORT)
 *-------------------------------------------------------------------------------
 * 1. 首先将数据以步长gap分为多个组，即没连续gap个数为一个组
 * 2. 每一组第一个数字看成是一个数组，进行一次插入排序
 * 3. 接着是每个组第二个数字，直到这个数字大于gap
 * 4. 缩小gap的大小重复第2-3步
 * 5. 直到gap小于等于0
 * ==============================================================================
 * 注意： gap的大小适合黄金分割时(1, 5, 19...),会使希尔排序达到较快的速度
 * 即： O(n log2 n)
 *
 * */

int GetGap(int size)
{
    return 1;
}

int NextGap(int gap)
{
    return --gap;
}

template<typename _Ty, typename _Comp>
void ShellSort(_Ty *arr, int size, _Comp comp = greater<_Ty>())
{
   int gap = GetGap(size);
   for(; gap >= 1; gap = NextGap(gap))
   {
       InsertionSort(arr, size, comp, gap);
   }
}
#endif
