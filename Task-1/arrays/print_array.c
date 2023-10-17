
#include <stdio.h>  
   
int main()  
{  
    //Initialize array   
    int arr[] = {1, 2, 3, 4, 5};   
    //Calculate length of array  
    int length = sizeof(arr)/sizeof(arr[0]);  
      
    printf("Elements of given array: \n");  
    //Loop through the array by incrementing value of i   
    for (int i = 0; i < length; i++) {   
        printf("%d ", arr[i]);   
    }    
   
    return 0;  
}  
