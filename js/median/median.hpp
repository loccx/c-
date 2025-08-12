#include <iostream>
#include <queue>

/*
 * add to empty heap: goes to maxheap
 * if add to left: pop left into right
 * if add to right: pop right into left
 * keep count of total elements
 *  if odd, maxheap first element
 *  if even, average both heap first elements
*/
class MedianFinder {
public:
    void add_number(int x);
    double get_median();

private:
    std::priority_queue<int> maxheap;
    std::priority_queue<int, std::vector<int>,std::greater<int>> minheap;
};
