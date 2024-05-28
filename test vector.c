#include "libs/data_structures/vector/vector.h"


void test_reserve_theSizeIsLargerThanTheCapacity() {
    vector v = createVector(5);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);выфцьбдютьбо
    reserve(&v, 3);
    assert(v.size == 3);
    assert(v.capacity == 3);
    deleteVector(&v);
}
void test_reserve_emptyVector() {
    vector v = createVector(5);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    reserve(&v, 0);
    assert(v.data == NULL);
    deleteVector(&v);
}
void test_reserve_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    reserve(&v, 10);
    assert(v.size == 5);
    assert(v.capacity == 10);
    deleteVector(&v);
}
void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}
void test_pushBack_fullVector1() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.size == 2);
    assert(v.capacity == 2);
    deleteVector(&v);
}
void test_pushBack_fullVector2() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    assert(v.size == 3);
    assert(v.capacity == 4);
    deleteVector(&v);
}
void test_pushBack_fullVector3() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    assert(v.size == 5);
    assert(v.capacity == 8);
    deleteVector(&v);
}

void test_popBack_notEmptyVector1() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_popBack_notEmptyVector2() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 24);
    pushBack(&v, 58);
    assert(v.size == 3);
    popBack(&v);
    assert(v.size == 2);
    assert(v.capacity == 3);
    deleteVector(&v);
}
void test_popBack_notEmptyVector3() {
    vector v = createVector(3);
    pushBack(&v, 10);
    pushBack(&v, 24);
    pushBack(&v, 58);
    assert(v.size == 3);
    popBack(&v);
    popBack(&v);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 3);
    deleteVector(&v);
}

void test_shrinkToFit_notEmptyVector() {
    vector v = createVector(100);
    pushBack(&v, 10);
    pushBack(&v, 24);
    pushBack(&v, 58);
    shrinkToFit(&v);
    assert(v.size == 3);
    assert(v.capacity == 3);
    deleteVector(&v);
}
void test_clear_notEmptyVector() {
    vector v = createVector(10);
    pushBack(&v, 10);
    pushBack(&v, 24);
    pushBack(&v, 58);
    clear(&v);
    assert(v.size == 0);
    assert(v.capacity == 10);
    deleteVector(&v);
}
void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 4);
    pushBack(&v, 7);
    pushBack(&v, 0);
    pushBack(&v, 100);
    atVector(&v, 0);
    atVector(&v, 1);
    assert(v.size == 4);
    assert(v.capacity == 5);
    deleteVector(&v);
}
void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    pushBack(&v, 4);
    pushBack(&v, 7);
    pushBack(&v, 0);
    pushBack(&v, 100);
    atVector(&v, 3);
    assert(v.size == 4);
    assert(v.capacity == 5);
    deleteVector(&v);
}
void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    back(&v);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}
void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    front(&v);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test() {
    test_reserve_theSizeIsLargerThanTheCapacity();
    test_reserve_emptyVector();
    test_reserve_notEmptyVector();
    test_pushBack_emptyVector();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
    test_pushBack_fullVector3();
    test_popBack_notEmptyVector1();
    test_popBack_notEmptyVector2();
    test_popBack_notEmptyVector3();
    test_shrinkToFit_notEmptyVector();
    test_clear_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
    return 0;
}