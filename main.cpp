#include <iostream>
#include <vector>
#include <ctime>
enum {
    POZITIVE,
    NEGATIVE,
    MIX
};


template <class T>
void FillVector(std::vector<T> &vec, int size, int type = 0){
    if (size < 0){
        std::cout << "Error negative size" << std::endl << std::endl;
        return;
    }
    vec.clear();
    if (!type){
        for (int i = 0; i < size; ++i) {
            vec.push_back((rand())%1000);
        }
    }
    if (type == NEGATIVE){
        for (int i = 0; i < size; ++i) {
            vec.push_back((rand()*(-1))%1000);
        }
    }
    if (type == MIX){
        for (int i = 0; i < size; ++i) {
            vec.push_back((rand() * ((-1)^i)%1000));
        }
    }
}

template <class T>
void ShowVector( const std::vector<T> &vec){
    for (typename std::vector<T>::const_iterator iter = vec.begin(); iter < vec.end(); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << std::endl;
}

template<class T>
void Swap(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void Heeapify(std::vector<T> &vec, size_t size, int current = 0){
    int largest = current;
    int left = 2 * current + 1;
    int right = left + 1;
    if (left < size && vec[left] > vec[largest]){
        largest = left;
    }
    if (right < size && vec[right] > vec[largest]){
        largest = right;
    }
    if (current != largest){
        Swap(vec[current],vec[largest]);
        Heeapify(vec,size,largest);
    }


}

template <class T>
void MakeHeap(std::vector<T> &vec){
    int size = (vec.size() / 2 ) - 1;
    for (int i = size; i >= 0 ; --i) {
        Heeapify(vec,vec.size(),i);
    }
}

template <class T>
void HeapSort(std::vector<T> &vec){
    int size = vec.size();
    MakeHeap(vec);
    for (int i = size - 1; i >= 0 ;  --i) {
        Swap(vec[0], vec[i]);
        Heeapify(vec,i);
    }

}

template <class T>
void TestVector(std::vector<T> &vec, int size){
    std::cout << "Start test with (" << size << ") elements;" << std::endl << std::endl;
    for (int i = 0; i <= 2 ; ++i) {
        if (!i){
            std::cout << "Fill vector with Positive numbers: " << std::endl;
            FillVector(vec,size);
        }
        if (i == NEGATIVE){
            std::cout << "Fill vector with Negative numbers: " << std::endl;
            FillVector(vec,size,i);
        }
        if (i == MIX){
            std::cout << "Fill vector with Mix numbers: " << std::endl;
            FillVector(vec,size,i);
        }
        std::cout << "Vector before sort:" << std::endl;
        ShowVector(vec);
        std::cout << "Vector after sort:" << std::endl;
        HeapSort(vec);
        ShowVector(vec);
        std::cout << "Test finished" << std::endl << std::endl;
        vec.clear();
    }



}

int main(){
    srand(time(NULL));
    std::vector<int> vec;
    // Test zero
    int size = 0;
    TestVector(vec, size);
    //test one element
    size = 1;
    TestVector(vec,size);
    //test -1 element
    size = -1;
    TestVector(vec,size);
    //test two elements
    size = 2;
    TestVector(vec,size);
    //test three elements
    size = 3;
    TestVector(vec,size);
    //test 10 elements
    size = 10;
    TestVector(vec,size);
    //test 30 elements
    size = 30;
    TestVector(vec,size);
    //test 50 elements
    size = 50;
    TestVector(vec,size);
    //test 100 elements
    size = 100;
    TestVector(vec,size);
}