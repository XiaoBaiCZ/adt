//
// Created by zml on 2021/3/11.
//

#ifndef ADT_STACK_H
#define ADT_STACK_H

#include "list.h"

//栈
typedef adt_array_list adt_stack;

//新建动态数组
adt_stack *adt_stack_new();
//释放动态数组
void adt_stack_release(adt_stack *obj, adt_list_iterator iterator);
//入栈
void *adt_stack_push(adt_stack *obj, void *val);
//出栈
void *adt_stack_pop(adt_stack *obj);
//获取栈顶
void *adt_stack_peek(adt_stack *obj);
//判空 0 是非空
char adt_stack_isempty(adt_stack *obj);

#endif //ADT_STACK_H
