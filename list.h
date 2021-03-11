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



//链表节点
typedef struct linked_list_node {
    //元素
    void *val;
    //上一个节点
    struct linked_list_node *pre;
    //下一个节点
    struct linked_list_node *next;
} linked_list_node;

//链表
typedef struct {
    //链头
    linked_list_node *head;
    //链尾
    linked_list_node *tail;
    //长度
    unsigned int size;
} linked_list;


//新建链表
linked_list *adt_linked_list_new();
//释放链表
void adt_linked_list_release(linked_list *linked, adt_list_iterator iterator);
//迭代元素
void adt_linked_list_iteration(linked_list *linked, adt_list_iterator iterator);
//添加元素
void *adt_linked_list_append(linked_list *linked, void *val);
//插入元素
void *adt_linked_list_insert(linked_list *linked, unsigned int index, void *val);
//修改元素
void *adt_linked_list_set(linked_list *linked, unsigned int index, void *val);
//删除元素
void *adt_linked_list_del(linked_list *linked, unsigned int index);
//获取元素
void *adt_linked_list_get(linked_list *linked, unsigned int index);

#endif //ADT_LIST_H
