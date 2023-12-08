/**
 * @file vec.h 
 * @author Steph
 * @date 12.07.23
 * @version 1.0
 * 
 * Class that emulates std::vector
 * 
*/
#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <initializer_list>

template<typename T>
class vec {
    public:

    /**
     * Default vec constructor
    */
    vec() { }
    
    /**
     * Constructs a vector from an initializer list
     * 
     * @param init_list Initializer list to create vector from
    */
    vec(std::initializer_list<T> init_list) {
        for (const auto& val : init_list) {
            this->push_back(val);
        }
    }

    /**
     * Constructs a vector given a starting size_
     * 
     * @param size_ The size_ of the vector to be created
    */
    vec(std::size_t new_size) {
        this->size_ = new_size;
        this->cap_ = new_size * 2;
        arr_ = new T[this->cap_];
    }

    /**
     * Constructs a vector given a starting size_ and value for ecah elememt
     * 
     * @param size_ The size_ of the vector to be created
     * @param val The value of each element of the vector
    */
    vec(std::size_t new_size, const T& val) {
        this->size_ = new_size;
        this->cap_ = new_size * 2;
        arr_ = new T[this->cap_];
        for (std::size_t i = 0; i < this->size_; i++) {
            this->arr_[i] = val;
        }
    }

    /**
     * Constructs a vector from anthat vector
     * 
     * @param that 
    */
    vec(const vec& that) {
        this->size_ = that.size_;
        this->cap_ = that.cap_;
        for (std::size_t i = 0; i < this->size_; i++) {
            this->arr_[i] = that.arr_[i];
        }
    }

    // Input iterator constructor

    /**
     * Vector distructor
    */
    ~vec() {
        delete[] this->arr_;
    }

    /**
     * Requests that the vector capacity be at least enough 
     * to contain 'new_cap' elements
     * 
     * @param new_cap The new capacity of the vector
    */
    void reserve(std::size_t new_cap) { 
        // Insures the new capacity is greater than the current 
        // allocated capacity, if not, the function does nothing
        if (new_cap > this->cap_) {
            T *new_arr = new T[new_cap];
            for (std::size_t i = 0; i < this->size_; i++) {
                new_arr[i] = this->arr_[i];
            }
            delete[] this->arr_;
            this->cap_ = new_cap;
            this->arr_ = new_arr;
        }
    }

    /**
     * Returns an iterator to the beginning
    */
    // T& begin() {
    //     this->throw_empty_err();
    //     return this->arr_;
    // }

    /**
     * Returns an iterator to the end
    */
    // T& end() const {
    //     this->throw_empty_err();
    //     return this->arr_ + this->size_;
    // }

    // Reverse iterator begin 

    // Reverse iterator end

    /**
     * Returns the number of elements in the vector
     * 
     * @return Returns the number of elements in the vector
    */
    std::size_t size() const { return this->size_; }

    void resize(std::size_t new_size);

    /**
     * Returns the size of allocated storage capacity
     * 
     * @return Returns the size of allocated storage capacity
    */
    std::size_t capacity() const { return this->cap_; }

    /**
     * Is the vector empty (if the size() is zero)
     * 
     * @return true if the vector is empty
    */
    bool empty() const { return this->size_ == 0; }

    /**
     * Returns a reference to the element at position 'index' 
     * in the vector. The function does not bounds check, 
     * if bounds checking is required, .at() should be used
     * 
     * @param index Position of an element in the vector
     * @return Access to an element at an index
    */
    T& operator[](std::size_t index) { return this->arr_[index]; }

    /**
     * Returns a reference to the element at position 'index' 
     * in the vector. The function automatically checks whether 'index' 
     * is within the bounds of valid elements in the vector, 
     * throwing an out_of_range exception if it is not
     * 
     * @param index Position of an element in the vector
     * @return Access to an element at an index
    */
    T& at(std::size_t index) {
        if (index < 0 || index >= this-> size_) {
            throw std::out_of_range("Index out of range");
        }
        return this->arr_[index];
    }

    /**
     * Access the first element of the vector, or the
     * element at index zero
     * 
     * @return access to the first element
    */
    T& front() const {
        if (this->size_ == 0) {
            throw std::domain_error("Vector is empty");
        }
        return this->arr_[0];
    }

    /**
     * Access the last element of the vector, or the 
     * element at size() - 1
     * 
     * @return access to the first element
    */
    T& back() const {
        if (this->size_ == 0) {
            throw std::domain_error("Vector is empty");
        }
        return this->arr_[this->size_ - 1];
    }
    // FIXME????

    // Data?

    /**
     * Adds an element to the back of the vector
     * 
     * @param val The value to append
    */
    void push_back(const T& val) {
        if (this->size_ >= this->cap_) {
            this->reserve(this->cap_ * 2);
        }
        this->arr_[this->size_] = val;
        this->size_++;
    }

