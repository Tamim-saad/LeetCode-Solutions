#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
  SmallestInfiniteSet() {}
  set<int> st;
  int smallest = 1;

  int popSmallest() {
    int i = 1;
    while (1) {
      if (st.find(i) == st.end()) {
        st.insert(i);
        return i;
      }
      i++;
    }
  }

  void addBack(int num) {
    if (st.find(num) != st.end())
      st.erase(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */