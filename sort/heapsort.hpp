#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_



#include "heap.hpp"










template<typename _Ty, typename _Comp>
void DoSort(Heap<_Ty, _Comp> heap, _Ty *arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        heap.remove_heap(arr[i]);
    }
}



template<typename _Ty, typename _Comp>
void HeapSort(_Ty *arr, int size, _Comp comp)
{
    Heap<_Ty, _Comp> mheap(arr, size);
    DoSort(mheap, arr, size);
}

#endif
