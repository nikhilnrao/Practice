#include <iostream>
#include <vector>


void insertionSort(std::vector<int> &input);

int main(){
  std::vector<int> input = {0, -12, -24, -1999};//{1, 6, 55, 67, 43, 23, 99, 69};

  for(auto i: input){
  	std::cout << i << std::endl;
  }

  insertionSort(input);

  std::cout << "After Sorting" << std::endl;

  for(auto i: input){
  	std::cout << i << std::endl;
  }
  return 0;
}

void insertionSort(std::vector<int> &input){
  for(auto i=1; i<input.size(); ++i){
    auto vacant = i;
    int val = input[vacant];

    while(input[vacant-1] > val && vacant > 0){
    	input[vacant] = input[vacant-1];
    	vacant = vacant - 1;
    }

    input[vacant] = val;
  }

  return;
}
