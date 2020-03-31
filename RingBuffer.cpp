// Copyright 2020 Adam Tremblay

#include <iostream>
#include <string>
#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
    if (capacity < 1) {
        std::string str = "constructor: capacity must be greater than zero.";
        throw std::invalid_argument(str);
    }

    capacity_ = capacity;
}

void RingBuffer::enqueue(int16_t x) {
    if (this->isFull()) {
        throw std::runtime_error("enqueue: can't enqueue to a full ring.");
    }

    ring_buffer_.push(x);
}

int16_t RingBuffer::dequeue() {
    if (this->isEmpty()) {
        throw std::runtime_error("dequeue: can't dequeue to an empty ring.");
    }

    int16_t front = ring_buffer_.front();
    ring_buffer_.pop();

    return front;
}

int16_t RingBuffer::peek() {
    if (this->isEmpty()) {
        throw std::runtime_error("peek: can't peek to an empty ring.");
    }

    return ring_buffer_.front();
}
