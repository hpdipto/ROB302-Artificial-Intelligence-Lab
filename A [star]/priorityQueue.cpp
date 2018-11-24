#include "priorityQueue.h"
using namespace std;

template <class T>
priorityQueue<T>::priorityQueue()
{
    index = 0;
}

template <class T>
priorityQueue<T>::~priorityQueue()
{
    index = 0;
    pQueue.clear();
}

template <class T>
void priorityQueue<T>::reheapUp()
{
    int i = index-1;
    while(1) {
        if(i < 1)
            break;
        if(pQueue[(i-1)/2].pathCost > pQueue[i].pathCost) {
            T temp = pQueue[i];
            pQueue[i] = pQueue[(i-1)/2];
            pQueue[(i-1)/2] = temp;
            i = (i-1)/2;
        }
        else
            break;
    }
}

template <class T>
void priorityQueue<T>::reheapDown()
{
    int i = 0;
    while(1) {
        if((2*i+2) > index-1)
                break;
        if((pQueue[i].pathCost > pQueue[2*i+1].pathCost) || (pQueue[i].pathCost > pQueue[2*i+2].pathCost)) {
            if(pQueue[2*i+1].pathCost < pQueue[2*i+2].pathCost) {
                T temp = pQueue[2*i+1];
                pQueue[2*i+1] = pQueue[i];
                pQueue[i] = temp;
                i = 2*i+1;
            }
            else {
                T temp = pQueue[2*i+2];
                pQueue[2*i+2] = pQueue[i];
                pQueue[i] = temp;
                i = 2*i+2;
            }

        }
        else
            break;
    }
}

template <class T>
void priorityQueue<T>::enqueu(T n)
{
    pQueue.push_back(n);
    index++;
    if(index != 1)
        reheapUp();
}

template <class T>
void priorityQueue<T>::dequeu()
{
    //cout << pQueue[0].pathCost << endl;
    T temp = pQueue[0];
    pQueue[0] = pQueue[index-1];
    pQueue[index-1] = temp;
    index--;
    pQueue.pop_back();
    reheapDown();
}

template <class T>
T priorityQueue<T>::front()
{
    return pQueue[0];
}

template <class T>
bool priorityQueue<T>::isEmpty()
{
    if(index == 0)
        return true;
    else
        return false;
}

template <class T>
void priorityQueue<T>::size()
{
    cout << index << endl;
}
