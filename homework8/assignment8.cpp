#include<iostream>
#include<string>
#include<concepts>


//Task 2.1: Create a Template with a Concept 
template<typename T>
concept Numeric = std::floating_point<T> || std::integral<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
}
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




int main() {
    std::cout << maxValue(8, 135) << std::endl;                                            //should print 135     
    std::cout << maxValue(76.3, 7.3) << std::endl;                                         //should print 76.3
    std::cout << maxValue(std::string("computer"), std::string("gaming")) << std::endl;    //should print gaming

    std::cout << maxValue(8, 135,425) << std::endl; 
    std::cout << maxValue(76.3, 7.3,2.4) << std::endl;

}