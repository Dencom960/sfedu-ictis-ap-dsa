//
// Created by Денис on 20.04.2022.
//
#include <List.h>


namespace ListNS {
    template<typename TYPE>
    DoublyList<TYPE> *newList() {
        auto *list = new DoublyList<TYPE>;
        list->head = nullptr;
        list->tail = nullptr;
        return list;
    }

    template<typename TYPE>
    int addAsAFirst(DoublyList<TYPE> *list, TYPE value) {
        if (list == nullptr) {
            return 0;
        }
        auto *node = new DoublyListNode<TYPE>;
        node->key = value;
        node->next = nullptr;
        node->previous = nullptr;
        if (list->head != nullptr) {
            list->head->previous = node;
        }
        node->next = list->head;
        list->head = node;
        if (list->tail == nullptr) {
            list->tail = list->head;
        }
        return 1;
    }

    template<typename TYPE>
    int addAsALast(DoublyList<TYPE> *list, TYPE value) {
        if (list == nullptr) {
            return 0;
        }
        auto *node = new DoublyListNode<TYPE>;
        node->key = value;
        node->next = nullptr;
        node->previous = nullptr;
        if (list->tail != nullptr) {
            list->tail->next = node;
        }
        node->previous = list->tail;
        list->tail = node;
        if (list->head == nullptr) {
            list->head = list->tail;
        }
        return 1;
    }

    template<typename TYPE>
    DoublyListNode<TYPE> *find(DoublyList<TYPE> *list, TYPE value) {
        auto *left = list->head;
        auto *right = list->tail;

        while (left != nullptr && right != nullptr) {
            if (left->key == value) {
                return left;
            }
            if (right->key == value) {
                return right;
            }

            left = left->next;
            right = right->previous;
        }
        return nullptr;
    }

    template<typename TYPE>
    int insertAfterNode(DoublyList<TYPE> *list, DoublyListNode<TYPE> *node, TYPE value) {
        if (list == nullptr || node == nullptr) {
            return 0;
        }
        auto *newNode = new DoublyListNode<TYPE>;
        newNode->key = value;
        newNode->next = nullptr;
        newNode->previous = nullptr;
        newNode->next = node->next;
        newNode->previous = node;
        node->next = newNode;
        return 1;
    }


    template<typename TYPE>
    void deleteList(DoublyList<TYPE> *list) {
        while(list->head!= nullptr)
        {
            auto *d = list->head->next;
            delete list->head;
            list->head = d;
        }
        delete list;
    }
}
