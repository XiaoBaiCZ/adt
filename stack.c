//
// Created by zml on 2021/3/11.
//

#include "stack.h"

stack *adt_stack_new() {
    return adt_array_list_new();
}

void adt_stack_release(stack *obj, adt_list_iterator iterator) {
    adt_array_list_release(obj, iterator);
}

void *adt_stack_push(stack *obj, void *val) {
    return adt_array_list_append(obj, val);
}

void *adt_stack_pop(stack *obj) {
    return adt_array_list_del(obj, obj->size - 1);
}

void *adt_stack_peek(stack *obj) {
    return adt_array_list_get(obj, obj->size - 1);
}

