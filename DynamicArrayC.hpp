//
// Created by 张炳楠 on 2022/5/22.
//
/* 动态数组
 * C Implementation
 * V0.1
 * 初始化申请一块内存用于存放数组，有固定capacity，满了以后重新申请新内存并增加capacity
 * API:
 *      初始化、
 *      pushBack，insert，
 *      按位置删除，按值删除，
 *      根据值查找位置，根据位置查找值，
 *      clear，getSize, getCapacity, print, 释放内存
 */

#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DYNAMICARRAYINT{
    int* pAddr;//存放数据
    int size;//数组大小
    int capacity;//数组容量
    int* locArray;//按值寻找返回的位置，包含重复可能性
    int sizeLocArray;//locArray的大小
}dynamicArrayInt;

//初始化返回一个结构体指针
dynamicArrayInt* initDynamicArrayInt(){
    dynamicArrayInt* arr = (dynamicArrayInt*)malloc(sizeof(dynamicArrayInt));//申请结构体内存
    arr->size = 0;//最开始数组没有数据但是元素会被初始化为0
    arr->capacity = 3;//最大容量
    arr->pAddr = (int*) malloc(sizeof(int) * arr->capacity);//为这32个int申请内存
    return arr;
}
//末端插入
void pushBackArray(dynamicArrayInt* arr, int value){
     if(arr == nullptr)
         return;
     //如果空间已经最大了则申请新空间并更新指向
     if(arr->size == arr->capacity){
         int* newSpace = (int*) malloc(sizeof(int) * arr->capacity * 2);
         //copy each byte
         memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
         free(arr->pAddr);
         arr->capacity *= 2;
         arr->pAddr = newSpace;
     }
     arr->pAddr[arr->size] = value;
     arr->size += 1;
}
//按位置插入，默认在所输入的index后面插入值
void insertElement(dynamicArrayInt* arr, int value,int loc){
    if(arr == nullptr)
        return;
    if(loc < 0 || loc > arr->size)
        printf("location incorrect or out of range!!");
    //如果空间已满
    if(arr->size == arr->capacity){
        //先申请新空间
        int* newSpace = (int*) malloc(sizeof(int) * arr->capacity * 2);
        memcpy(newSpace,arr->pAddr,arr->capacity * sizeof(int));
        free(arr->pAddr);
        arr->capacity *= 2;
        arr->pAddr = newSpace;
    }
    arr->size += 1;
    for (int i = arr->size-1; i > loc; --i) {
        arr->pAddr[i] = arr->pAddr[i - 1];
    }
    arr->pAddr[loc]= value;
}
//按位置删除
void deleteElementByLocation(dynamicArrayInt* arr, int loc){
    if (loc < 0 || loc >= arr->size){
        printf("location is not right or not in range!!");
    }
    for (int i = loc; i < arr->size - 1; ++i) {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }
    arr->size -= 1;
}
//按值删除,包含所有同样的值
void deleteElementByValue(dynamicArrayInt* arr, int val){
    if (arr == nullptr)
        return;
    for (int i = 0; i < arr->size; ++i) {
        if (arr->pAddr[i] == val){
            deleteElementByLocation(arr,i);
            --i;
        }
    }
}
//根据值查找位置，最坏情况就是所有值都一样
void findLocationByValue(dynamicArrayInt* arr, int val){
    if (arr == nullptr)
        printf("array is null!!!");
    arr->sizeLocArray = arr->size;
    //为sizeLocArray申请一块内存
    arr->locArray = (int*) malloc(sizeof(int) * arr->sizeLocArray);
    //初始化sizeLocArray数组
    for (int i = 0; i < arr->sizeLocArray; ++i) {
        arr->locArray[i] = 0;
    }
    int indexSizeLocArray = 0;
    for (int i = 0; i < arr->size; ++i) {
        if (arr->pAddr[i] == val){
            arr->locArray[indexSizeLocArray] = i;//把当前的loc放入结果数组中
            indexSizeLocArray++;
        }
    }
    //精简一下，把未使用的元素去掉
    arr->sizeLocArray = indexSizeLocArray;
    int* newSpace = (int*) malloc(sizeof(int) * (indexSizeLocArray+1));
    memcpy(newSpace,arr->locArray,sizeof(int) * (indexSizeLocArray+1));
    free(arr->locArray);
    arr->locArray = newSpace;
}
//根据位置查找值 空指针return-1肯定是不行的 先待定
int findValueByLocation(dynamicArrayInt* arr, int loc){
    if ((arr == nullptr) || (loc < 0 || loc >= arr->size))
        return -1;
    return arr->pAddr[loc];
}
//清空数组
void clearArray(dynamicArrayInt* arr){
    if (arr == nullptr)
        return;
    arr->size = 0;
}
//获得当前元素个数，空指针return-1
int getSizeOfArray(dynamicArrayInt* arr){
    if (arr == nullptr)
        return -1;
    return arr->size;
}
//获得当前数组容量
int getCapacityOfArray(dynamicArrayInt* arr){
    if (arr == nullptr)
        return -1;
    return arr->capacity;
}
//打印全部数组
void printWholeArray(dynamicArrayInt* arr){
    if (arr == nullptr)
        return;
    for (int i = 0; i < arr->size; ++i) {
        printf("%d ",arr->pAddr[i]);
    }
    printf("\n");
    printf("size:%d, capacity:%d\n", getSizeOfArray(arr), getCapacityOfArray(arr));
}
//删除数组，释放所有内存
void freeSpaceArray(dynamicArrayInt* arr){
    if (arr == nullptr)
        return;
    //先释放内层
    if (arr->pAddr == nullptr){
        free(arr->pAddr);
        free(arr->locArray);
    }
    //再释放外层
    free(arr);
}





#endif//DYNAMIC_ARRAY_HPP