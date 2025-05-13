class MyCircularQueue {
public:
  int d = -1;
  int j = 0;
  int n = 0;
  vector<int> arr;
  MyCircularQueue(int k) {
    arr.resize(k, d);
    n = k;
  }
  bool enQueue(int value) {
    if (j == n) return false;
    arr[j] = value;
    j++;
    return true;
  }
  bool deQueue() {
    if (j == 0) return false;
    for (int x = 0; x < j; x++) {
      if (x+1 == j && j == n) {
        arr[x] = -1;
        continue;
      }
      arr[x] = arr[x+1];
    }
    j--;
    return true;
  }
  int Front() {
    if (isEmpty()) return d;
    return arr.front();  
  }
  int Rear() {
    if (isEmpty()) return d;
    return arr[j-1];  
  }
  bool isEmpty() {
    return (arr.front() == d); 
  }  
  bool isFull() {
    return (arr.back() != d); 
  }
};


