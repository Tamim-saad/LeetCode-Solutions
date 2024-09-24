
#define ll long long


class Solution {


struct Node {
    ll height;
    ll index;
};

// Function to build the segment tree
void buildTree(vector<Node>& segmentTree, const vector<int>& heights, ll node, ll start, ll end) {
    if (start == end) {
        segmentTree[node] = { heights[start], start };
        return;
    }

    ll mid = start + (end - start) / 2;
    buildTree(segmentTree, heights, 2 * node, start, mid);
    buildTree(segmentTree, heights, 2 * node + 1, mid + 1, end);

    if (segmentTree[2 * node].height < segmentTree[2 * node + 1].height)
        segmentTree[node] = segmentTree[2 * node];
    else
        segmentTree[node] = segmentTree[2 * node + 1];
}

// Function to query the segment tree for minimum height and index
Node query(vector<Node>& segmentTree, ll node, ll start, ll end, ll l, ll r) {
    if (r < start || l > end)
        return { INT_MAX, -1 };

    if (l <= start && r >= end)
        return segmentTree[node];

    ll mid = start + (end - start) / 2;
    Node left = query(segmentTree, 2 * node, start, mid, l, r);
    Node right = query(segmentTree, 2 * node + 1, mid + 1, end, l, r);

    if (left.height < right.height)
        return left;
    else
        return right;
}

// Function to calculate the maximum area of a rectangle
ll calculateArea(vector<Node>& segmentTree, const vector<int>& heights, ll start, ll end) {
    if (start > end)
        return 0;

    if (start == end)
        return heights[start];

    Node minNode = query(segmentTree, 1, 0, heights.size() - 1, start, end);
    ll minHeight = minNode.height;
    ll minWidth = end - start + 1;
    ll area = minHeight * minWidth;

    ll leftArea = calculateArea(segmentTree, heights, start, minNode.index - 1);
    ll rightArea = calculateArea(segmentTree, heights, minNode.index + 1, end);

    return max(area, max(leftArea, rightArea));
}







public:
    int largestRectangleArea(vector<int>& heights) {
        ll n = heights.size();
    if (n == 0)
        return 0;

    // Construct the segment tree
    vector<Node> segmentTree(4 * n);
    buildTree(segmentTree, heights, 1, 0, n - 1);

    // Calculate the maximum area
    return calculateArea(segmentTree, heights, 0, n - 1);
    }
};