#include <iostream>
#include <vector>


void swap(int& a, int& b);
void selectionSort(std::vector<int> &input);


int main(){

    std::vector<int> input = {2,7,1,9,4,35,99,34,76,78,98};

    for(auto i: input){
        std::cout << i << " " << std::endl;
    }

    selectionSort(input);


    std::cout << "After Sorting" << std::endl;
    
    for(auto i: input){
        std::cout << i << " " << std::endl;
    }


    return 0;
}

void selectionSort(std::vector<int> &input){
    for(std::size_t i = 0; i<input.size()-1; i++){
        int minIdx = i;
        for(std::size_t j = i+1; j < input.size(); j++){
            if(input[minIdx] > input[j]){
                minIdx = j;
            }
        }
        swap(input[i], input[minIdx]);
    }

}

void swap(int& a, int& b){
    // This check is necessary if we have references
    if(a != b){
        a = a + b;
        b = a - b;
        a = a - b;
    }
}