    /**
     * Removes the last element of the vector
    */
    void pop_back() {
        if (this->size_ == 0) {
            throw std::domain_error("Vector is empty");
        }
        this->size_--;
    }

    // Insert 

    // erase 

    // swap
    
    /**
     * Removes all elements from the vector (which are distroyed)
     * leaving the vector with a size of zero
    */
    void clear() {
        delete[] this->arr_;
        this->size_ = 0;
        this->cap_ = 2;
    }

    /**
     * Replaces the contents of this vector with a copy of each element 
     * in 'that', in the same order.
     * 
     * @param that the vec from which to copy
   */
    vec& operator=(const vec<T>& that) {
        this->clear();
        for (std::size_t i = 0; i < this->size_; i++) {
            this->push_back(that.arr_[i]);
        }
        return *this;
    }

    /**
     * Replaces the contents of this vector with a copy of each element 
     * in 'init_list', in the same order.
     * 
     * @param init_list the std::initializer_list from which to copy
   */
    vec& operator=(std::initializer_list<T> init_list) {
        this->clear();
        for (const auto& val : init_list) {
            this->push_back(val);
        }
        return *this;
    }

    /**
     * Compares this vector with 'that' for inequality.
     * 
     * @return whether the two vectors do not contain the same number of 
     * elements, with the same values, in the same order
   */
    bool operator!=(const vec<T>& that) const {
        // If the sizes are different, the vectors are not equal
        if (this->size_ != that.size_) return true;
        // If the sizes are the same, iterate to find if there are any differences
        for (std::size_t i = 0; i < this->size_; i++) {
            if (this->arr_[i] != that.arr_[i]) return true;
        }
        return false;
    }

    /**
     * Compares this vector with another for equality.
     * 
     * @return whether the two vectors contain the same number of 
     * elements, with the same values, in the same order
   */
    bool operator==(const vec<T>& that) const {
        // If the sizes are different, the vectors are not equal
        if (this->size_ != that.size_) return false;
        // If the sizes are the same, iterate to find if there are any differences
        for (std::size_t i = 0; i < this->size_; i++) {
            if (this->arr_[i] != that.arr_[i]) return false;
        }
        return true;
    }

    /**
     * Inserts this vector into an ostream, with the format [element1, element2, element3, ...].
     * 
     * @param out	ostream object where the list is inserted
     * @param vector the list object to insert
   */
    friend std::ostream& operator<<(std::ostream& out, const vec<T>& vector) {
        out << "[";
        for (std::size_t i = 0; i < vector.size_; i++) {
            out << vector.arr_[i];
            // Add commas after there element if not the last one
            if (i < vector.size_ - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    // Sorts the vector using merge sort 
    void sort();

    /**
     * Returns the index of the first occurance of 'val' in the vector
     * 
     * @param val The item to search for 
     * @return The index of the first occurance of 'val', if not found returns -1
     */
    std::size_t search(const T& val) const {
        for (std::size_t i = 0; i < this->size_; i++) {
            if (this->arr_[i] == val) return i;
        }
        return -1;
    } 

    /**
     * Returns the number of occurance of 'val' in the vector
     * 
     * @param val The item to count
     * @return The number of times 'val' occurs in the vector
    */
    std::size_t count(const T& val) const {
        std::size_t counter = 0;
        for (std::size_t i = 0; i < this->size_; i++) {
            if (this->arr_[i] == val) counter++;
        }
        return counter;
    }

    /**
     * Finds the minimum value in the vector
     * 
     * @return The minimum value in the vector
    */
    T min() const {
        if (this->size_ == 0) {
            throw std::domain_error("Vector is empty");
        }
        T minimum = this->arr_[0];
        for (std::size_t i = 1; i < this->size_; i++) {
            if (this->arr_[i] < minimum) {
                minimum = this->arr_[i];
            }
        }
        return minimum;
    }

    /**
     * Finds the maximum value in the vector 
     * 
     * @return The maximum value in the vector
    */
    T max() const {
        if (this->size_ == 0) {
            throw std::domain_error("Vector is empty");
        }
        T maximum = this->arr_[0];
        for (std::size_t i = 1; i < this->size_; i++) {
            if (this->arr_[i] > maximum) {
                maximum = this->arr_[i];
            }
        }
        return maximum;
    }

    /**
     * Modifies the vector to contain no duplicate elements
    */
    void unique();


    private:
    std::size_t size_ = 0; // The current size_ occupied by data
    std::size_t cap_ = 2; // The cap_acity of the array before needing realocation
    T *arr_ = new T[this->cap_];; // An array of type T
};

# endif
