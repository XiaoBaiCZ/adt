//
// Created by xiaoj on 2021/03/10.
//

#include "list.h"
#include <stdlib.h>

//数组扩容，翻一倍容量
void adt_array_list_expansion(array_list *array) {
    array->limit <<= 1;
    array->src = realloc(array->src, array->limit * sizeof(void *));
}

//元素偏移
void adt_array_list_offset(array_list *array, unsigned int index, int offset) {
    if (offset == 0) {
        return;
    }
    const unsigned int count = array->size - index;
    if (offset > 0) {
        for (int i = 0; i < count; ++i) {
            array->src[array->size - 1 - i + offset] = array->src[array->size - i - 1];
        }
        return;
    }
    for (int i = 0; i < count; ++i) {
        array->src[index + i + offset] = array->src[index + i];
    }
}

//检测边界
char adt_array_list_check_border(array_list *array, unsigned int index) {
    return index >= array->size;
}

array_list *adt_array_list_new() {
    array_list *array = calloc(1, sizeof(array_list));
    array->size = 0;
    array->limit = ADT_DEF_SIZE;
    array->src = calloc(ADT_DEF_SIZE, sizeof(void *));
    return array;
}

void adt_array_list_release(array_list *array, adt_list_iterator iterator) {
    if (iterator != NULL) {
        for (int i = 0; i < array->size; ++i) {
            iterator(i, array->src[i]);
        }
    }
    array->limit = 0;
    array->size = 0;
    free(array->src);
    free(array);
}

void adt_array_list_iteration(array_list *array, adt_list_iterator iterator) {
    if (iterator != NULL) {
        for (int i = 0; i < array->size; ++i) {
            iterator(i, array->src[i]);
        }
    }
}

void *adt_array_list_append(array_list *array, void *val) {
    if (array->size + 1 >= array->limit) {
        adt_array_list_expansion(array);
    }
    array->src[array->size++] = val;
    return val;
}

void *adt_array_list_insert(array_list *array, unsigned int index, void *val) {
    if (index > array->size) {
        return NULL;
    }
    if (array->size + 1 >= array->limit) {
        adt_array_list_expansion(array);
    }
    adt_array_list_offset(array, index, 1);
    array->src[index] = val;
    array->size++;
    return val;
}

void *adt_array_list_set(array_list *array, unsigned int index, void *val) {
    if (adt_array_list_check_border(array, index)) {
        return NULL;
    }
    void *old = array->src[index];
    array->src[index] = val;
    return old;
}

void *adt_array_list_del(array_list *array, unsigned int index) {
    if (adt_array_list_check_border(array, index)) {
        return NULL;
    }
    void *old = array->src[index];
    adt_array_list_offset(array, index + 1, -1);
    array->size--;
    return old;
}

void *adt_array_list_get(array_list *array, unsigned int index) {
    if (adt_array_list_check_border(array, index)) {
        return NULL;
    }
    return array->src[index];
}

