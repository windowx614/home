//
// Created by zbn on 2022/5/23.
//

#include "Sort.h"
#include <algorithm>
#include <time.h>



Sort::Sort(int num) {
    this->m_num = num;
}

void Sort::initSortArray() {
    sortArray = new int[this->m_num];
    for (int i = 0; i < this->m_num; ++i) {
        sortArray[i] = 1 + rand()%(this->m_num*2);
    }
    //得到真正的随机数组
    std::random_shuffle(sortArray,sortArray+this->m_num);
}

void Sort::printAll() {
    for (int i = 0; i < this->m_num; ++i) {
        cout << this->sortArray[i] << " ";
    }
    cout << endl;
}

void Sort::beginCounter() {
    QueryPerformanceFrequency(&frequence);
    QueryPerformanceCounter(&beginTime);
}
void Sort::endCounter() {
    QueryPerformanceCounter(&endTime);
    this->time_us = 1000*(double)(endTime.QuadPart - beginTime.QuadPart)/(double)frequence.QuadPart;
}

//冒泡排序
void Sort::bubbleSort(int* array){

}
//选择排序
void Sort::selectionSort(int* array){

}
//插入排序
void Sort::insertionSort(int* array){

}
//快速排序
void Sort::quickSort(int* array){

}
//归并排序
void Sort::mergeSort(int* array){

}
//计数排序
void Sort::countingSort(int* array){

}
//基数排序LSD
void Sort::RadixSortLSD(int* array){

}
//基数排序MSD
void Sort::RadixSortMSD(int* array){

}
//桶排序
void Sort::bucketSort(int* array){

}
//梳子排序
void Sort::combSort(int* array){

}
//希尔排序
void Sort::shellSort(int* array){

}
//堆排序
void Sort::heapSort(int* array){

}
//内省排序
void Sort::introSort(int* array){

}
//鸡尾酒排序
void Sort::cocktailShakerSort(int* array){

}
//侏儒排序
void Sort::gnomeSort(int* array){

}
//双调排序
void Sort::bitonicSort(int* array){

}
//bogo排序
void Sort::bogoSort(int* array){

}

Sort::~Sort() {
    if (this->sortArray != nullptr){
        delete[] sortArray;
    }
}
