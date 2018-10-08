#include <iostream>
#include "collection.h"
#include "linked_list.h"
using namespace std;

int main(){
  // Collection
  Collection<int> c;
  c.add(3);
  c.add(4);
  c.add(6);
  c.add(9);
  c.add(2);
  c.add(10);
  cout << c << endl;

  Collection<int> b(c);
  cout << b << endl;

  for(int i : c){
    cout << i * 2 << endl;
  }

  // Linked list
  LinkedList<int> nums;
  nums.add(5);
  nums.add(17);
  nums.add(23);

 
  for(int n : nums){
    cout << n << endl;
  }

  nums.remove( 17);
  nums.remove(99);

  nums.print();

  return 0;
}