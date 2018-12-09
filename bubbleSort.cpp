#include <iostream>
#include <vector>

void swap(int &a, int &b);
void bubbleSort(std::vector<int> &input);

int main(){
  std::vector<int> input = {1, 6, 55, 67, 43, 23, 99, 69};

  for(auto i: input){
  	std::cout << i << std::endl;
  }

  bubbleSort(input);

  std::cout << "After Sorting" << std::endl;

  for(auto i: input){
  	std::cout << i << std::endl;
  }
}

void swap(int &a, int &b){
  if(a != b){
  	a += b;
  	b = a - b;
  	a -= b;
  }
}

void bubbleSort(std::vector<int> &input){
  for(auto i=0; i<input.size(); ++i){
    bool ctnue = false;
    for(auto j=0; j<input.size()-i-1; ++j){
    	if(input[j] > input[j+1]){
    		swap(input[j], input[j+1]);
    		ctnue = true;
    	}
    }
    if(!ctnue){
    	break;
    }
  }
}