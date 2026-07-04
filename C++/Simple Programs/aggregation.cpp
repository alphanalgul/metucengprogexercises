#include <iostream> 
using namespace std; 
 
class Component{ 
 private: 
  int value; 
 public: 
  Component(int value): value(value){} 
  void set(int value){ 
   this->value = value; 
  } 
  int get(){ 
   return value; 
  } 
}; 
 
class Aggregate{ 
 private: 
  Component *contained1, * contained2; 
 public: 
  Aggregate(Component* one, Component* two) { 
      contained1 = one; 
      contained2 = two; 
  } 
  void show_components(){ 
   cout << contained1 ->get() << " | " << contained2 ->get(); 
  } 
}; 
 
int main(){ 
 Component *first = new Component(1); 
 Component *second = new Component(3); 
 Aggregate *aggregate = new Aggregate(first, second); 
 aggregate->show_components(); 

 delete aggregate;
 delete first;
 delete second;

 return 0; 
}
