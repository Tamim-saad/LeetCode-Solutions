// say Alhamdulillah

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vec vector<ll>

// Custom comparator for comparing vectors lexicographically
struct compare {
  bool operator()(const vec &a, const vec &b) const {
    if (a[0] != b[0])
      return a[0] < b[0];
    return a[3] < b[3]; // 'a[3]' and 'b[3]' are the timestamps
  }
};

// template <typename Key, typename Mapped, typename Compare, typename Tag,
//           typename Policy>

typedef tree<vec, null_type, compare, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class LFUCache {
public:
  indexed_multiset st;
  unordered_map<ll, vec> mp;

  ll capacity;
  ll time = 0;
  LFUCache(ll capacity) { this->capacity = capacity; }

  ll get(ll key) {
    if (mp.find(key) == mp.end())
      return -1;
    vec v = mp[key];
    st.erase(v);
    v[3] = time++;
    v[0]++;
    st.insert(v);
    mp[key] = v;
    return v[2];
  }

  void put(ll key, ll value) {
    if (capacity == 0)
      return;
    if (mp.find(key) == mp.end()) {
      if (mp.size() == capacity) {
        mp.erase((*st.begin())[1]);
        st.erase(st.begin());
      }
      vec v = {1, key, value, time++};
      st.insert(v);
      mp.insert({key, v});
      return;
    }
    vec v = mp[key];
    st.erase(v);
    v[0]++;
    v[2] = value;
    v[3] = time++;
    st.insert(v);
    mp[key] = v;
  }
};
