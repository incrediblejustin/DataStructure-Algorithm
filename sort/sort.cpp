
#include <iostream>
#include <functional>

#include "shellsort.hpp"
#include "insertionsort.hpp"
#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "wrap.hpp"
using namespace std;



/****************************************************************************************
 *                                     稳定的排序
 * --------------------------------------------------------------------------------------
 *  冒泡排序（bubble sort）― O(n2)                                       -- done
 *  插入排序（insertion sort）― O(n2)                                    -- done                         
 *  桶排序（bucket sort）― O(n)；需要O(k)额外空间
 *  归并排序（merge sort）― O(n log n)；需要O(n)额外空间                   -- done
 *  原地归并排序 ― O(n log2 n)如果使用最佳的现在版本
 *  二叉排序树排序（binary tree sort）― O(n log n)期望时间；O(n2)最坏时间；需要O(n)额外空间
 *  基数排序（radix sort）― O(n・k)；需要O(n)额外空间
 * =======================================================================================
 *                                     不稳定的排序
 * ---------------------------------------------------------------------------------------
 *  选择排序（selection sort）― O(n2)                                    -- done
 *  希尔排序（shell sort）― O(n log2 n)如果使用最佳的现在版本            -- done
 *  堆排序（heap sort）― O(n log n)
 *  快速排序（quick sort）― O(n log n)期望时间，O(n2)                      -- done
 *           最坏情况；对于大的、随机数列表一般相信是最快的已知排序
 ****************************************************************************************/




int main()
{
	//int arr[] = { 99, 88, 66, 77, 55, 33, 44, 22, 11 };
	int arr[] = { 11, 99, 55, 66, 77, 88, 22, 33, 44 };
	const int size = sizeof(arr) / sizeof(arr[0]);

	//BubbleSort(arr, size, greater<int>());
	//SelectionSort(arr, size, greater<int>());
    //QuickSort(arr, size, greater<int>());
    //MergeSort(arr, size, greater<int>());
    //InsertionSort(arr, size, greater<int>());
    ShellSort(arr, size, greater<int>());
	Print_1(arr, arr + size);
	return 0;
}
