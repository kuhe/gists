
#include "ArrayList.h"

namespace Lehr {
    template <typename T>
    void ArrayList<T>::resize(int n, int start_index) {
        T* transfer;
        transfer = new T[n];
        for (int i = 0; i + start_index < length && i < n; i++) {
            transfer[i] = data[i + start_index];
        }
        if (data != nullptr) {
            delete[] data;
        }
        length -= start_index;
        data = transfer;
    }

    template <typename T>
    int ArrayList<T>::count() {
        return length;
    }
    template <typename T>
    ArrayList<T>::ArrayList() {
        resize(0);
    }
    template <typename T>
    ArrayList<T>::ArrayList(T item) {
        resize(1);
        data[0] = item;
        length = 1;
    }
    template <typename T>
    ArrayList<T>::ArrayList(const ArrayList<T>& source) {
        resize(source.length);
        length = source.length;
        for (int i = 0; i < length; i++) {
            data[i] = *(source.data + i);
        }
    }
    template <typename T>
    ArrayList<T>::~ArrayList() {
        delete[] data;
    }

    template <typename T>
    T& ArrayList<T>::operator[](int i) {
        return data[i];
    }

    template <typename T>
    ArrayList<T>* ArrayList<T>::push(T item) {
        if (sizeof data >= length) {
            resize((int) (RESIZE_SCALAR * (length + 1)));
        }
        data[length] = item;
        length++;
        return this;
    }
    template <typename T>
    ArrayList<T>* ArrayList<T>::unshift(T item) {
        if (sizeof data >= length + 1) {
            resize((int) (RESIZE_SCALAR * (length + 2)));
        }
        for (int i = length; i > 0; i--) {
            data[i] = data[i-1];
        }
        data[0] = item;
        length++;
        return this;
    }

    template <typename T>
    T ArrayList<T>::pop() {
        if (length > 0) {
            int index = length - 1;
            T value = data[index];
            length--;
            return value;
        }
        T dummy;
        return dummy;
    }
    template <typename T>
    T ArrayList<T>::shift() {
        if (length > 0) {
            T value = data[0];
            resize(sizeof data, 1);
            return value;
        }
        T dummy;
        return dummy;
    }
    template <typename T>
    ArrayList<T>& ArrayList<T>::excise(int at) {
        return excise(at, at);
    }
    template <typename T>
    ArrayList<T>& ArrayList<T>::excise(int from, int to) {
        if (to < from) return *this;
        for (int i = 0; i + to + 1 < length; i++) {
            data[i + from] = data[i + to + 1];
        }
        length -= 1 + (to - from);
        return *this;
    }
    template <typename T>
    ArrayList<T>& ArrayList<T>::splice(int before, ArrayList<T>& list) {
        if (before >= length) {
            for (int i = 0; i < list.length; i++) {
                push(list[i]);
            }
        } else {
            resize(length + list.length);
            for (int i = before; i < before + list.length; i++) {
                if (length >= i + list.length - 1) {
                    data[i + list.length] = data[i];
                }
                data[i] = list[i - before];
            }
            length += list.length;
        }
        return *this;
    }
    template <typename T>
    ArrayList<T>& ArrayList<T>::splice(int before, T& item) {
        ArrayList<T> container(item);
        return splice(before, container);
    }
    template <typename T>
    ArrayList<T>& ArrayList<T>::slice(int index) {
        while (index--) {
            shift();
        }
        return *this;
    }
    template <typename T>
    ArrayList<T>& ArrayList<T>::slice(int index, int length) {
        while (index--) {
            shift();
        }
        while (this->length > length) {
            pop();
        }
        return *this;
    }
}