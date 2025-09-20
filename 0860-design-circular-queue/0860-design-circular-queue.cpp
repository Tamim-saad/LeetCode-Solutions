#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
  deque<int> dq;
  int len;
  MyCircularQueue(int k) { len = k; }

  bool enQueue(int value) {
    if (dq.size() < len) {
      dq.push_back(value);
      return true;
    }
    return false;
  }

  bool deQueue() {
    if (dq.size() > 0) {
      dq.pop_front();
      return true;
    }
    return false;
  }

  int Front() {
    if (dq.size() > 0) {
      return dq.front();
    }
    return -1;
  }

  int Rear() {
    if (dq.size() > 0) {
      return dq.back();
    }
    return -1;
  }

  bool isEmpty() { return dq.empty(); }

  bool isFull() { return dq.size() >= len; }
};