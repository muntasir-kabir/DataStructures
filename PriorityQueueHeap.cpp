#include<iostream>
using namespace std;

template<typename T>
class PriorityQueue {
	int size;
	T* arr;

	inline int parent(int i) { return i >> 1; }
	inline int left(int i) { return i << 1; }
	inline int right(int i) { return (i << 1) + 1; }

	void heapify(int i) {
		if (i <= 0)
			return;

		int l = left(i);

		int pick = i;
		if (size >= l && arr[pick] > arr[l])
			pick = l;

		int r = right(i);
		if (size >= r && arr[pick] > arr[r])
			pick = r;

		if (pick != i) {
			std::swap(arr[i], arr[pick]);
			heapify(pick);
		}
	}

public:

	PriorityQueue(T arr[]) {
		this->arr = arr;
		this->size = 0;
	}

	bool hasMore() {
		return size > 0;
	}

	void enqueue(T d) {
		arr[++size] = d;

		int i = size;
		while (i > 1 && arr[i] < arr[parent(i)]) {
			std::swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	T top() {
		return arr[1];
	}

	T dequeue() {
		auto r = arr[1];
		arr[1] = arr[size--];
		heapify(1);

		return r;
	}
};

int main() {
	int arr[20];
	PriorityQueue<int> pq(arr);

	pq.enqueue(10);
	pq.enqueue(5);
	pq.enqueue(5);
	pq.enqueue(9);
	pq.enqueue(1);

	while (pq.hasMore())
		cout << "Minimum: " << pq.dequeue() << endl;

	cout << "Should be : 1 5 5 9 10" << endl;

	pq.enqueue(10);
	pq.enqueue(1);
	pq.enqueue(9);
	pq.enqueue(2);
	pq.enqueue(8);
	pq.enqueue(3);
	pq.enqueue(7);
	pq.enqueue(4);
	pq.enqueue(6);
	pq.enqueue(5);
	pq.enqueue(1);
	pq.enqueue(-1);
	while (pq.hasMore())
		cout << "Minimum: " << pq.dequeue() << endl;

	cout << "Should be : -1 1 1 2 3 4 5 6 7 8 9 10 " << endl;
	return 0;
}
