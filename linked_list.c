//
// Created by xiaoj on 2021/03/10.
//

#include "list.h"
#include <stdlib.h>

//检测边界
char adt_linked_list_check_border(adt_linked_list *linked, unsigned int index) {
    return index >= linked->size;
}

adt_linked_list *adt_linked_list_new() {
    adt_linked_list *linked = calloc(1, sizeof(adt_linked_list));
    linked->size = 0;
    linked->head = NULL;
    linked->tail = NULL;
    return linked;
}

void adt_linked_list_release(adt_linked_list *linked, adt_list_iterator iterator) {
    adt_linked_list_node *node = linked->head;
    int index = 0;
    while (node != NULL) {
        if (iterator != NULL) {
            iterator(index, node->val);
        }
        adt_linked_list_node *temp = node->next;
        node->val = NULL;
        node->pre = NULL;
        node->next = NULL;
        free(node);
        node = temp;
        index++;
    }
}

void adt_linked_list_iteration(adt_linked_list *linked, adt_list_iterator iterator) {
    if (iterator == NULL) {
        return;
    }

    adt_linked_list_node *node = linked->head;
    int index = 0;
    while (node != NULL) {
        iterator(index, node->val);
        node = node->next;
        index++;
    }
}

void *adt_linked_list_append(adt_linked_list *linked, void *val) {
    adt_linked_list_node *node = calloc(1, sizeof(adt_linked_list_node));
    node->val = val;
    node->pre = NULL;
    node->next = NULL;
    linked->size++;
    if (linked->tail == NULL) {
        linked->head = node;
        linked->tail = node;
        return val;
    }
    node->pre = linked->tail;
    linked->tail->next = node;
    linked->tail = node;
    return val;
}

void *adt_linked_list_insert(adt_linked_list *linked, unsigned int index, void *val) {
    if (adt_linked_list_check_border(linked, index)) {
        return NULL;
    }

    adt_linked_list_node *new = calloc(1, sizeof(adt_linked_list_node));
    new->val = val;
    new->pre = NULL;
    new->next = NULL;

    adt_linked_list_node *node;
    //折半查找
    if (index < linked->size / 2) {
        node = linked->head;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
    } else {
        node = linked->tail;
        for (int i = linked->size - 1; i > index; --i) {
            node = node->pre;
        }
    }

    adt_linked_list_node *pre = node->pre;
    pre->next = new;
    new->pre = pre;
    new->next = node;
    node->pre = new;

    linked->size++;
    return val;
}

void *adt_linked_list_set(adt_linked_list *linked, unsigned int index, void *val) {
    if (adt_linked_list_check_border(linked, index)) {
        return NULL;
    }

    adt_linked_list_node *node;
    //折半查找
    if (index < linked->size / 2) {
        node = linked->head;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
    } else {
        node = linked->tail;
        for (int i = linked->size - 1; i > index; --i) {
            node = node->pre;
        }
    }

    adt_linked_list_node *old = node->val;
    node->val = val;
    return old;
}

void *adt_linked_list_del(adt_linked_list *linked, unsigned int index) {
    if (adt_linked_list_check_border(linked, index)) {
        return NULL;
    }

    adt_linked_list_node *node;
    //折半查找
    if (index < linked->size / 2) {
        node = linked->head;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
    } else {
        node = linked->tail;
        for (int i = linked->size - 1; i > index; --i) {
            node = node->pre;
        }
    }

    //pre -> node -> next

    adt_linked_list_node *pre = node->pre;
    pre->next = node->next;
    node->next->pre = pre;
    void *old = node->val;
    node->val = NULL;
    node->pre = NULL;
    node->next = NULL;
    free(node);

    linked->size--;
    return old;
}

void *adt_linked_list_get(adt_linked_list *linked, unsigned int index) {
    if (adt_linked_list_check_border(linked, index)) {
        return NULL;
    }

    adt_linked_list_node *node;
    //折半查找
    if (index < linked->size / 2) {
        node = linked->head;
        for (int i = 0; i < index; ++i) {
            node = node->next;
        }
    } else {
        node = linked->tail;
        for (int i = linked->size - 1; i > index; --i) {
            node = node->pre;
        }
    }
    return node->val;
}

char adt_linked_list_isempty(adt_linked_list *linked) {
    return linked->size == 0;
}