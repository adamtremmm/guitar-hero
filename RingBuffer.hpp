// Copyright 2020 Adam Tremblay

#ifndef RINGBUFFER_HPP_
#define RINGBUFFER_HPP_

#include <stdint.h>
#include <queue>

class RingBuffer {
 public:
    explicit RingBuffer(int capacity);

    // return number of items currently in the buffer
    int size() { return size_; }

    // is the buffer empty (size equals zero)?
    bool isEmpty() { return size_ <= 0; }

    // is the buffer full (size equals capacity)?
    bool isFull() { return size_ >= capacity_; }

    // add item x to the end
    void enqueue(int16_t x);

    // delete and return item from the front
    int16_t dequeue();

    // return (but do not delete) item from the front
    int16_t peek();

    // empty the ring buffer
    void empty();

 private:
    std::queue<int16_t> ring_buffer_;
    int capacity_;
    int size_;
};

#endif  // RINGBUFFER_HPP_
