/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *	RingBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Adam Tremblay


Hours to complete assignment: 3 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

This assignment was to create a RingBuffer class that has all the necessary
prerequisites to complete the next part of the assignment. When it is 
complete, we will have a program that simulates a guitar string being plucked.

/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

For the ring buffer I used a queue from the STL library. This seemed like 
the best choice for a data structure. The directions said we were to be
deleting from the front and adding items to the end, which is what a
queue is.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

RingBuffer:
The constructor takes in an integer, the capacity, and checks if its
greater than zero, if not it throws an invalid_argument error. It then
sets the member capacity to the argument passed. The enqueue function
takes a int16_t and checks if the ring buffer is full and throws a
runtime_error if so. It then pushes the argument into the ring buffer.
The dequeue function checks if the ring buffer is empty and throws a
runtime_error if so. It then gets the item from the front then does a 
pop then returns that item from the front. The peek function checks if 
the ring buffer is empty and throws a runtime_error if so. It then checks
the front of the ring buffer and returns that item.

test:
I use the boost test library to test this. I used BOOST_REQUIRE_THROW to
check if correct exceptions were thrown and BOOST_REQUIRE_NO_THROW for 
the opposite. I also use BOOST_REQUIRE for peek and dequeue functions
after enqueueing to make sure I get the correct data returned.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

Yes, I completed the whole assignment. I think every part of the 
assignment is working correctly. I can tell because I made the unit tests
push all the boundaries of my RingBuffer class.

/**********************************************************************
 *  Does your RingBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

Yes, my RingBuffer class implementation passes the unit tests. I know this
because when I run the test executable, I get back that there were no
errors detected. 

/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/

Space:
My RingBuffer implementation is O(n) in terms of space complexity.
The capacity_ data member is always fixed to O(1), but ring_buffer_
is a queue which is defined by the user. This would make it O(n) for
space. Therefore O(n + 1) = O(n)

Time:
My RingBuffer implementation is O(1) in terms of time complexity.
Push, pop, and front are all O(1) according to the STL queue
documentation. My constructor only sets a variable so it is also O(1).

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

No extra help.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

No serious problems.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

 To Compile:
 make all

 To Run Test:
 ./test

 To Clean:
 make clean

 To use cpplint:
 cpplint RingBuffer.hpp
 cpplint RingBuffer.cpp
 cpplint test.cpp