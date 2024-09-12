#include <iostream>
#include <time.h>
using namespace std;

template <class T>
class Array {
private:
    int size;
    T *A;
    int length;
public:
    // Create array with default size
    Array() {
        size = 10;
        A = new T[size];
        length = 0;
    }
    // Create array with input size
    Array(int sz) {
        size = sz;
        A = new T[size];
        length = 0;
    }
    // Destructor
    ~Array() {
        delete []A;
    }
    // Methods
    int get_size();
    int get_length();
    void display();
    bool is_valid_index(int index);
    T get_element(int index);
    bool is_sorted();
    void swap(int i, int j);
    void append(T element);
    void assign(int index, T element);
    void insert(int index, T element);
    void sorted_insert(T element);
    T pop(int index);
    T max_val();
    int max_index();
    T min_val();
    int min_index();
    T sum();
    float avg();
    void sort(bool ascending = true);
    void shuffle();
    void reverse();
    void shift(bool left = true);
    void rotate(bool left = true);
    void negative_positive();
    int linear_search(T element);
    int binary_search(T element);
};

template <class T>
int Array<T>::get_size() {
    return size;
    }

template <class T>
int Array<T>::get_length() {
    return length;
}

template <class T>
void Array<T>::display() {
    int i;
    cout<<"--------------\n";
    cout<<"| Array Info |\n";
    cout<<"--------------\n";
    cout<<"Size: "<<size<<"\nLength: "<<length<<"\nElements: [";
    for (i = 0; i < length; i++) {
        if (i == length - 1) {
            cout<<A[i];
        }
        else {
            cout<<A[i]<<", ";
        }
    }
    cout<<"]\n";
}

template <class T>
bool Array<T>::is_valid_index(int index) {
    bool result;
    result = (0 <= index < length);
    return result;
}

template <class T>
T Array<T>::get_element(int index) {
    if (is_valid_index(index)) {
        return A[index];
    }
    return -1;
}

template <class T>
bool Array<T>::is_sorted() {
    if (length > 1) {
        bool isAscending = A[0] < A[length - 1]; 
        for (int i = 0; i < length - 1; i++) {
            if (isAscending) {
                if (A[i] > A[i + 1]) {
                    return false;
                }
            }
            else if (! isAscending) {
                if (A[i] < A[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template <class T>
void Array<T>::swap(int i, int j) {
    int temp;
    if (is_valid_index(i) && is_valid_index(j)) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

template <class T>
void Array<T>::append(T element) {
    if (length < size) {
        A[length] = element;
        length++;
    }
}

template <class T>
void Array<T>::assign(int index, T element) {
    if (length > 0 && is_valid_index(index))  {
        A[index] = element;
    }
}

template <class T>
void Array<T>::insert(int index, T element) {
    if (length < size) {
        if (is_valid_index(index)) {
            for (int i = length; i > index; i--) {
                A[i] = A[i - 1];
            }
            A[index] = element;
        }
    }
}

template <class T>
T Array<T>::pop(int index) {
    T element;
    if (is_valid_index(index)) {
        element = A[index];
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        return element;
    }
    return 0;
} 

template <class T>
T Array<T>::max_val() {
    int result = A[0];
    int index = 0;
    for (int i = 1; i < length; i++) {
        if (A[i] > result) {
            result = A[i];
            index = i;
        }
    }
    return result;
}

template <class T>
int Array<T>::max_index() {
    int result = A[0];
    int index = 0;
    for (int i = 1; i < length; i++) {
        if (A[i] > result) {
            result = A[i];
            index = i;
        }
    }
    return index;
}

template <class T>
T Array<T>::min_val() {
    T result = A[0];
    int index = 0;
    for (int i = 1; i < length; i++) {
        if (A[i] < result) {
            result = A[i];
            index = i;
        }
    }
    return result;
}
template <class T>
int Array<T>::min_index() {
    int result = A[0];
    int index = 0;
    for (int i = 1; i < length; i++) {
        if (A[i] < result) {
            result = A[i];
            index = i;
        }
    }
    return index;
}

template <class T>
T Array<T>::sum() {
    T result = 0;
    for (int i = 0; i < length; i++) {
        result += A[i];
    }
    return result;
}

template <class T>
float Array<T>::avg() {
    float result = (float) sum() / (float) length;  
    return result;
}

template <class T>
void Array<T>::sort(bool ascending) {
    int count;
    while (count < length - 1) {
        count = 0;
        for (int i = 0; i < length - 1; i++) {
            if (ascending) {
                if (A[i] > A[i + 1]) {
                    swap(i, i + 1);
                }
                else {
                    count++;
                }
            }
            else if (! ascending) {
                if (A[i] < A[i + 1]) {
                    swap(i, i + 1);
                }
                else {
                    count++;
                }
            }
        }
    }
}

template <class T>
void Array<T>::sorted_insert(T element) {
    bool ascending;
    if (is_sorted() && length < size) {
        ascending = A[0] < A[1];
        for (int i = length; i >= 0; i--) {
            if (i > 0) {
                if (element >= A[i - 1] && ascending || element <= A[i - 1] && ! ascending) {
                    A[i] = element;
                    break;
                }
                else {
                    A[i] = A[i - 1]; 
                }
            }
            else {
                A[i] = element;
            }
        }
        length++;
    }
}

template <class T>
void Array<T>::shuffle() {
    int i, j;
    srand(time(0));
    for (i = length - 1; i > 0; i--) {
        j = rand() % i;
        swap(i, j);
    }
}

template <class T>
void Array<T>::reverse() {
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        swap(i, j);
    }
}

template <class T>
void Array<T>::shift(bool left) {
    if (left) {
        for (int i = 0; i < length; i++) {
            if (i < length - 1) {
                A[i] = A[i + 1];
            }
            else {
                A[i] = 0;
            }
        }
    }
    else if (! left) {
        for (int i = length - 1; i >= 0; i--) {
            if (i > 0) {
                A[i] = A[i - 1];
            }
            else {
                A[i] = 0;
            }
        }
    }
}

template <class T>
void Array<T>::rotate(bool left) {
    int head = A[0];
    int tail = A[length - 1];
    shift(left);
    if (left) {
        A[length - 1] = head;
    }
    else if (! left) {
        A[0] = tail;  
    }
}

template <class T>
void Array<T>::negative_positive() {
    int i = 0;
    int j = length - 1;
    while (i < j) {
        while (A[i] < 0 && i < j) {
            i++;
        }
        while (A[j] >= 0 && i < j) {
            j--;
        }
        swap(i, j);
    } 
}

template <class T>
int Array<T>::linear_search(T element) {
    for (int i = 0; i < length; i++) {
        if (element == A[i]) {
            return i;
        }
    }
    return -1;
}

template <class T>
int Array<T>::binary_search(T element) {
    int l, m, h;
    l = 0;
    h = length;
    if (is_sorted()) {
        while (l <= h) {
            m = (l + h) / 2;
            if (element == A[m]) {
                return m;
            }
            else if (element < A[m]) {
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
    }
    return -1;
}

int main() {
    Array<float> arr(7);
    for (int i = 1; i < arr.get_size() + 1; i++) {
        arr.append((float) 1/i);
    }
    cout<<arr.sum()<<endl;
    arr.display();
    return 0;
}
