#include "median.hpp"

void MedianFinder::add_number(int x) {
    if (maxheap.empty()) {
        maxheap.push(x);
        return;
    }

    if (maxheap.size() == minheap.size()) {
        if (x <= maxheap.top()) maxheap.push(x);
        else minheap.push(x);
        return;
    }

    if (maxheap.size() > minheap.size()) {
        minheap.push(maxheap.top());
        maxheap.pop();
        maxheap.push(x);
    }
    else {
        maxheap.push(minheap.top());
        minheap.pop();
        minheap.push(x);
    }
}

double MedianFinder::get_median() {
    if (this->maxheap.empty()) return 0.0;

    if ((this->maxheap.size() + this->minheap.size()) % 2 == 0) {
        return (float)(maxheap.top() + minheap.top()) / 2.0;
    }
    else return (float)maxheap.top();
}
