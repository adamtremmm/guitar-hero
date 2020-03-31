// Copyright 2020 Adam Tremblay

#include <iostream>
#include <string>
#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
    if (capacity < 1) {
        std::string str = "constructor: capacity must be greater than zero.";
        throw std::invalid_argument(str);
    }

    for (int i = 0; i < capacity; i++) {
        ring_buffer_.push_back(0);
    }
    
    capacity_ = capacity;
    size_ = 0;
    first_ = 0;
    last_ = 0;
}

void RingBuffer::enqueue(int16_t x) {
    if (this->isFull()) {
        throw std::runtime_error("enqueue: can't enqueue to a full ring.");
    }

    ring_buffer_.at(last_) = x;
    last_ = (last_ + 1) % capacity_;
    ++size_;
}

int16_t RingBuffer::dequeue() {
    if (this->isEmpty()) {
        throw std::runtime_error("dequeue: can't dequeue to an empty ring.");
    }

    int16_t front = ring_buffer_.at(first_);
    first_ = (first_ + 1) % capacity_;
    --size_;

    return front;
}

int16_t RingBuffer::peek() {
    if (this->isEmpty()) {
        throw std::runtime_error("peek: can't peek to an empty ring.");
    }

    return ring_buffer_.at(first_);
}

void RingBuffer::empty() {
    size_ = 0;
    first_ = 0;
    last_ = 0;
}
