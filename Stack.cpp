//
// Created by Денис on 20.04.2022.
//
#include "Stack.h"

namespace StackNS {
    template<typename TYPE>
    Stack<TYPE> *newStack() {
        auto *stack = new Stack<TYPE>;
        stack->head = nullptr;
        return stack;
    }

    template<typename TYPE>
    int push(Stack<TYPE> *stack, TYPE value) {
        if (stack == nullptr) {
            return 0;
        }
        auto *newNode = new StackNode<TYPE>;
        newNode->key = value;
        newNode->next = stack->head;
        stack->head = newNode;
        return 1;
    }

    template<typename TYPE>
    StackNode<TYPE> *pop(Stack<TYPE> *stack) {
        if (stack == nullptr || stack->head == nullptr) {
            return nullptr;
        }
        auto *node = stack->head;
        stack->head = stack->head->next;
        return node;
    }

    template<typename TYPE>
    void deleteStack(Stack<TYPE> *stack) {
        auto *tmp = stack->head;
        if (stack->head == nullptr) {
            return;
        }
        do {
            tmp = stack->head->next;
            delete stack->head;
            stack->head = tmp;
        } while (stack->head != nullptr);

        delete stack;
    }
}
