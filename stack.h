//
// Created by zml on 2021/3/11.
//

#ifndef ADT_STACK_H
#define ADT_STACK_H

#include "list.h"

//栈
typedef array_list stack;

//新建动态数组
stack *adt_stack_new();
//释放动态数组
void adt_stack_release(stack *obj, adt_list_iterator iterator);
//入栈
void *adt_stack_push(stack *obj, void *val);
//出栈
void *adt_stack_pop(stack *obj);
//获取栈顶
void *adt_stack_peek(stack *obj);

#endif //ADT_STACK_H
