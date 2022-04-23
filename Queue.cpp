//
// Created by Денис on 20.04.2022.
//
#include <Queue.h>
#include <cstddef>

namespace QueueNS {

    template<typename TYPE>
    Queue<TYPE> *newQueue() {
        auto *queue = new Queue<TYPE>;
        queue->tail = nullptr;
        queue->head = nullptr;
        return queue;
    }

    template<typename TYPE>
    int enqueue(Queue<TYPE> *queue, TYPE value) {
        if (queue == nullptr) {
            return 0;
        }
        auto *newNode = new QueueNode<TYPE>;
        newNode->key = value;
        newNode->next = nullptr;
        if (queue->tail != nullptr) {
            queue->tail->next = newNode;
        }
        queue->tail = newNode;
        if (queue->head == nullptr) {
            queue->head = queue->tail;
        }
        return 1;
    }

    template<typename TYPE>
    QueueNode<TYPE> *dequeue(Queue<TYPE> *queue) {
        if (queue== nullptr||queue->head== nullptr)
            return nullptr;
        auto *node = queue->head;
        queue->head=queue->head->next;
        return node;
    }

    template<typename TYPE>
    void deleteQueue(Queue<TYPE> *queue) {
        while (queue->head!= nullptr)
        {
            delete dequeue(queue);
        }
        delete queue;
    }
}
