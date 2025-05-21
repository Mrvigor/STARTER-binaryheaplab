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
  if(vdata.size() == 0) return;
  vdata[0] = vdata[vdata.size() - 1];
  vdata.pop_back();
  int index = 0;
  while(index != vdata.size() - 1){
    index = swapdown(index);
  }
}

// Returns the minimum element in the heap
int Heap::top(){
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
int Heap:: swapdown(int x){
  int val = vdata[x];
  int left = 2 * x + 1;
  int right = 2 * x + 2;
  if(left > vdata.size() - 1 && right > vdata.size() - 1) return vdata.size() - 1;
  if(right > vdata.size() - 1 && vdata[left] > val){
    vdata[x] = vdata[left];
    vdata[left] = val;
    return left;
  }
  if(vdata[left] > vdata[right] && vdata[right] > val){
    vdata[x] = vdata[right];
    vdata[right] = val;
    return right;
  }else if(vdata[right] > vdata[left] && vdata[left] > val){
    vdata[x] = vdata[left];
    vdata[left] = val;
    return left;
  }else{
    return vdata.size() - 1;
  }
}