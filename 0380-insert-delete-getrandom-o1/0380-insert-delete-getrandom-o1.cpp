// say Alhamdulillah

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

class RandomizedSet {
public:
  indexed_set st;
  RandomizedSet() {}

  bool insert(int val) {
    if (st.find(val) == st.end()) {
      st.insert(val);
      return true;
    } else
      return false;
  }

  bool remove(int val) {
    if (st.find(val) != st.end()) {
      st.erase(val);
      return true;
    } else
      return false;
  }

  int getRandom() { return *st.find_by_order(rand()%st.size()); }
};
