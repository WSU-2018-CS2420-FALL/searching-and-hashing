#include <iostream>
#include <chrono>
#include "collection.h"
#include "linked_list.h"

using namespace std;

int main(){
  using namespace chrono;
  auto start = high_resolution_clock::now();
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

  auto end = high_resolution_clock::now();
  duration<double> span = end - start;
  cout << "It took " << span.count() << " seconds to run the collection code above." << endl;
  // Linked list
  start = high_resolution_clock::now();
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
  end = high_resolution_clock::now();
  span = end - start;
  cout << "It took " << span.count() << " seconds to run the collection code above." << endl;
  return 0;
}