#include<iostream>
#include<string>

std::tuple<double,double,double> punto(){
    double x= 12.4;
    double y= 24.34;
    double z=-13.5;
    return {x,y,z};
};

int main()
{
    //Actv1
    int a=123; //direct initialization
    double b = {12.765};//uniform initialization
    std::string name={"Steve"}; //uniform initialization
    bool c= true; //direct initialization
    std::cout<<"Initial Values;"<<"\n";
    std::cout<<"a:"<<a<<", b:"<<b<<", name:"<<name<<", c="<<c<<std::endl;
    std::cout<<std::endl;

    //Actv 2
    int& A= a;
    A= 25;
    double&B{b};
    B=40.4;
    std::string& Name= name;
    Name={"Alejandro"};
    bool& flag= c;
    flag= false;
    std::cout<<"Modified Values;"<<"\n";
    std::cout<<"a:"<<a<<", b:"<<b<<", name:"<<name<<", c="<<c<<std::endl;
    std::cout<<" "<<std::endl;

    //Actv3
    auto [x,y,z]= punto();
    std::cout<<"Structured binding;"<<"\n";
    std::cout<<"x:"<<x<<", y:"<<y<<", z:"<<z<<std::endl;
    std::cout<<" "<<std::endl;

    //Actv 4
/*   
    a = 42; 
    a: L value
    42: R value

    int x = a + b;
    x: L value
    a: L value
    b: L value

    &a; 
    a: L value            

    std::string s = c + " World";
    s: L value
    c: L value
    "World": R value 

    int& refX = x;   
    refX: L value
    x: L value  

    int&& rref = 100;     
    rref: L value
    100: R value

    
    
*/
}