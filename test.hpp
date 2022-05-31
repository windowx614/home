//
// Created by zbn on 2022/5/22.
//
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DynamicArrayC.hpp"
#include "DynamicArray.h"
#include "LinkedListC.hpp"
#include "Sort.h"

using std::cout;
using std::endl;

void testDynamicArrayC_01(){
    dynamicArrayInt* arr01 = initDynamicArrayInt();
    pushBackArray(arr01,25);
    pushBackArray(arr01,43);
    pushBackArray(arr01,6);
    printWholeArray(arr01);
    cout << findValueByLocation(arr01,2) << endl;
    pushBackArray(arr01,97);
    printWholeArray(arr01);
    insertElement(arr01,2333,3);
    printWholeArray(arr01);
    deleteElementByLocation(arr01,3);
    printWholeArray(arr01);
    deleteElementByValue(arr01,6);
    printWholeArray(arr01);

    insertElement(arr01,614,2);
    insertElement(arr01,614,2);
    insertElement(arr01,614,2);
    insertElement(arr01,614,2);
    printWholeArray(arr01);
    findLocationByValue(arr01,614);
    cout << arr01->sizeLocArray << endl;
    for (int i = 0; i < arr01->sizeLocArray; ++i) {
        cout << arr01->locArray[i] << " ";
    }
    cout << endl;
    cout << findValueByLocation(arr01,1) << endl;
    printWholeArray(arr01);
    deleteElementByValue(arr01,614);
    printWholeArray(arr01);
    clearArray(arr01);
    printWholeArray(arr01);
    freeSpaceArray(arr01);
    //此处由于已经释放掉内存，所以打印出来的应该是随机数
    //printWholeArray(arr01);

}

typedef struct PERSON{
    char* name;
    int age;
    double weight;
}person;

//用户定义的打印函数
void userDefinedPrint(void* data){
    person* p = (person*)data;
    printf("Name:%s,\tAge:%d,\t  Weight:%d\n",p->name,p->age,p->weight);
}

void testLinkedListC_01(){
    double data_0 = 88.7;

    person person01 = {"Teddy",39, 113};
    person person02 = {"Winston",16, 87};
    person person03 = {"Andy",41, 92};
    person personxx = {"XXXXX",0, 0};

    //测试初始化和依次插入
    sLinkedList* list01 = initSLinkedList();
    insertSLinkedListNode(list01,1,&person01);
    insertSLinkedListNode(list01,2,&person02);
    insertSLinkedListNode(list01,3,&person03);
    printSLinkedList(list01,userDefinedPrint);
    //测试任意插入
    insertSLinkedListNode(list01,1,&personxx);
    printSLinkedList(list01,userDefinedPrint);
    //测试链表长度
    printf("size:%d\n", getSLinkedListSize(list01));
    //测试删除指定位置的值
    deleteSLinkedListNode(list01,1);
    printSLinkedList(list01,userDefinedPrint);
    //测试查找 测试不出来
    //int pos = findSNodeLocation(list01,&personxx);
    //printf("Pos:%d",pos);
    //测试链表长度
    printf("size:%d\n", getSLinkedListSize(list01));
    //测试返回第一个节点
    person* personFirst = (person*)getFirstNode(list01);
    userDefinedPrint(personFirst);

}

void testSort(){
    srand((unsigned int)time(NULL));
    int numElements = 20000000;
    Sort sortInstance(numElements);

    sortInstance.beginCounter();//开始计时
    sortInstance.initSortArray();
    //sortInstance.printAll();
    sortInstance.endCounter();
    cout << sortInstance.time_us << "us" << endl;//计时结束
}






