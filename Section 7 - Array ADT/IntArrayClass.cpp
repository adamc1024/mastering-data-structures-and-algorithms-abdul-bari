#include <iostream>
#include <time.h>
using namespace std;

class Array {
private:
    int size;
    int *A;
    int length;
public:
    // Create array with default size
    Array() {
        size = 10;
        A = new int[size];
        length = 0;
    }
    // Create array with input size
    Array(int sz) {
        size = sz;
        A = new int[size];
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
    int get_element(int index);
    bool is_sorted();
    void swap(int i, int j);
    void append(int element);
    void assign(int index, int element);
    void insert(int index, int element);
    void sorted_insert(int element);
    int pop(int index);
    int max_val();
    int max_index();
    int min_val();
    int min_index();
    int sum();
    float avg();
    void sort(bool ascending = true);
    void shuffle();
    void reverse();
    void shift(bool left = true);
    void rotate(bool left = true);
    void negative_positive();
    int linear_search(int element);
    int binary_search(int element);
};

int Array::get_size() {
    return size;
    }

int Array::get_length() {
    return length;
}

void Array::display() {
    int i;
    cout<<"--------------\n";
    cout<<"| Array Info |\n";
    cout<<"--------------\n";
    cout<<"Size: "<<size<<"\nLength: "<<length<<"\nElements: [";
    for (i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", A[i]);
        }
        else {
            printf("%d, ", A[i]);
        }
    }
    cout<<"]\n";
}

bool Array::is_valid_index(int index) {
    bool result;
    result = (0 <= index < length);
    return result;
}

int Array::get_element(int index) {
    if (is_valid_index(index)) {
        return A[index];
    }
    return -1;
}

bool Array::is_sorted() {
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

void Array::swap(int i, int j) {
    int temp;
    if (is_valid_index(i) && is_valid_index(j)) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

void Array::append(int element) {
    if (length < size) {
        A[length] = element;
        length++;
    }
}

void Array::assign(int index, int element) {
    if (length > 0 && is_valid_index(index))  {
        A[index] = element;
    }
}

void Array::insert(int index, int element) {
    if (length < size) {
        if (is_valid_index(index)) {
            for (int i = length; i > index; i--) {
                A[i] = A[i - 1];
            }
            A[index] = element;
        }
    }
}

int Array::pop(int index) {
    int element;
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

int Array::max_val() {
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

int Array::max_index() {
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

int Array::min_val() {
    int result = A[0];
    int index = 0;
    for (int i = 1; i < length; i++) {
        if (A[i] < result) {
            result = A[i];
            index = i;
        }
    }
    return result;
}
int Array::min_index() {
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

int Array::sum() {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result += A[i];
    }
    return result;
}

float Array::avg() {
    float result = (float) sum() / (float) length;  
    return result;
}

void Array::sort(bool ascending) {
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

void Array::sorted_insert(int element) {
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

void Array::shuffle() {
    int i, j;
    srand(time(0));
    for (i = length - 1; i > 0; i--) {
        j = rand() % i;
        swap(i, j);
    }
}

void Array::reverse() {
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        swap(i, j);
    }
}

void Array::shift(bool left) {
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

void Array::rotate(bool left) {
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

void Array::negative_positive() {
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

int Array::linear_search(int element) {
    for (int i = 0; i < length; i++) {
        if (element == A[i]) {
            return i;
        }
    }
    return -1;
}

int Array::binary_search(int element) {
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
    Array arr(10);
    arr.append(1);
    arr.display();
    return 0;
}
