#include <iostream>
#include <vector>

template <class T>
void Swap(T& first, T& second){
    T* temp = new T;
    *temp = first;
    first = second;
    second = *temp;
    delete temp;
};
template <class T>
void Heapify(std::vector<T> &array, int size = 0, int current = 0);


template <class T>
void SortHeap(std::vector<T> &array){

    int size = array.size();
    for (int i = size-1; i > 0 ; --i) {
        Swap(array[0],array[i]);
        Heapify(array,i);
    }

};

template <class T>
void FillArray(std::vector<T> &array, int size) {
    array.clear();
    array.resize(size);
    for (int i = size - 1; i >= 0; --i) {
        array[i] = i;
    }
}

template <class T>
void ShowArray(const std::vector<T> &array){
    for (typename std::vector<T>::const_iterator it = array.cbegin(); it != array.cend(); ++it ) {
        std::cout <<  *it << " ";
    }
    std::cout<<std::endl;
}

template<class T>
void Heapify(std::vector<T> &array, int size, int current) {
    int largest = current; // Объявляем переменную для индекса наибольшего элемента, по умолчанию это корневой элемент.
    int left = 2 * current + 1; // Объявляем левого и правого потомков
    int right = 2 * current + 2;
    // Проверка на наибольшее число в поддереве.
    if (left < size && array[left] > array[largest]) { // Так как мы можем рекурсивно зайти в элемент без потомков, устонавливаем в условии
        largest = left;//- что индекс левого и правого потомка, не выходят за рамки массива.
    }
    if (right < size && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != current) {
        Swap(array[largest], array[current]);
        Heapify(array,size,largest);
    }
}

template <class T>
void MakeHeap(std::vector<T> &array){
    int size = (array.size()/2) -1;
    for (int i = size; i >= 0; --i) {
        Heapify(array,i);
    }
};


int main() {
    int size = 6;
    std::vector<int> array;
    FillArray(array,size);

    std::cout << "--------Before MakeHeap--------" << std::endl;
    ShowArray(array);
    MakeHeap(array);
    std::cout << "--------After MakeHeap--------" << std::endl;
    ShowArray(array);

    std::cout << std::endl;

    std::cout << "--------Before Sort--------" << std::endl;
    ShowArray(array);
    SortHeap(array);
    std::cout << "--------After Sort--------" << std::endl;
    ShowArray(array);
}