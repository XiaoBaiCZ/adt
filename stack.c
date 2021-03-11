//
// Created by zml on 2021/3/11.
//

#include "stack.h"

adt_stack *adt_stack_new() {
    return adt_array_list_new();
}

void adt_stack_release(adt_stack *obj, adt_list_iterator iterator) {
    adt_array_list_release(obj, iterator);
}

void *adt_stack_push(adt_stack *obj, void *val) {
    return adt_array_list_append(obj, val);
}

void *adt_stack_pop(adt_stack *obj) {
    return adt_array_list_del(obj, obj->size - 1);
}

void *adt_stack_peek(adt_stack *obj) {
    return adt_array_list_get(obj, obj->size - 1);
}

char adt_stack_isempty(adt_stack *obj) {
    return adt_array_list_isempty(obj);
}

