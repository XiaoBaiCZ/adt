#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>
#include <stack.h>

void iterator(int i, void *val);
void array_list_demo();

void linked_list_demo();

void stack_demo();

int main() {

//    array_list_demo();

    linked_list_demo();

//    stack_demo();

    return 0;
}

void stack_demo() {
    adt_stack *obj = adt_stack_new();
    int a = 10, b = 20, c = 30;
    adt_stack_push(obj, &a);
    adt_stack_push(obj, &b);
    adt_stack_push(obj, &c);

    for (int i = 0; i < 3; ++i) {
        int *res = adt_stack_pop(obj);
        printf("%d \n", *res);
    }

    adt_stack_release(obj, NULL);
}

void linked_list_demo() {
    adt_linked_list *linked = adt_linked_list_new();

    int x = 10;
    adt_linked_list_append(linked, &x);
    adt_linked_list_append(linked, &x);
    adt_linked_list_append(linked, &x);

    adt_linked_list_del(linked, 0);
    adt_linked_list_del(linked, 0);
    adt_linked_list_del(linked, 0);

    adt_linked_list_iteration(linked, iterator);

    adt_linked_list_release(linked, NULL);
}

void array_list_demo() {
    adt_array_list *array = adt_array_list_new();

    int a = 1;
    for (int i = 0; i < 10; ++i) {
        adt_array_list_append(array, &a);
    }
    int b = 2;
    adt_array_list_insert(array, 10, &b);

    int c = 40;
    adt_array_list_set(array, 4, &c);

    adt_array_list_del(array, 4);

    adt_array_list_iteration(array, iterator);

    printf("%d %d \n", array->size, array->limit);

    printf("%d: %d\n", 9, *(int *)adt_array_list_get(array, 9));

    adt_array_list_release(array, NULL);
}

void iterator(int i, void *val) {
    int *v = val;
    printf("%d: %d\n", i, *v);
}
