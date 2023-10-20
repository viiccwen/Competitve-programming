/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
 private:
  vector<int> vec;
  int index;

  vector<int> flat(vector<NestedInteger> &nestedList) {
    vector<int> result;

    for (auto &node : nestedList) {
      if (node.isInteger())
        result.push_back(node.getInteger());
      else {
        vector<int> subResult = flat(node.getList());
        result.insert(result.end(), subResult.begin(), subResult.end());
      }
    }

    return result;
  }

 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    vec = flat(nestedList);
    index = 0;
  }

  int next() { return vec[index++]; }

  bool hasNext() { return index < vec.size(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */