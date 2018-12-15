#include <iostream>
#include <vector>

void quickSort(std::vector<int> &input, int start, int end);
int partition(std::vector<int> &input, int start, int end);


int main(){
  std::vector<int> input = {12, 34, -23, 45, -3, 0, 88, 76, 34, 19000};

  for(auto i: input){
    std::cout << i << std::endl;
  }
 
  quickSort(input, 0, input.size()-1);

  std::cout << "After Sorting" << std::endl;

  for(auto i: input){
    std::cout << i << std::endl;
  }
	return(0);
}


void quickSort(std::vector<int> &input, int start, int end){
  if(start<end)
  {
  	int pivot = partition(input, start, end);
	quickSort(input, start, pivot-1);
	quickSort(input, pivot+1, end);
  }
}

int partition(std::vector<int> &input, int start, int end){
  // Simple Pivot
  int pivot = input[end];

  int pivotPos = start;
  for(int i=start; i<end; ++i){
    if(input[i] <= pivot)
      std::swap(input[i], input[pivotPos++]);
  }

  std::swap(input[pivotPos], input[end]);
  return pivotPos;
}