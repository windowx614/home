//
// Created by zbn on 2022/5/23.
//

/*
 * 基本排序算法总结以及优化实现
 */

#ifndef C_C___DATASTRUCTURE_ALGORITHMUS_SORT_H
#define C_C___DATASTRUCTURE_ALGORITHMUS_SORT_H

#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <stdlib.h>

using std::map;
using std::string;
using std::cout;
using std::endl;

class Sort {
public:
    Sort(int num);//传入长度并初始化sortArray,此时全是零
    void initSortArray();//用随机数填满整个数组
    void printAll();//打印整个数组
    void beginCounter();
    void endCounter();//返回微秒
public:
    int m_num;//数组长度
    int* sortArray;
    LARGE_INTEGER beginTime, endTime, frequence;
    double time_us;
    map<string, double> timeDictSorting[10];
//所有排序算法
public:
    //冒泡排序
    void bubbleSort(int* array);
    //选择排序
    void selectionSort(int* array);
    //插入排序
    void insertionSort(int* array);
    //快速排序
    void quickSort(int* array);
    //归并排序
    void mergeSort(int* array);
    //计数排序
    void countingSort(int* array);
    //基数排序LSD
    void RadixSortLSD(int* array);
    //基数排序MSD
    void RadixSortMSD(int* array);
    //桶排序
    void bucketSort(int* array);
    //梳子排序
    void combSort(int* array);
    //希尔排序
    void shellSort(int* array);
    //堆排序
    void heapSort(int* array);
    //内省排序
    void introSort(int* array);
    //鸡尾酒排序
    void cocktailShakerSort(int* array);
    //侏儒排序
    void gnomeSort(int* array);
    //双调排序
    void bitonicSort(int* array);
    //bogo排序
    void bogoSort(int* array);
public:
    ~Sort();
};


#endif //C_C___DATASTRUCTURE_ALGORITHMUS_SORT_H
