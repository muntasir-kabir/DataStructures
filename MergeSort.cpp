#include<iostream>

using namespace std;

template<typename T>
class MergeSort {

public:
	static void sort(T arr[], T temp[], int size) {

		for (int s = 2; s >> 1 < size; s = s << 1) {

			cout << " IT STEP " << s << endl;
			for (int l = 0, m = s >> 1, r = s;
				m < size;
				l += s, m += s, r += s
				) {

				if (r > size)
					r = size;

				int i = l, j = m, k = 0;
				
				cout << " IT " << l << ", " << m << ", " << r << " ";
				print(&arr[i], m - l);
				cout << ", ";
				print(&arr[m], r - m);
				cout << " >";


				while (i < m && j < r) {
					if (arr[i] > arr[j])
						temp[k++] = arr[j++];
					else
						temp[k++] = arr[i++];
				}

				while (i < m) {
					temp[k++] = arr[i++];
				}
				while (j < r) {
					temp[k++] = arr[j++];
				}

				// copy back to arr
				for (i = l, j = 0; i < r; ++i, ++j)
					arr[i] = temp[j];

				print(&arr[l], r-l);
				cout << endl;
			}
		}
	}

	static void print(T d[], int size) {
		cout << "{";
		for (int i = 0; i < size; ++i)
			cout << (i == 0 ? "" : ",") << d[i];

		cout << "}";
	}
};

#define SIZE 10

int main() {
	
	int a[] = { 9,5,3,4,2,1,5, 3, 44,1,2,3,5,6,7,11,2,3,4,5,6,7,223,33,999};
	int t[SIZE];



	MergeSort<int>::print(a, SIZE);
	cout << endl;

	MergeSort<int>::sort(a, t, SIZE);

	MergeSort<int>::print(a, SIZE);
	cout << endl;
	return 0;
}
