// Copyright 2020 Adam Tremblay

#include <math.h>
#include <random>
#include <string>
#include "StringSound.hpp"

const float ENERGY_DECAY = 0.994;

StringSound::StringSound(double frequency) {
    if (frequency < 1) {
        std::string str = "constructor: frequency must be greater than zero.";
        throw std::invalid_argument(str);
    }

    pRing_buffer_ = new RingBuffer(ceil(frequency));
    time_ = 0;
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    pRing_buffer_ = new RingBuffer(init.capacity());

    for (int i = 0; i < init.size(); i++) {
        pRing_buffer_->enqueue(init.at(i));
    }
    time_ = 0;
}

StringSound::~StringSound() {
    delete pRing_buffer_;
}

void StringSound::pluck() {
    // create a random number generator over the int16_t range
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-32768, 32767);

    // if anything in rb then empty it
    pRing_buffer_->empty();

    // fill rb with random nums over the range
    while (!pRing_buffer_->isFull()) {
        pRing_buffer_->enqueue(dis(gen));
    }
}

void StringSound::tic() {
    int16_t f_front = pRing_buffer_->dequeue();
    int16_t k_c_update = ENERGY_DECAY * 0.5 * (f_front + pRing_buffer_->peek());
    pRing_buffer_->enqueue(k_c_update);
    ++time_;
}

sf::Int16 StringSound::sample() {
    return pRing_buffer_->peek();
}

int StringSound::time() {
    return time_;
}
