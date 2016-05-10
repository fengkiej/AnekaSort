#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(vector<int> &data);
void selectSort(vector<int> &data);
void insertSort(vector<int> &data);
void mergeSort(vector<int> &data);
void quickSort(vector<int> &data,int upper,int lower);
void r_quickSort(vector<int> &data);
void countSort(vector<int> &data);
void radixSort(vector<int> &data);

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int getMaxValue(vector<int> &arr){
	int length = arr.size(), max;
	max = arr[0];
	for(int i = 1; i < length; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

int dataLength; bool isManualInput = false;
int MAX_RAND = 27; //SET MAX VALUE FOR TO BE GENERATED IN RANDOM DATA

int main(int argc, char **argv)
{
	srand(time(NULL)); //SEED FOR RANDOM DATA
	
	cout << "How many data?: "; cin >> dataLength;
	
	vector<int> data(dataLength);
	
	cout << "0. Generate Data	1. Manual Input\n"; 
	cin >> isManualInput;
	
	if(isManualInput){
		for(int i = 0; i < dataLength; i++){
			cout << "Data: ";
			cin >> data[i];
		}
	} else { 
		for(int i = 0; i < dataLength; i++){
			data[i] = rand() % MAX_RAND; 
			cout << data[i] << " ";
		}
	}
	cout << endl;
	
	cout << "1. Bubble Sort\n"
		 << "2. Selection Sort\n"
		 << "3. Insertion Sort\n"
		 << "4. Merge Sort\n"
		 << "5. Quick Sort\n"
		 << "6. R-Quick Sort\n"
		 << "7. Counting Sort\n"
		 << "8. Radix Sort\n";
	
	//ask for user choice, valid input: 1-8
	int q; bool is_qValid = false;
	do {
		cout << "Choose sorting method: ";
		cin >> q;
		if(q >= 1 && q <= 8){ 
			is_qValid = true; 
		} else {
			cout << "Invalid input.\n";
		}
	} while(is_qValid == false);
	
	switch(q){
		case 1:
			bubbleSort(data);
			break;
		case 2:
			selectSort(data);
			break;
		case 3:
			insertSort(data);
			break;
		case 4:
			mergeSort(data);
			break;
		case 5:
			quickSort(data,dataLength-1,0);
			break;
		case 6:
			r_quickSort(data);
			break;
		case 7:
			countSort(data);
			break;
		case 8:
			radixSort(data);
			break;
		default:
			//nothing
			break;
	}
	
	//print the sorted data
	for(int i = 0; i < dataLength; i++){
		cout << data[i] << " ";
	}
	
	cout << endl;
	return 0;
}

/* LIST OF SORTING FUNCTIONS *
 * ------------------------- */
void bubbleSort(vector<int> &data){
	int lastUnsortedElement = dataLength - 1;
	bool swapped = false;
	
	do {
		swapped = false;
		for(int i = 0; i < lastUnsortedElement; i++){
			if(data[i] > data[i+1]){
				swap(data[i], data[i+1]);
				swapped = true;
			}
		}
		
		lastUnsortedElement--;
	} while(swapped == true);
}

void selectSort(vector<int> &data){
	int min, numOfElements = dataLength - 1, firstUnsortedIndex = 0;
	
	for(int i = 0; i < numOfElements; i++){
		min = firstUnsortedIndex;
		
		for(int j = firstUnsortedIndex + 1; j <= numOfElements; j++){
			if(data[j] < data[min]){
				min = j;
			}
		}
		
		swap(data[min], data[firstUnsortedIndex]);
		firstUnsortedIndex++;
	}
}

void insertSort(vector<int> &data){
	int length = dataLength;
	
	for(int i = 1; i < length; i++){
		int curIndex = i;
		for(int j = i - 1; j >= 0; j--){
			if(data[curIndex] < data[j]){
				swap(data[curIndex], data[j]);
				curIndex = j;
			} else {
				break;
			}
		}
	}
}

void mergeSort(vector<int> &data){
	
}

void quickSort(vector<int> &data,int upper,int lower){
	int pivot=upper;
	int i=upper-1;
	int j=lower;
	
	if(i > j){
		while(i > j){
			while(data[i] >= data[pivot] && i >= j){
				i--;
			}
			while(data[j] < data[pivot] && j <= i){
				j++;
			}
			if(i > j){
				swap(data[i],data[j]);
			}else if(j > i){
				swap(data[j],data[pivot]);
			}
		}
	}else if(i==j && data[i]>data[pivot]){
		swap(data[i],data[pivot]);
	}
	
	if(j-1>lower){
		quickSort(data,j-1,lower);
	}
	if(i+2<upper){
		quickSort(data,upper,i+2);
	}
	return;
}

void r_quickSort(vector<int> &data){
	
}

void countSort(vector<int> &data){
	int length = dataLength;
	int maxRange = getMaxValue(data) + 1;
	vector<int> counter(maxRange);
	
	for(int i = 0; i < length; i++){
		counter[data[i]]++;
	}
	
	int dataIndex = 0;
	for(int i = 0; i < maxRange; i++){
		while(counter[i] > 0){
			data[dataIndex] = i;
			counter[i]--;
			dataIndex++;
		}
	}
}

void radixSort(vector<int> &data){
	
}
