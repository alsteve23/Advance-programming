#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

//TASK1
void displayInventory(const std::map<std::string, int>& Inventory) {
    if(!Inventory.empty()){
            std::cout << "Current Inventory:\n";
        for (const auto& item : Inventory) {
            std::cout << item.first << ": " << item.second << " in stock\n";
        }
        std::cout << std::endl;    
    }else{
        std::cout<<"The inventory is empty"<<'\n';
    }
    

}
void addUpdateInventory(std::map<std::string, int>& inventory){
    std::pair<std::string,int> product;
    std::cout<<"Name of the product:  ";
    std::getline(std::cin, product.first);
    std::cout<<"Amount:  ";
    std::cin>>product.second;
    if(inventory[product.first]=product.second){
        std::cout<<"Inventory Updated correctly!!"<<'\n';
    }else{
        std::cout<<"Something went wrong"<<'\n';
    }

}

//TASK2
void displayCategories(const std::set<std::string>& Categories){
    if(!Categories.empty()){
        std::cout<<"Product categories:"<<'\n';
        for (const auto& category : Categories) {
            std::cout << "- " << category << "\n";
        }
    }else{
        std::cout<<"The categories list is emmpty"<<'\n';
    }
};
void addCategories(std::set<std::string>& Categories){
    std::string categorie;
    std::cout<<"Name of the category: ";
    std::getline(std::cin,categorie);
    Categories.insert(categorie);
    if (Categories.count(categorie)){
        std::cout<<"Category added correctly!!"<<'\n';
    }else{
        std::cout<<"Something went wrong"<<'\n';
    };
};

//TASK3
void addOrders (std::queue<std::string>& Orders){
    std::string order;
    std::cout<<"Enter the order: ";
    std::getline(std::cin, order);
    Orders.push(order);
    std::cout<<"Order added correctly"<<'\n';   
};
void processOrders(std::queue<std::string>& Orders){
    while (!Orders.empty()) {
        std::cout << "Processing " << Orders.front() << std::endl;
        Orders.pop();
    };
    if(Orders.empty()){
        std::cout<<"Orders processed correctly!!"<<'\n';
        }
};

//TASK4
void addRestock(std::stack<std::pair<std::string, int>>&Restocks){
    std::pair<std::string, int> restock;
    std::cout<<"Product to restock; ";
    std::getline(std::cin, restock.first);
    std::cout<<"Amount; ";
    std::cin>>restock.second;
    Restocks.push(restock);
    std::cout<<"Restock done "<<'\n';   
};
void processRestock(std::stack<std::pair<std::string, int>>&Restocks){
    while (!Restocks.empty()) {
        auto item = Restocks.top();
        std::cout << "Restocking " << item.second << " units of " << item.first << std::endl;
        Restocks.pop();
    };

};

//TASk5
void addCart(std::vector<std::string>& Cart){
    std::string product;
    std::cout<<"Enter the product: ";
    std::getline(std::cin,product);
    Cart.push_back(product);
};
void displayCart(const std::vector<std::string>& Cart){
    std::cout << "Items in customer cart:\n";
    for (const auto& item : Cart) {
        std::cout << "- " << item << "\n";
    }
};



int main() {
    std::map<std::string, int> inventory;
    std::set<std::string> productCategories;
    std::queue<std::string> orders;
    std::stack<std::pair<std::string, int>> restocks;
    std::vector<std::string> customerCart;

    // Adding products
    // inventory["Laptop"] = 5;
    // inventory["Mouse"] = 20;
    // inventory["Keyboard"] = 10;

    std::cout<<"Enter an action to the menu:"<<'\n';
    std::cout
    <<"1. Display Inventory"     <<'\n'
    <<"2. Add to Inventory"      <<'\n'
    <<"3. Update Inventory"      <<'\n'
    <<"4. Display Categories"    <<'\n'
    <<"5. Add Categories"        <<'\n'
    <<"6. Add Orders"            <<'\n'
    <<"7. Process Orders"        <<'\n'
    <<"8. Add Restock"           <<'\n'
    <<"9. Process Restock"       <<'\n'
    <<"10. Add Cart"             <<'\n'
    <<"11. Display Cart"         <<'\n';
    
    bool flag=true;
    std::string action;
    while (flag){
        std::cin>>action;
        if (action=="1"){
            displayInventory(inventory);
        }
        else if(action=="2" || action=="3"){
            addUpdateInventory(inventory);
        }
        else if(action=="4"){
            displayCategories(productCategories);
        }
        else if(action=="5"){
            addCategories(productCategories);
        }
        else if(action=="6"){
            addOrders(orders);
        }
        else if(action=="7"){
            processOrders(orders);
        }
        else if(action=="8"){
            addRestock(restocks);
        }
        else if(action=="9"){
            processRestock(restocks);
        }
        else if(action=="10"){
            addCart(customerCart);
        }
        else if(action=="11"){
            displayCart(customerCart);
        }
        else if(action=="-1"){
            flag=false;
        }
        else{
            std::cout<<"Not registered option. Try again"<<'\n';
        }
    }

    return 0;
}

