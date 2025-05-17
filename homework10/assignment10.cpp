
#include<fstream>
#include<iostream>
#include <string>
#include<vector>
#include<sstream>
#include <windows.h>
#include "CLI11.hpp"
#include"barkeep.h"
using namespace std;


vector<string> split(const string& s, char delim) {
  std::vector<string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (getline(ss, token, delim)) {
    return_vec.push_back(token);
  }
  return return_vec;
}


vector<vector<string>> fromCountry(string fileName, string country){
    string line;
    vector<vector<string>> ans;
    ifstream file(fileName);
    if(file.is_open()){
      long long unsigned int  total=0;
      string xd;
      while(getline(file,xd)){
        total+=1;
      };
      file.clear(); // Reset EOF flag
      file.seekg(0);
      cout<<total<<'\n';
      size_t progress = 0;
      auto bar= barkeep::ProgressBar(&progress, barkeep::ProgressBarConfig<size_t>{.total = total});
      bar->show();
      while(getline(file, line)){
        progress++;
        vector<string>aux= split(line, ';');
        if(aux[7]==country){
        ans.push_back(aux);
      }
    }
    }else{
      cout<<"no se abrió el archivo"<<endl;
    }
    
    file.close();
    return ans;
}

vector<vector<string>> fromCountry(string fileName){
    string line;
    vector<vector<string>> ans;
    ifstream file(fileName);
    while(getline(file, line)){
      vector<string>aux= split(line, ';');
      ans.push_back(aux);
    }
    return ans;
}

void printing(vector<vector<string>>& filtered){
  cout<<"InvoiceNo; StockCode; Description; Quantity; InvoiceDate; UnitPrice; CustomerID; Country"<<endl;
  for(auto i:filtered){
    for (auto j:i){
      cout<<j<<"; ";
    }
    cout<<"\n";
  };
};


int main(int argc, char** argv){
  SetConsoleOutputCP(CP_UTF8);
  string fileName= "..\\Online_Retail.csv";

  CLI::App app("first try");
  string country;
  app.add_option("country", country, "filter by country: ");
  CLI11_PARSE(app,argc,argv);
  auto anim = barkeep::Animation({.message = "Cargando datos...", .style = barkeep::Earth});
  vector<vector<string>> ans;
  if(country.empty()){
    ans=fromCountry(fileName);
  }else{
    ans=fromCountry(fileName,country);
  }
  printing(ans);
  return 0;
}