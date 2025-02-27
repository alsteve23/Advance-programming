#include <iostream>
#include <cmath>





int main(){
    std::pair<bool,std::pair<double,double>> ans;
    double a,b,c;
    std::cout<<"Enter your equation's coeficients:"<<'\n';
    std::cout<<"a: ";std::cin>>a;
    std::cout<<"b: ";std::cin>>b;
    std::cout<<"c: ";std::cin>>c;
    double discr{pow(b,2)-4*a*c};
    if (discr<0){
        ans.first=false;
    }else{
        ans.first=true;
        ans.second.first=(b+sqrt(discr))/(2*a);
        ans.second.second=(b-sqrt(discr))/(2*a);
    }
    if (ans.first)
    {
        std::cout<<"True "<<"root1: "<<ans.second.first<<" root2:"<<ans.second.second<<'\n';
    }else{
        std::cout<<"False"<<'\n';
    }
    
};