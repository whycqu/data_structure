#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

// 插入排序，冒泡排序，选择排序，希尔排序,归并排序，快速排序，堆排序，基数排序

// 打印序列
void print(int a[], int n) {
	for(int i = 0;i < n;i++) {
		cout << setw(3) << a[i] << " ";
	}
	cout << endl;
}

// 插入排序
void inssort(int a[], int n) {
	for(int i = 1;i < n;i++) {
		for(int j = i; (j > 0) && a[j] < a[j - 1];j--) {
			swap(a[j], a[j - 1]);
		}
		print(a, n);
	}
}

// 冒泡排序
void bubsort(int a[], int n) {
 	for(int i = 0;i < n - 1;i++) {
 		for(int j = n - 1;j > i;j--) {
 			if(a[j] < a[j - 1]) {
 				swap(a[j], a[j - 1]);
 			}
 		}
		print(a, n);
 	}
}

// 选择排序
void selsort(int a[], int n) {
	for(int i = 0;i < n - 1;i++) {
		int lowindex = i;
		for(int j = n - 1;j > i;j--) {
			if(a[j] < a[lowindex]) {
				lowindex = j;
			}
		}
		swap(a[i], a[lowindex]);
		print(a, n);
	}
}

// 希尔排序
void inssort2(int a[], int n, int incr) {
	for(int i = incr;i < n;i += incr) {
		for(int j = i;(j >= incr) && a[j] < a[j - incr];j -= incr) {
			swap(a[j], a[j - incr]);
		}
	}
}

void shellsort(int a[], int n) {
	for(int i = n / 2;i > 2;i /= 2) {
		for(int j = 0;j < i;j++) {
			inssort2(a, n - j, i);
		}
		print(a, n);
	}
	inssort2(a, n, 1);
	print(a, n);
}

// 归并排序
void mergesort(int a[], int temp[], int left, int right, int n) {
	if(left == right) return;
	int mid = (left + right) / 2;
	mergesort(a, temp, left, mid, n);
	mergesort(a, temp, mid + 1, right, n);
	
	for(int i = left;i <= right;i++) {
		temp[i] = a[i];
	}
	int i1 = left;
	int i2 = mid + 1;
	for(int curr = left;curr <= right;curr++) {
		if(i1 == mid + 1) {
			a[curr] = temp[i2++];
		} else if(i2 > right) {
			a[curr] = temp[i1++];
		}else if(temp[i1] < temp[i2]) {
			a[curr] = temp[i1++];
		}else {
			a[curr] = temp[i2++];
		}
	}
	print(a, n);
}

// 快速排序
inline int findpivot(int a[], int i, int j) {
	return (i + j) / 2;
}

inline partition(int a[], int l, int r, int& pivot) {
	do {
		while(a[++l] < pivot);
		while((l < r) && pivot < a[--r]);
		swap(a[l], a[r]);
	}while(l < r);
}

void qsort(int a[], int i, int j, int n) {
	if(j <= i) return;
	int pivotindex = findpivot(a, i, j);
	swap(a[pivotindex], a[j]);
	int k = partition(a, i - 1, j, a[j]);
	swap(a[k], a[j]);
	qsort(a, i, k - 1, n);
	qsort(a, k + 1, j, n);
	print(a, n);
}

// 堆排序
class heap {
private:
	int* Heap;
	int maxsize;
	int n;
	void siftdown(int pos) {
		while(!isLeaf(pos)) {
			int j = leftchild(pos);
			int rc = rightchild(pos);

			if((rc < n) && Heap[rc] > Heap[j])
				j = rc;
			if(Heap[pos] > Heap[j]) return;
			swap(Heap[pos], Heap[j]);
			pos = j;
		}
	}
public:
	heap(int* h, int num, int max) {
		Heap = h;
		n = num;
		maxsize = max;
		buildHeap();
	}
	bool isLeaf(int pos) const {
		return (pos >= n / 2); 
	}
	int leftchild(int pos) const {
		return 2 * pos + 1;
	}
	int rightchild(int pos) const {
		return 2 * pos + 2;
	}
	void buildHeap() {
		for(int i = n / 2 - 1;i >= 0;i--) {
			siftdown(i);
		}

	}
	int removefirst() {
		swap(Heap[0], Heap[--n]);
		if(n != 0) siftdown(0);
		return Heap[n];
	}
};

void heapsort(int a[], int n) {
	int maxval;
	heap H(a, n, n);
	for(int i = 0;i < n;i++) {
		maxval = H.removefirst();
		print(a, n);
	}
}

// 基数排序
void radix(int a[], int b[], int n, int k, int r, int cnt[]) {
	int j;
	for(int i = 0, rtoi = 1;i < k;i++, rtoi *= r) {
		for(j = 0;j < r;j++) cnt[j] = 0;
		for(j = 0;j < n;j++) cnt[(a[j] / rtoi) % r]++;
		for(j = 1;j < r;j++) cnt[j] = cnt[j - 1] + cnt[j];
		for(j = n - 1;j >= 0;j--) {
			b[--cnt[(a[j] / rtoi) % r]] = a[j];
		}
		for(j = 0;j < n;j++) a[j] = b[j];
		print(a, n);
	}
}

void init(int a[], int b[], int n) {
	for(int i = 0;i < n;i++) {
		a[i] = b[i];
	}
}

int main() {
	// freopen("C:\\Users\\Administrator\\Desktop\\test_data\\input.txt", "r", stdin);
	// freopen("C:\\Users\\Administrator\\Desktop\\test_data\\output.txt", "w", stdout);

	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int origin[] = {12, 21, 16, 30, 8, 28, 4, 10, 20, 36, 18, 31, 73, 19, 45, 67};
	const int n = 16;
	int temp[n];
	int a[n];
	int b[n];
	int cnt[n];
	
	init(a, origin, n);
	cout << "insert sort : " << endl;
	inssort(a, n);
	cout << endl;

	init(a, origin, n);
	cout << "bubble sort : " << endl;
	bubsort(a, n);
	cout << endl;

	init(a, origin, n);
	cout << "selection sort : " << endl;
	selsort(a, n);
	cout << endl;

	init(a, origin, n);
	cout << "shell sort : " << endl;
	shellsort(a, n);
	cout << endl;

	init(a, origin, n);
	cout << "merge sort : " << endl;
	mergesort(a, temp, 0, n - 1, n); 
	cout << endl;

	init(a, origin, n);
	cout << "quick sort : " << endl;
	qsort(a, 0, n - 1, n);
	cout << endl;

	init(a, origin, n);
	cout << "heap sort : " << endl;
	heapsort(a, n);
	cout << endl;

	init(a, origin, n);
	cout << "radix : " << endl;
	radix(a, b, n, 16, 10, cnt);
	cout << endl;

	return 0;
}