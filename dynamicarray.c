#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 10

typedef struct 
{
    int *arr;
    int n;
    int limit;
} DynamicArray;

DynamicArray* create() 
{
    DynamicArray* d = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (d == NULL) 
    {
        printf("Failed!\n");
        exit(EXIT_FAILURE);
    }
    d->arr = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (d->arr == NULL) 
    {
        printf("Failed!\n");
        free(d);
        exit(EXIT_FAILURE);
    }
    d->n = 0;
    d->limit = INITIAL_CAPACITY;
    return d;
}

void destroy(DynamicArray* d)
{
    free(d->arr); 
    free(d);
}

void push(DynamicArray* d, int value) 
{
    if (d->n >= d->limit) 
    {
        int new_capacity = d->limit * 2;
        int* new_array = (int*)realloc(d->arr, new_capacity * sizeof(int));
        if (new_array == NULL) 
        {
            printf("Failed!\n");
            exit(EXIT_FAILURE);
        }
        d->arr = new_array;
        d->limit = new_capacity;
    }
    d->arr[d->n++] = value;
}

int getElement(DynamicArray* d, int index) 
{
    if (index < 0 || index >= d->n) 
    {
        printf("Out of range!\n");
        exit(EXIT_FAILURE);
    }
    return d->arr[index];
}

int main() 
{
    DynamicArray* arr = create();
    push(arr, 31);
    push(arr, 25);
    push(arr, 45);
    printf("index 0: %d\n", getElement(arr, 0));
    printf("index 1: %d\n", getElement(arr, 1));
    printf("index 2: %d\n", getElement(arr, 2));
    destroy(arr);
    return 0;
}


/*
output:
index 0: 31
index 1: 25
index 2: 45
*/
