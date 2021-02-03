#include<stdio.h>

int main()
{
    int arr[1000][1000];

    //generating random values for image array.
    for (int i = 0; i <256; i++){
        for(int k = 0; k < 256; k++){
            arr[i][k] = (rand() % (255 - 0 + 1)) + 0;
            
        }
    }




 //increasing each pixel value by a 20H also setting the maximum value to be 255
 for (int i = 0; i <256; i++){
        for(int k = 0; k < 256; k++){
            arr[i][k] = arr[i][k] + 32;
            
        if(arr[i][k]>255)
        {
            arr[i][k]=255;
        
        }

        }
    }

        //printing the array
        for (int i = 0; i <256; i++){
        printf("%s","\n");
        for(int k = 0; k < 256; k++){
            printf("%x ",arr[i][k]);
            
        }
    }







}
