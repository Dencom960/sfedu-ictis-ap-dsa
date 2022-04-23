//
// Created by Денис on 20.04.2022.
//
#include "Array.h"

namespace ArrayNS {
    template<typename TYPE>

    Array<TYPE> *newArray(int size) {
        auto *arr = new Array<TYPE>;
        arr->array=new TYPE[size];
        arr->size=size;
        return arr;
    }

    template<typename TYPE>
    int insertToArray(Array<TYPE> *arr, TYPE value, int index) {
        if (index > arr->size) {
            return 0;
        }

        arr->array[index] = value;

        return 1;
    }


    template<typename TYPE>
    TYPE *find(Array<TYPE> *arr, TYPE value) {
        if (arr== nullptr||arr->array==nullptr) {
            return nullptr;
        }
        for (int i=0;i<arr->size;i++)
        {
            if (arr->array[i]==value) {
                return &(arr->array[i]);
            }
        }
        return nullptr;
    }

    template<typename TYPE>
    void deleteArray(Array<TYPE> *arr) {
        if (arr== nullptr) {
            return;
        }
        delete[] arr->array;
        delete arr;
    }
}