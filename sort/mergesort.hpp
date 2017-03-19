#ifndef _MERGESORT_HPP_
#define _MERGESORT_HPP_

#include <functional>
/****************************************************************************************
* 迭代法
* --------------------------------------------------------------------------------------
* 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
* 设定两个指针，最初位置分别为两个已经排序序列的起始位置
* 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
* 重复步骤3直到某一指针到达序列尾
* 将另一序列剩下的所有元素直接复制到合并序列尾
* =======================================================================================
*                                       递归法
* ---------------------------------------------------------------------------------------
* 1. 将序列每相邻两个数字进行归并操作，形成 floor(n/2)个序列，排序后每个序列包含两个元素
* 2. 将上述序列再次归并，形成floor(n/4)个序列，每个序列包含四个元素
* 3. 重复步骤2，直到所有元素排序完毕
*****************************************************************************************/



template<typename _Ty, typename _Comp>
void Merge(_Ty *dst, _Ty *src, int left, int mid, int right, _Comp comp)
{
    int i = left;
    int j = mid + 1;
    int dst_index = left;
    while(i <= mid && j <= right)
    {
        dst[dst_index++] = comp(src[j], src[i]) ? src[i++] : src[j++];  
    }
    while(i <= mid)
    {
        dst[dst_index++] = src[i++];
    }
    while(j <= right)
    {
        dst[dst_index++] = src[j++];
    }
}

template<typename _Ty>
void MergeCopy(_Ty *dst, _Ty *src, int left, int right)
{
    for(int i = left; i <= right; ++i)
    {
        dst[i] = src[i];
    }
}

template<typename _Ty, typename _Comp>
void MergePass(_Ty *dst, _Ty *src, int left, int right, _Comp comp)
{
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergePass(dst, src, left, mid, comp);
    MergePass(dst, src, mid + 1, right, comp);
    Merge(dst, src, left, mid, right, comp);
    MergeCopy(src, dst, left, right);
}


template<typename _Ty, typename _Comp>
void MergeSort(_Ty *arr, int size, _Comp comp = greater<_Ty>())
{
    _Ty *dst = new _Ty[size];
    MergePass(dst, arr, 0, size - 1, comp);
}



































/*
template<typename _Ty, typename _Comp>
void Merge(_Ty *dst, _Ty *src, int left, int mid, int right, _Comp comp = greater<_Ty>())
{
	int i = left, j = mid + 1;
	int dst_index = left;
	while (i <= mid && j <= right)
	{
		dst[dst_index++] = comp(src[j], src[i]) ? src[i++] : src[j++];
	}
	while (i <= mid)
	{
		dst[dst_index++] = src[i++];
	}
	while (j <= right)
	{
		dst[dst_index++] = src[j++];
	}
}

template<typename _Ty>
void MergeCopy(_Ty *dst, _Ty *src, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		dst[i] = src[i];
	}
}

template<typename _Ty, typename _Comp>
void MergePass(_Ty *dst, _Ty *src, int left, int right, _Comp comp = greater<_Ty>())
{
	if (left >= right)
		return;

	int mid = (right - left) / 2 + left;
	MergePass(dst, src, left, mid, comp);
	MergePass(dst, src, mid + 1, right, comp);
	Merge(dst, src, left, mid, right, comp);
	MergeCopy(src, dst, left, right);
}


template<typename _Ty, typename _Comp>
void MergeSort(_Ty *arr, int len, _Comp comp = greater<_Ty>())
{
	_Ty *dst = new _Ty[len];
	MergePass(dst, arr, 0, len - 1, comp);
	delete []dst;
}

*/



#endif
