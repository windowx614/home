//
// Created by zbn on 2022/5/23.
//

/* 单向传统链表
 * C Implementation
 * V0.1
 *
 * API:
 *      初始化、
 *      insert，delete，
 *      根据值查找位置，getSize，返回第一个节点
 *      打印节点，返回头节点，释放内存
 */

#ifndef CLIONC__TEST_LINKEDLISTC_HPP
#define CLIONC__TEST_LINKEDLISTC_HPP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//节点
typedef struct SINGLYLINKEDLISTNODE{
    void* data;//指向任何类型数据
    struct SINGLYLINKEDLISTNODE* next;//结构体尚未定义完成，需要struct声明，如果在C++编译器中则无所谓，这里养成好习惯
}sLinkedListNode;
//链表体
typedef struct SINGLYLINKEDLIST{
    sLinkedListNode* head;
    int size;
}sLinkedList;

//初始化:包含头节点（不保存信息）
sLinkedList* initSLinkedList(){
    sLinkedList* list = (sLinkedList*) malloc(sizeof(sLinkedList));
    list->size = 0;
    list->head = (sLinkedListNode*) malloc(sizeof(sLinkedListNode));
    list->head->data = NULL;
    list->head->next = nullptr;
    return list;
}
//插入，只需要传入地址就可以
void insertSLinkedListNode(sLinkedList* list, int pos, void* data){
    if (list == nullptr)
        return;
    if (data == nullptr)
        return;
    if (pos < 0 || pos > list->size){
        pos = list->size;
    }
    //先创建新节点
    sLinkedListNode* newNode = (sLinkedListNode*)malloc(sizeof(sLinkedListNode));
    newNode->data = data;
    newNode->next = nullptr;
    //找节点位置
    sLinkedListNode* ptrCurrent = list->head;
    for (int i = 0; i < pos; ++i) {
        ptrCurrent = ptrCurrent->next;
    }
    //出循环后已经找到pos处的节点，直接插入当前的和下一个节点中间
    //插入新节点
    newNode->next = ptrCurrent->next;//注意顺序不能错，否则newNode指向自己
    ptrCurrent->next = newNode;
    list->size++;
}
//删除指定位置的值
void deleteSLinkedListNode(sLinkedList* list, int pos){
    if (list == nullptr)
        return;
    if (pos < 0 || pos >= list->size)//size比最大index大1
        return;
    //找到删除节点的前一个节点
    sLinkedListNode* ptrCurrent = list->head;
    for (int i = 0; i < pos; ++i) {
        ptrCurrent = ptrCurrent->next;
    }
    //取出要删除的节点并把节点的next连接到ptrCurrent上
    sLinkedListNode* ptrDelete = ptrCurrent->next;
    ptrCurrent->next = ptrDelete->next;
    //释放内存
    free(ptrDelete);
    list->size--;
}
//根据值查找位置
//注意 这样写没办法进行测试因为是传入地址而不是数据所以判断不了是否相等
int findSNodeLocation(sLinkedList* list, void* data){
    if (list == nullptr || data == nullptr)
        return -1;
    sLinkedListNode* ptrCurrent = list->head;
    int pos = -1;
    //遍历然后如果找到了就break掉然后return当前index
    for (int i = 0; i < list->size; ++i) {
        ptrCurrent = ptrCurrent->next;
        if (ptrCurrent->data == data){
            pos = i;
            break;
        }
    }
    return pos;
}
//返回第一个节点，也即head的next
void* getFirstNode(sLinkedList* list){
    return list->head->next->data;
}

//获得链表长度
int getSLinkedListSize(sLinkedList* list){
    return list->size;
}
//此处因为不知道data的数据类型，所以需要用户自己定义函数
//定义打印的回调函数指针 更简洁优美
typedef void(*PRINTSLINKNODE)(void*);
//打印全部节点
void printSLinkedList(sLinkedList* list, PRINTSLINKNODE printNode){
    if (list == nullptr)
        return;
    sLinkedListNode* ptrCurrent = list->head;
    for (int i = 0; i < list->size; ++i) {
        ptrCurrent = ptrCurrent->next;
        printf("Pos:%d\t",i);
        printNode(ptrCurrent->data);
    }
    printf("\n");

}
//释放链表内存
void freeMemorySLinkedList(sLinkedList* list){
    if (list == nullptr)
        return;
    //先释放节点
    sLinkedListNode* ptrCurrent = list->head;
    while (ptrCurrent != nullptr){
        //先缓存下一个节点
        sLinkedListNode* ptrNext = ptrCurrent->next;
        //再free掉内存
        free(ptrCurrent);
        //再把ptrCurrent指向下一个节点
        ptrCurrent = ptrNext;
    }
    //再释放链表
    list->size = 0;
    free(list);
}


/* 企业单向链表
 * C Implementation
 * V0.1
 *
 * API:
 *      初始化、
 *      insert，delete，
 *      根据值查找位置，getSize，返回第一个节点
 *      打印节点，返回头节点，释放内存
 */

//子节点用于连接
typedef struct ENTERPRISELINKEDLISTSUBNODE{
    struct ENTERPRISELINKEDLISTNODE* next;
}eLinkedListSubNode;
//主节点存放链表数据
typedef struct ENTERPRISELINKEDLIST{
    struct ENTERPRISELINKEDLISTSUBNODE* head;
    int size;
}eLinkedList;
//初始化
eLinkedList* initELinkedList();
//插入主节点
void insertELinkedList(eLinkedList* list, int pos, eLinkedListSubNode* subNode);
//删除
void deleteELinkedList(eLinkedList* list, int pos);
//查找节点
int findENodeLocation(eLinkedList* list, eLinkedListSubNode* subNode);
//链表大小
int getSizeELinkedList(eLinkedList* list);
//打印函数指针//为什么传入子节点指针？？
typedef void(*PRINTELINKNODE)(eLinkedListSubNode *);
//打印整个链表
void printELinkedList(eLinkedList* list,PRINTELINKNODE print);
//释放全部链表内存
void freeMemoryELinkedList(eLinkedList* list);











#endif //CLIONC__TEST_LINKEDLISTC_HPP
