// Copyright 2020 Adam Tremblay

#ifndef STRINGSOUND_HPP_
#define STRINGSOUND_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include "RingBuffer.hpp"

class StringSound {
 public:
    // create a guitar string sound of the
    // given frequency using a sampling rate
    // of 44,100
    explicit StringSound(double frequency);

    // create a guitar string with
    // size and initial values are given by
    // the vector
    explicit StringSound(std::vector<sf::Int16> init);

    // destructor
    ~StringSound();

    // pluck the guitar string by replacing
    // the buffer with random values,
    // representing white noise
    void pluck();

    // advance the simulation one time step
    void tic();

    // return the current sample
    sf::Int16 sample();

    // return number of times tic was called
    // so far
    int time();

 private:
    RingBuffer* pRing_buffer_;
    int time_;
};

#endif  // STRINGSOUND_HPP_
