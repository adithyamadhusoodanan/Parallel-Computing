#include<stdio.h>

int main()
{
    int arr[100][100][100];
    
    //initialise a random array with values

    for (int j = 0; j <10; j++){
    for (int i = 0; i <10; i++){
        for(int k = 0; k < 24; k++){
            arr[j][i][k] = (rand() % (100 - 20 + 1)) + 20;
            ;
        }
        }
    }

      int max[11],min[11],avg[11];



        //calculate the min max and avg for all the cities
        for (int j = 0; j <10; j++)
        {
            max[j]=arr[j][0][0];
            min[j]=arr[j][0][0];
            avg[j]=0;

            for (int i = 0; i < 10; i++) {
                for(int k = 0; k < 24; k++)
                {
                if (max[j] < arr[j][i][k])
                max[j] = arr[j][i][k];

                if (min[j] > arr[j][i][k])
                min[j] = arr[j][i][k];
                avg[j]=avg[j]+arr[j][i][k];    

                }

            }
            avg[j]=avg[j]/240;
        }
        
         printf("%s       %s  %s  %s \n","    ","avg","max","min");

        for (int j = 0; j <10; j++)
        {
            printf("%s  %d  %d  %d  %d \n","city :",j+1,avg[j],max[j],min[j]);
        }

    

    

    
    return 0;
}

