// Copyright 2020 Adam Tremblay

#include <iostream>
#include "RingBuffer.hpp"
#include "StringSound.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(constructor) {
    BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
    BOOST_REQUIRE_NO_THROW(RingBuffer(1));
}

BOOST_AUTO_TEST_CASE(functions) {
    RingBuffer rb(1);
    BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
    BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
    BOOST_REQUIRE_NO_THROW(rb.enqueue(2));
    BOOST_REQUIRE_THROW(rb.enqueue(2), std::runtime_error);
    BOOST_REQUIRE_NO_THROW(rb.peek());
    BOOST_REQUIRE_NO_THROW(rb.dequeue());
}

BOOST_AUTO_TEST_CASE(check_values) {
    RingBuffer rb(1);
    BOOST_REQUIRE_NO_THROW(rb.enqueue(2));
    BOOST_REQUIRE(rb.peek() == 2);
    BOOST_REQUIRE(rb.dequeue() == 2);
}

BOOST_AUTO_TEST_CASE(check_other_fxns) {
    RingBuffer rb(2);
    BOOST_REQUIRE_NO_THROW(rb.enqueue(2));
    BOOST_REQUIRE(rb.size() == 1);
    BOOST_REQUIRE(rb.isEmpty() == false);
    BOOST_REQUIRE(rb.dequeue() == 2);
    BOOST_REQUIRE(rb.size() == 0);
    BOOST_REQUIRE(rb.isEmpty() == true);
    BOOST_REQUIRE(rb.isFull() == false);
    BOOST_REQUIRE_NO_THROW(rb.enqueue(55));
    BOOST_REQUIRE_NO_THROW(rb.enqueue(3));
    BOOST_REQUIRE(rb.isFull() == true);
    rb.empty();
    BOOST_REQUIRE(rb.size() == 0);
}

BOOST_AUTO_TEST_CASE(check_StringSound) {
    BOOST_REQUIRE_NO_THROW(StringSound(9.8));
    BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
    StringSound ss(9.8);
    ss.pluck();
    ss.tic();
    std::cout << "Sample = " << ss.sample() << std::endl;
    BOOST_REQUIRE(ss.time() == 1);
}
