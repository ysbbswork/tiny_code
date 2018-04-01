//¿ìËÙÅÅĞò
#include<iostream>
using namespace std;
void myswap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;

}
int partition(int data[], int start, int end) {
	if (data == NULL || start < 0 ) {
		//throw new std::exception("invaild input!");

	}
	int i = start - 1;
	for (int j = start; j < end; ++j) {
		if (data[j] < data[end]) {
			i++;
			myswap(data[i], data[j]);
		}
	}
	i++;
	myswap(data[i], data[end]);
	return i;
}

void quicksort(int data[], int start, int end) {
	if (start == end) {
		return;
	}
	int index = partition(data,start,end);
	cout << "start£º" << start << "end:" << end << "index" << index << endl;
	if(index>start)//¹Ø¼ü£¡
	quicksort(data, start, index - 1);
	if(index<end)
	quicksort(data, index + 1, end);
}
int main() {
	int test[6] = { 3,4,6,2,1,5 };

	quicksort(test, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << test[i] << ',';
	}
	

	cin.get();
	return 0;
}