#include<iostream>
#include<vector>
#include<chrono>



//ASSIGMENT 9
/*
Task1. -
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;        // Copy
    std::vector<int> v3 = std::move(v1); // Move

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v3 size: " << v3.size() << std::endl;

    return 0;
}
Questions:
What is the output of this program?
v1 size: 0
v2 size: 4
v3 size: 4
Why does v1.size() return 0 after the move?
Because the data stored in v1 is in v3, and v1 is a nulptr
What does std::move do?
It casts v1 to an r-reference value, so the info stored in it, can be moved.
Why is v1 still in a valid but unspecified state? 
Because the implementation points v1 to nultpr.
*/

/*
Task 2.1 Define a Simple Resource-Managing Class
Implement a class Buffer that manages a dynamically allocated array of integers
*/
class Buffer{
    private:
        int* value;
        size_t size;
    public:
        //constructor
        Buffer(size_t size): 
            size(size),
            value(new int[size]){
                //std::cout << "Constructor called\n";
            };
        //destructor
        ~Buffer(){           
            delete[]value;
            //std::cout << "Destructor called\n";
        };
        //copy constructor
        Buffer(const Buffer& other):
            size(other.size),
            value(new int[other.size]){
            std::copy(other.value, other.value + other.size, value);
            //std::cout << "copy constructor called\n";
        };
        //Copy assigment operator
        Buffer operator=(const Buffer& other){
            if(this!=&other){
                delete[] value;
                size=other.size;
                value=new int[size];
                std::copy(other.value, other.value + size, value);
              //  std::cout << "copy assignment called\n";
            };
            
            return *this;
        };
        //move constructor
        Buffer(Buffer&& other) noexcept:
        size(other.size),
        value(other.value){
            other.value=nullptr;
            other.size=0;
            //std::cout << "Move constructor called\n";
        };
        //move assigment operator
        Buffer operator=(Buffer&& other){
            if(this!=&other){
                delete[] value;
                size=other.size;
                value=other.value;
                other.value=nullptr;
                other.size=0;
              //  std::cout << "Move assignment called\n";

            };
            return *this;
        };

};

int main() {
    Buffer b1(100); //Constructor
    Buffer b2 = b1;           // Copy constructor
    Buffer b3 = std::move(b1); //move constructor

    Buffer b4(50);//constructor
    b4 = b2;                  // Copy assignment operator
    b4 = std::move(b2);//move assignment operator
    const size_t bufferSize = 10000; 
    auto startCopy = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i){
        Buffer buffer1(bufferSize);
        Buffer buffer2 = buffer1;
    }
    auto endCopy = std::chrono::high_resolution_clock::now();
    std::cout << "Copy Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(endCopy - startCopy).count() << " ms\n";
 
    auto startMove = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < 1000; ++j){
        Buffer buffer3(bufferSize);
        Buffer bufer4 = std::move(buffer3);
    }
    auto endMove = std::chrono::high_resolution_clock::now();
    std::cout << "Move Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(endMove - startMove).count() << " ms\n";

    return 0;
};

/*
What constructors and assignments are called and when?
The Constructor is called in line 101 and 105, 
the copy contructor in line 102,
the move constructor in line 103,
The copya assignment operator in line 106, 
• What happens to the source object after a move? 
The object is pointed to Nullptr and the size is zero.
• What would happen if you didn’t define the move constructor/assignment?
The move operator would not point to nullptr and de destrcutor will erase the data saved in the new object and the old one.
*/

/*
Questions

• What did you learn about move semantics?
How to use them in a class, and how to implement them.
• In what kinds of projects do you think this would matter?
with data that is heavy to copy, like images, videos, etc.
• What are some risks of using std::move incorrectly?
you can lose the data stored in the object, and you can have memory leaks if you do not implement the destructor correctly.
*/