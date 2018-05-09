class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0;i<length;i++){
            int index = numbers[i];
            if(index>=length) index-=length;
            if(numbers[index]>=length) {
                *duplication = index;
                return 1;
            }
            else numbers[index]+=length;
        }
        return 0;
    }
};
