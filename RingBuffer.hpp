// Copyright 2020 Adam Tremblay

#ifndef _USERS_ADAMTREMBLAY_DEVELOPMENT_COMPUTING_4_PS4A_RINGBUFFER_HPP_
#define _USERS_ADAMTREMBLAY_DEVELOPMENT_COMPUTING_4_PS4A_RINGBUFFER_HPP_

#include <stdint.h>
#include <queue>

class RingBuffer {
 public:
    explicit RingBuffer(int capacity);

    // return number of items currently in the buffer
    int size() { return ring_buffer_.size(); }

    // is the buffer empty (size equals zero)?
    bool isEmpty() { return ring_buffer_.size() <= 0; }

    // is the buffer full (size equals capacity)?
    bool isFull() { return ring_buffer_.size() >= capacity_; }

    // add item x to the end
    void enqueue(int16_t x);

    // delete and return item from the front
    int16_t dequeue();

    // return (but do not delete) item from the front
    int16_t peek();

 private:
    std::queue<int16_t> ring_buffer_;
    int capacity_;
};

#endif  // _USERS_ADAMTREMBLAY_DEVELOPMENT_COMPUTING_4_PS4A_RINGBUFFER_HPP_
