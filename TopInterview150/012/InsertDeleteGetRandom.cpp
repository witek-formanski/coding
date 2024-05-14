#include <unordered_map>
#include <cstdlib> 

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        size = 0;
        capacity = 8;
        arr = (int *)malloc(sizeof(int) * capacity);
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }

        map[val] = size;
        arr[size] = val;
        size++;

        if (size == capacity) {
            resize();
        }

        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }

        map[arr[size - 1]] = map[val];
        arr[map[val]] = arr[size - 1];
        map.erase(val);
        size--;

        return true;
    }
    
    int getRandom() {
        return arr[rand() % size];
    }

private:
    unordered_map<int,int> map; // value-index
    int* arr; // values
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        arr = (int *)realloc(arr, sizeof(int) * capacity);
    }
};