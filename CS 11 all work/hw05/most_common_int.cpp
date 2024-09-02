/* 
* Program name: most_common_int 
* Author: Scott Fullenbaum
* Purpose: Find most common integer from an array
*/

#include <iostream>
using namespace std;

//global constant used for array size
const int ARR_SIZE = 1000;

//function declaration
int most_common_int(int nums [], int len);
int max_val(int nums[], int len);
void testing (int nums[], int len, int n);

int main(){
    //Test ran thru testing w/ input of array, array_length and expected output
    int array_len = 10;
    int array[] = {1, 4, 5, 2, 4, 2, 9, 1, 1, 6};
    testing(array, array_len, 1);
    
    int array_len_2 = 6;
    int array2[] = {4, 4, 2, 2, 1, 1};
    testing(array2, array_len_2, 1);
    
    int array_len_3 = 7;
    int array3[] = {0, 150, 220, 330, 440, 550, 900};
    testing (array3, array_len_3, 0);
    
    int array_len_4 = 5;
    int array4[] = {999, 999, 999, 700, 700};
    testing (array4, array_len_4, 999);
}

/* most_common_int
* Parameters: An array and it's length 
* Purpose: Finds the most common number in the array
* Returns: The most common number
*/
int most_common_int(int nums [], int len){
    int num_val[ARR_SIZE];
    
    //initializes all values to 0 to avoid issues
    for (int i = 0; i < ARR_SIZE; i++){
        num_val[i] = 0;
    }
    
    //Counts up number of times each number is repeated, matching the number to 
    //it's equivalent index, meaning an int temp = 1, means num_val[1]++
    for (int i = 0; i < len; i++){
        int temp = nums[i];
        num_val[temp] = num_val[temp] + 1; 
    }
    //finds biggest element in new array, then matches it to get largest num
    //If there is tie, returns lowest num, which is what we want
    int k = max_val(num_val, ARR_SIZE); 
    for (int i = 0; i < ARR_SIZE; i++){
        if (k == num_val[i]){
            return i;
        }
    }
    return 0;
}

/* max_val
* Parameters: An array and length of array 
* Purpose: Figures out biggest number in array, for reasons
* Returns: Said number
*/
int max_val(int nums[], int len){
    int max = 0;
    for (int i = 0; i < len; i++){
        if (nums[i] > max){
            max = nums[i];
        } 
    }
    //cout << max << endl;
    return max;
}

/* testing
* Parameters: The array, array length, and expected answer
* Purpose: Runs the test case and displays the output
* Returns: Nothing, outputs to terminal instead
*/
void testing(int nums[], int len, int n){
    cout << "TESTING: ";
    for (int i = 0; i < len; i++){ 
        cout << nums[i] << " "; 
    }
    cout << endl;
    
    int common_int = most_common_int(nums, len); //finds most common int
    if (common_int == n){ //displays output
        cout << "SUCCESS: " << common_int << endl;
    } else {
        cout << "FAILURE: " << common_int << endl;
    }
}