//实现快速排序
#include<iostream>

using namespace std;
void quicksort(int *data,int length,int start,int end);
int main(){
	int *a=NULL;
	quicksort(a,1,0,1);
	for(int i =0;i<1;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
	
} 


int partion(int *data,int start,int end){
	int small = start -1;
	int randnum = data[end];
	for(int i=start;i<end;i++){
		if(data[i]<=randnum){
			++small;
			if(i!=small){
				int temp=data[i];
				data[i]=data[small];
				data[small]=temp;
			}		
		}
	}
	++small;
	int temp=data[end];
	data[end]=data[small];
	data[small]=temp;
	return small;
}

void quicksort(int *data,int length,int start,int end){
	if(data==NULL||length<=0){
		cout<<"input error!";
		return;
	}
	int index=partion(data,start,end);
	
	if(index>start){
		quicksort(data,length,start,index-1);
	}
	if(index<end){
		
		quicksort(data,length,index+1,end);
	}
}