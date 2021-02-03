#include <stdio.h>
#include <sys/time.h>
#include <omp.h>
#include <stdlib.h>
int main(void){
struct timeval TimeValue_Start1,TimeValue_Start2;
struct timezone TimeZone_Start1,TimeZone_Start2;
struct timeval TimeValue_Final1,TimeValue_Final2;
struct timezone TimeZone_Final1,TimeZone_Final2;
long time_start, time_end;

double time_overhead;double pi,x;
int i,n,a[10000],min,chunk;
chunk=5;

n=10000;


for(i=0;i<n;i++)
{ 
  a[i]=rand()%10;

}

min=a[0];
gettimeofday(&TimeValue_Start1, &TimeZone_Start1);

for(i=0;i<=n;i++){
if(a[i]<min)
{
  min=a[i];
}

}

gettimeofday(&TimeValue_Final1, &TimeZone_Final1);
time_start = TimeValue_Start1.tv_sec * 1000000 + TimeValue_Start1.tv_usec;
time_end = TimeValue_Final1.tv_sec * 1000000 + TimeValue_Final1.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
printf("\n\n\tTime in Seconds (T) sequential Execution is: %lf\n",time_overhead);

printf("\n \n Minimum after sequential Execution is %d\n\n",min);



min=a[0];
gettimeofday(&TimeValue_Start2, &TimeZone_Start2);

#pragma omp parallel for num_threads(20) private(i) shared(min) schedule(static)
for(i=0;i<=n;i++){

if(a[i]<min)
{
  min=a[i];
}

}

gettimeofday(&TimeValue_Final2, &TimeZone_Final2);
time_start = TimeValue_Start2.tv_sec * 1000000 + TimeValue_Start2.tv_usec;
time_end = TimeValue_Final2.tv_sec * 1000000 + TimeValue_Final2.tv_usec;
time_overhead = (time_end - time_start)/1000000.0;
printf("\n\n\tTime in Seconds (T) : %lf\n",time_overhead);

printf("\n \n Minimum is %d\n\n",min);


}
