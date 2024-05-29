#include <iostream>


template<typename T>
class deque{
private:
    T* arr;
    int size;
    int cap;
    int start;
    int end;

    void resize() {
        int newCap = cap == 0 ? 1 : cap * 2;
        T* newArr = new T[newCap];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[(start + i) % cap];
        }
        delete[] arr;
        arr = newArr;
        start = 0;
        end = size - 1;
        cap = newCap;

    }
public:
    //Constructor:
    deque() : arr(nullptr), size(0), cap(0), start(0), end(0){};
    //Destructor:
    ~deque() {
        delete []arr;
    }
    deque(const deque& other): size(other.size), cap(other.size),start(0), end(other.size - 1){
        arr = new T[cap];
        for (int i = 0; i < size; i++){
            arr[i] = other.arr[(i + other.start) % other.cap];
        }
    }
    deque(const T* arr1, int arrSize){
        this->size = arrSize;
        this->cap = arrSize * 2;
        this->arr = new T[cap];
        this->start = 0;
        this->end = arrSize - 1;
        for (int i = 0; i < size; i++){
            arr[i] = arr1[i];
        }

    }
    
    deque& operator=(const deque& other) {
        if (this != &other) {
            delete[] arr;
            cap = other.cap;
            size = other.size;
            arr = new T[cap];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[(other.start + i) % other.cap];
            }
            start = 0;
            end = size - 1;
        }
        return *this;
    }
    T& operator()(const size_t& i){
        return arr[(start + i) % cap];
    }

    void push_front(const T& value) {
        if (size == cap) {
            resize();
        }
        start = (start - 1 + cap) % cap;
        arr[start] = value;
        if (size == 0) {
            end = start;
        }
        ++size;

    }

    void push_back(const T& value) {
        if (size == cap) {
            resize();
        }
        if (size > 0) {
            end = (end + 1) % cap;
        }
        arr[end] = value;
        ++size;
    }

    void pop_front() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        start = (start + 1) % cap;
        --size;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        end = (end - 1 + cap) % cap;
        --size;
    }

    int Size() {
        return this -> size;
    }

    int getCapacity() const {
        return cap;
    }
    void print(){
        for (int i = 0; i < this->size; i++){
            std:: cout <<this->arr[(start + i) % cap] << " ";
        }
        std::cout << std::endl;
    }
};





int main(){
    int arr[] = {1, 2, 3, 4, 5, 8};
    deque <int> deq1(arr, 6);
    deque <int> deq2;
    deque <int> deq3(deq1);
    deq1.push_front(10);
    deq1.push_front(5);
    deq1.push_front(15);
    deq1.push_back(20);
    deq1.push_back(30);
    deq1.pop_back();
    deq1.pop_front();
    deq1.pop_front();
    deq1.pop_back();
    deq1.print();
    deq3.print();
    std:: cout << deq1.Size() << std:: endl <<  deq1(0);
}
