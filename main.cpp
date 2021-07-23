#include <iostream>
#include <vector>


/*
    Construct permutations by adding numbers from the initial array,
    calling the permute() function recursively for each position in the array.
    Each call iterates through possible numbers in the array, removing
    the number it adds from the subsequent call's pool, ensuring
    that all combinations are found and that each combination is
    unique.
*/


void print (const std::vector<int>& arr){
// Print all members of an array in order, adding a newline at the end.
    for (int num : arr){
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

void permute(std::vector<int> pool, std::vector<int> perm){

    for (int num : pool){
        // Create a new permutation array from the existing one for each number
        // in the remaining pool, and add the current number to it
        std::vector<int> new_perm{perm};
        new_perm.push_back(num);
        std::vector<int> new_pool{};

        // Generate a new pool for the subsequent call that does not contain
        // the number that was added in this iteration
        for (int num2 : pool){
            if (num2 != num){
                new_pool.push_back(num2);
            }
        }
        // Call permute() recursively if all numbers in the pool have not been
        // used; otherwise, print the permutation
        if (new_pool.size() != 0){
            permute(new_pool, new_perm);
        }
        else
            print(new_perm);
    }

}


int main(){

    std::vector<int> pool{1, 2, 3, 4, 5, 6};

    // First call to permute() contains the full pool, and an empty permutation
    // array to be filled.
    permute(pool, {});

    return 0;
}