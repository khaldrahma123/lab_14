#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include "vector.h"

static void badAllocV() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(size_t n) {
    int *v = (int *) malloc(sizeof(int) * n);
    if (v == NULL) {
        badAllocV();
    }
    return (vector) {v, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data); // Освобождаем память, если новая емкость равна 0
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
        return;
    }
    else if (newCapacity < v->size) {
        v->size = newCapacity; // Уменьшаем размер, если новая емкость меньше текущего размера
    }
    int *newData = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (newData == NULL) {
        badAllocV();
    }
    v->data = newData;
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    reserve(v, 0);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void append_(int *data, int *size, int x) {
    data[*size] = x; // Добавляем новый элемент в конец массива данных
    (*size)++;       // Увеличиваем размер массива
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    append_(v->data, &v->size, x);
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        badAllocV();
    }
    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    return &v->data[index];
}

int* back(vector *v) {
    return atVector(v, v->size - 1);
}

int* front(vector *v) {
    return atVector(v, 0);
}

void vector_print(vector v) {
    printf("{");
    for (int i = 0; i < v.size; i++)
        printf("%d, ", v.data[i]);
    if (v.size == 0)
        printf("}");
    else
        printf("\b\b}\n");
}
