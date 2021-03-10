//
// Created by xiaoj on 2021/03/10.
//

#ifndef ADT_LIST_H
#define ADT_LIST_H

//抽象类型默认大小
#define ADT_DEF_SIZE 8

//动态数组
typedef struct {
    //数组
    void ** src;
    //数组边界
    unsigned int limit;
    //元素个数
    unsigned int size;
} array_list;

//列表迭代器
typedef void (*adt_list_iterator)(int, void *);

//新建动态数组
array_list *adt_array_list_new();
//释放动态数组
void adt_array_list_release(array_list *array, adt_list_iterator iterator);
//迭代元素
void adt_array_list_iteration(array_list *array, adt_list_iterator iterator);
//添加元素
void *adt_array_list_append(array_list *array, void *val);
//插入元素
void *adt_array_list_insert(array_list *array, unsigned int index, void *val);
//修改元素
void *adt_array_list_set(array_list *array, unsigned int index, void *val);
//删除元素
void *adt_array_list_del(array_list *array, unsigned int index);
//获取元素
void *adt_array_list_get(array_list *array, unsigned int index);

#endif //ADT_LIST_H
