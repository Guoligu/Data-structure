#ifndef SQLIST_H
#define SQLIST_H

#include "CommDef.h"

#define LIST_INC 10 //线性表每次增长的大小
#define LIST_INIT_SIZE 100 //线性表的初始大小

typedef struct list {
//顺序表的动态分配存储结构
    ElemType * e;
    int length;
    int listSize;
} SqList;

Status InitList(SqList * pl);
Status ListIns(SqList * pl, int i, ElemType e);
Status ListDel(SqList * pl, int i, ElemType *e);
void DispList(SqList * pl);     //显示表中所有元素
Status ClrList(SqList * pl);    //清空表中所有元素
Status DestroyList(SqList * pl);   //free释放线性表的地址
int GetLen(SqList * pl);

#endif