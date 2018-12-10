#include <iostream>
#include <vector>
#include <cmath>


void mergeSort(std::vector<int> &input);
void merge(std::vector<int> &a, std::vector<int> &b, std::vector<int> &result);

int main(){
  std::vector<int> input = {1, 6, 55, 67, 43, 23, 99, 69};

  for(auto i: input){
  	std::cout << i << std::endl;
  }

  mergeSort(input);

  std::cout << "After Sorting" << std::endl;

  for(auto i: input){
  	std::cout << i << std::endl;
  }
  return 0;

}

void mergeSort(std::vector<int> &input){
  if(input.size() == 1)
  	return;

  auto mid = (input.size()/2);

  std::vector<int> left;
  std::vector<int> right;

  // Copy performs copy of [first, last). The last element is not included.
  // back_inserter is necessary when the vector is not preallocated to its expected size
  std::copy(input.begin(), input.begin()+mid,  std::back_inserter(left));
  std::copy(input.begin()+mid, input.end(),  std::back_inserter(right));
  
  mergeSort(left);
  mergeSort(right);
  merge(left, right, input);
}

void merge(std::vector<int> &a, std::vector<int> &b, std::vector<int> &result){
	auto sizeL = a.size();
	auto sizeR = b.size();

	auto lPtr = 0;
	auto rPtr = 0;
    
  assert((sizeL+sizeR) == result.size());

	for(auto i = 0; i < result.size(); i++){
	  if(lPtr < sizeL && rPtr < sizeR){
		  if(a[lPtr] > b[rPtr]){
				result[i] = b[rPtr];
				rPtr++;
			}
			else if(a[lPtr] < b[rPtr]){
				result[i] = a[lPtr];
				lPtr++;
			}
			else{
				result[i++] = a[lPtr];
				result[i] = b[rPtr];
				lPtr++;
				rPtr++;
			}
		}
		else{
			if(lPtr < sizeL){
				result[i] = a[lPtr];
				lPtr++;
			}
			else if(rPtr < sizeR){
				result[i] = b[rPtr];
				rPtr++;
			}
		}
	}
}