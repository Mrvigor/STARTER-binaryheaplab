// heap.cpp
// Shunzhi Luo

#include "heap.h"
#include <iostream>
#include <vector>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int index = vdata.size() - 1;
  while(index != 0 && vdata[index] < vdata[(index - 1)/2]){
    swapup(index);
    index = (index - 1)/2;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) return;

  vdata[0] = vdata.back();
  vdata.pop_back();

  int index = 0;
  while (true) {
    int next = swapdown(index);
    if (next == index) break;
    index = next;
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty())return -1;
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.size() == 0) return true;
  return false;
}

void Heap::swapup(int x){
  if(x == 0) return;
  int val = vdata[x];
  vdata[x] = vdata[(x -1)/2];
  vdata[(x -1)/2] = val;
}
  int Heap::swapdown(int x) {
  int smallest = x;
  int left = 2 * x + 1;
  int right = 2 * x + 2;
  if (left < vdata.size() && vdata[left] < vdata[smallest])
    smallest = left;

  if (right < vdata.size() && vdata[right] < vdata[smallest])
    smallest = right;

  if (smallest != x) {
    std::swap(vdata[x], vdata[smallest]);
    return smallest;
  }

  return x; 
}