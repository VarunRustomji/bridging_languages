// Heap Sort in C++

#include <vector>
#include <iostream>
#include <typeinfo>
#include <sstream>

using namespace std;

void buildMaxHeap(vector<int> *array);
void siftDown(int currentIdx, int endIdx, vector<int> *heap);
void swap(int i, int j, vector<int> *array);

vector<int> heapSort(vector<int> array) {
  buildMaxHeap(&array);
  for (int endIdx = array.size()-1; endIdx >0; endIdx--) {
    swap(0, endIdx, &array);
    siftDown(0, endIdx -1, &array);
  }
  return array;
}

void buildMaxHeap(vector<int> *array) {
  int firstParentIdx = (array->size() - 2) / 2;
  for (int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--) {
    siftDown(currentIdx, array -> size() - 1, array);
  }
}

void siftDown(int currentIdx, int endIdx, vector<int> *heap) {
  int childOneIdx = currentIdx * 2 + 1;
  while(childOneIdx <= endIdx) {
    int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
    int idxToSwap;
    if (childTwoIdx != -1 && heap -> at(childTwoIdx) > heap -> at(childOneIdx)) {
      idxToSwap = childTwoIdx;
    } else {
      idxToSwap = childOneIdx;
    }

    if (heap-> at(idxToSwap) > heap -> at(currentIdx)) {
      swap(currentIdx, idxToSwap, heap);
      currentIdx = idxToSwap;
      childOneIdx = currentIdx * 2 + 1;
    } else {
      return;
    }
  }
}

void swap( int i, int j, vector<int> *array) {
  int temp = array->at(j);
  array->at(j) = array->at(i);
  array->at(i) = temp;
}

int main () {
  string data;
  for (std::string line; std::getline(std::cin, line);) {
    data = line;
  }

  // Vector of string to save tokens
  vector <string> tokens;
  vector<int> intNumbers;

  // stringstream class check1
  stringstream check1(data);
  string intermediate;

  // Tokenizing w.r.t. space ' '
  while(getline(check1, intermediate, ' '))
  {
    tokens.push_back(intermediate);
  }

  // Converting token to int
  for(int i = 0; i < tokens.size(); i++) {
    int num = atoi(tokens.at(i).c_str());
    intNumbers.push_back(num);
  }

  vector<int> sol = heapSort(intNumbers);
  for(int i = 0; i < sol.size(); i++) {
    cout << sol[i] << ' ';
  }

}
