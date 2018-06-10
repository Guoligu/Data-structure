#include <stdio.h>
#include <stdlib.h>
#include "CommDef.h"
#include "SqList.h"

Status InitList(SqList * pl)
{
    pl->e = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!pl->e)
        exit(OVERFLOW);
    pl->length = 0;
    pl->listSize = LIST_INIT_SIZE;
    return OK;
}

Status ListIns(SqList * pl, int i, ElemType e)
//在表中第i个元素之前插入一个新的元素
{
    if (i < 1 || i > pl->length + 1)
        return ERROR;
    if (pl->length >= pl->listSize)
    {
        pl->e = realloc(pl->e, 
            (pl->listSize + LIST_INC) * sizeof(ElemType));
        if (!pl->e)
            exit(OVERFLOW);
        pl->listSize += LIST_INC;
    }
    for (int j = pl->length; j > i-1; j--)
    //在数组中i-1才是第i个元素的位置
    {
        pl->e[j] = pl->e[j-1];
    }
    pl->e[i-1] = e;
    pl->length++;
    return OK;
}

Status ListDel(SqList * pl, int i, ElemType * e)
{
    *e = pl->e[i-1];
    for (int j = i-1; j < pl->length; j++)
        pl->e[j] = pl->e[j+1];
    pl->length--;
    return OK;
}

void DispList(SqList * pl)
{
    for (int i = 0; i < pl->length; i++)
        printf("%d: %d\n", i + 1, pl->e[i]);
}

Status ClrList(SqList * pl)
{
    pl->length = 0;
    return OK;
}

Status DestroyList(SqList * pl)
{
    pl->length = pl->listSize = 0;
    free(pl->e);
    return OK;
}

int GetLen(SqList * pl)
{
    return pl->length;
}