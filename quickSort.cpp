#include <iostream>
#include <vector>

void quickSort(std::vector<int> &input, std::size_t start, std::size_t end);
std::size_t partition(std::vector<int> &input, std::size_t start, std::size_t end);


int main(){
  std::vector<int> input = {12, 34, -23, 45, -3, 0, 88, 76, 34, 19000};

  for(auto i: input){
    std::cout << i << std::endl;
  }
  
  if(input.size())
    quickSort(input, 0, input.size()-1);

  std::cout << "After Sorting" << std::endl;

  for(auto i: input){
    std::cout << i << std::endl;
  }
	return(0);
}


void quickSort(std::vector<int> &input, std::size_t start, std::size_t end){
  if(start<end)
  {
  	size_t pivot = partition(input, start, end);
	quickSort(input, start, pivot-1);
	quickSort(input, pivot+1, end);
  }
}

std::size_t partition(std::vector<int> &input, std::size_t start, std::size_t end){
  // Simple Pivot
  int pivot = input[end];

  std::size_t pivotPos = start;
  for(size_t i=start; i<end; ++i){
    if(input[i] <= pivot)
      std::swap(input[i], input[pivotPos++]);
  }

  std::swap(input[pivotPos], input[end]);
  return pivotPos;
}