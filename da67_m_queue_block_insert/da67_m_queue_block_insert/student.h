#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm> // For std::max
#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element) {
    // Case 1: Not enough capacity. Must resize and copy.
    if (mSize + m > mCap) {
        // Use a better growth strategy to avoid frequent reallocations.
        size_t newCap = std::max(mCap * 2, mSize + m);
        T *arr = new T[newCap]();

        // Copy the first p elements
        for (size_t i = 0; i < p; i++) {
            arr[i] = mData[(mFront + i) % mCap];
        }

        // Insert the m new elements
        for (size_t i = 0; i < m; i++) {
            arr[p + i] = element;
        }

        // Copy the remaining (mSize - p) elements
        for (size_t i = p; i < mSize; i++) {
            arr[i + m] = mData[(mFront + i) % mCap];
        }

        delete[] mData;
        mData = arr;
        mCap = newCap;
        mFront = 0; // The new array is linear, so front is 0.
    }
    // Case 2: Enough capacity. Shift elements in-place (much faster).
    else {
        // To be efficient, we shift the smaller part of the queue.
        if (p < mSize - p) {
            // Option A: The front part is smaller. Shift it left by m positions.
            size_t newFront = (mFront - m + mCap) % mCap;
            for (size_t i = 0; i < p; i++) {
                mData[(newFront + i) % mCap] = mData[(mFront + i) % mCap];
            }
            mFront = newFront;
        } else {
            // Option B: The back part is smaller. Shift it right by m positions.
            // We must copy from right-to-left to avoid overwriting elements.
            for (int i = mSize - 1; i >= (int)p; i--) {
                mData[(mFront + i + m) % mCap] = mData[(mFront + i) % mCap];
            }
        }

        // Now that a gap has been created, fill it with the new element.
        for (size_t i = 0; i < m; i++) {
            mData[(mFront + p + i) % mCap] = element;
        }
    }

    // Finally, update the size.
    mSize += m;
}

#endif