#include<iostream>
#include<string>
#include<concepts>
#include<type_traits>
//task1.1 Write a Simple Template Function
template<typename T>
T maxValue(T a,T b){
    return(a>b)?a:b;
};

//Task 1.2: Overload a Template Function

template<typename T>
T maxValue(T a, T b, T c){
    return maxValue(a,maxValue(b,c));
    
};

//Task 2.1: Create a Template with a Concept 
template<typename D>
concept Numeric = std::floating_point<D> || std::integral<D>;


template <Numeric D>
D add(D a, D b) {
    return a + b;

};

//Write a variadic template function called printAll that accepts any number of parameters and prints them separated by spaces.
template<typename C>
void printAll(C c){
    std::cout<< c<< std::endl;
};

template<typename C,typename... Args>
void printAll(C c, Args...args){
    std::cout<<c<<" ";
    printAll(args...);    
};

//Task 4.1: Compile-Time Factorial Using Templates
template<int S>
struct Factorial {
    static constexpr int value = S * Factorial<S - 1>::value;
};
template<>
struct Factorial<0> {
    static constexpr int value = 1;
};
template<int B>
struct Fibonacci{
    static_assert(B >= 0, "Fibonacci is not defined for negative numbers");
    static constexpr int value = Fibonacci<B - 1>::value + Fibonacci<B - 2>::value;
};
template<int B>
struct Fibonacci<B < 0>; 

template<>
struct Fibonacci<0> {
    static constexpr int value = 0;
};

template<>
struct Fibonacci<1> {
    static constexpr int value = 1;
};


int main() {
    std::cout << maxValue(8, 135) << std::endl;                                            //should print 135     
    std::cout << maxValue(76.3, 7.3) << std::endl;                                         //should print 76.3
    std::cout << maxValue(std::string("computer"), std::string("gaming")) << std::endl;    //should print gaming
    std::cout << maxValue(8, 135,425) << std::endl;                                        //should print 425
    std::cout << maxValue(76.3, 7.3,2.4) << std::endl;                                     //should print 76.3
    std::cout << add(12.0,4.4) << std::endl;                                               //should print 16.4
    printAll(1,2,"hola como vas?");                                                        //should print 1,2,"hola como vas?"
    static constexpr int result= Factorial< 5>::value;
    std::cout << result << std::endl;                                                      //should print 120
    static constexpr int res2=Fibonacci<10>::value;
    std::cout<<res2<<std::endl;                                                            //should print 55
    return 0;
};