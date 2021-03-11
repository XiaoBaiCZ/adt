#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>

void iterator(int i, void *val);
void array_list_demo();

void linked_list_demo();

int main() {

//    array_list_demo();

    linked_list_demo();

    return 0;
}

void linked_list_demo() {
    linked_list *linked = adt_linked_list_new();

    int x = 10;
    for (int i = 0; i < 10; ++i) {
        adt_linked_list_append(linked, &x);
    }

    int y = 20;
    const int index = 6;
    adt_linked_list_set(linked, index, &y);

    int *target = adt_linked_list_get(linked, index);
    printf("-- %d: %d \n", index, *target);

    adt_linked_list_del(linked, index);

    adt_linked_list_insert(linked, index, &y);

    adt_linked_list_iteration(linked, iterator);

    adt_linked_list_release(linked, NULL);
}

void array_list_demo() {
    array_list *array = adt_array_list_new();

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
