#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define size 10

int array1[size],array2[size];

void* shellsort(){
int n,i;
n=sizeof(array1)/sizeof(array1[0]);
int gap;
for(gap=n/2;gap>0;gap/=2){
for(i=gap;i<n;i+=1){
int temp =array1[i];
int j;
for(j=i;j>=gap && array1[j-gap]>temp;j-=gap){

array1[j]=array1[j-gap];

}
array1[j]=temp;

}

}


}


void* selectionsort(){
int i,j,temp;
for(i=0;i<size;i++){
for(j=i;j<size;j++){
if(array2[i]>array2[j]){
temp=array2[i];
array2[i]=array2[j];
array2[j]=temp;
}
}
}

}


int main(){
pthread_t tid1,tid2;

int i,j,k,l;
clock_t begin,end;
double time_elapsed;

srand(time(NULL));
for(i=0;i<size;i++){
array1[i]=rand() % 100;
array2[i]=rand() % 100;
}
printf("\nArray1 before sorting.\n");
for(i=0;i<size;i++){
printf("%d\t",array1[i]);
}

printf("\n\nArray2 before sorting.\n");
for(i=0;i<size;i++){
printf("%d\t",array2[i]);
}

begin=clock();
pthread_create(&tid1,NULL,shellsort,NULL);
pthread_create(&tid1,NULL,selectionsort,NULL);
pthread_join(tid1,NULL);
pthread_join(tid1,NULL);
end=clock();
time_elapsed=(double) (end-begin)/CLOCKS_PER_SEC;

printf("\nArray1 after sorting.\n");
for(i=0;i<size;i++){
printf("%d\t",array1[i]);
}



printf("\nArray2 after sorting.\n");
for(i=0;i<size;i++){
printf("%d\t",array2[i]);
}
printf("\n\nTotal time it takes to sort both arrays parallelly is %lf seconds",time_elapsed);
return 0;
}








