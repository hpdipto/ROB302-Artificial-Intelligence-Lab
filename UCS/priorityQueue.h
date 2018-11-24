#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;


template <class T>
class priorityQueue
{
private:
    vector<T>pQueue;
    int index;
public:
    priorityQueue();
    ~priorityQueue();
    void reheapUp();
    void reheapDown();
    void enqueu(T);
    void dequeu();
    T front();
    bool isEmpty();
    void size();
    //bool isEmpty();
};
