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
    class Iterator;
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
            this->arr_ = new T[this->cap_];
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

        /**
         * Constructs a vector with as many elements as the range [first,last), with
         * each element constructed from its corresponding element in 
         * that range, in the same order.
         * 
         * @param first Iterator to start from (inclusive)
         * @param last Iterator to end with (exclusive/past the end)
         */
        template <typename InputIterator>
        vec(InputIterator first, InputIterator last) {
            for (; first != last; ++first) this->push_back(*first);
        }

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

        /**
         * Resizes the vector so that it contains 'new_size' elements.
         *  
         * @param new_size the new size for the vector
         */
        void resize(std::size_t new_size) {
            T val; 
            while (this->size_ > new_size) {
                this->pop_back();
            }
            while(this->size_ < new_size) {
                this->push_back(val);
            }
        }

        /**
         * Resizes the vector so that it contains 'new_size' elements.
         * 
         * @param new_size The new size for the vector
         * @param fill_value The value to place in any new elements
         */
        void resize(std::size_t new_size, const T& fill_value) {
            while (this->size_ > new_size) {
                this->pop_back();
            }
            while (this->size_ < new_size) {
                this->push_back(fill_value);
            }
        }

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
        
        /**
         * Removes all elements from the vector (which are distroyed)
         * leaving the vector with a size of zero
        */
        void clear() {
            delete[] this->arr_;
            this->size_ = 0;
            this->cap_ = 2;
            this->arr_ = new T[this->cap_];
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
         * @param out ostream object where the list is inserted
         * @param vector Tkhe list object to insert
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

        // Sorts the vector using merge sort 
        void sort();

        /**
         * Modifies the vector to contain no duplicate elements
        */
        void unique();

        /**
         * Removes from the container all the elements that compare equal to 'val'.
         * 
         * @param val Value of the elements to be removed
         */
        // TODO FIX THIS
        void remove(const T& val) {
            int count = 0;
            for (int i = 0; i < this->size_ - 1; i++) {
                if (this->arr_[i] == val) {
                    this->arr_[i] = this->arr_[i + 1];
                    count++, i--;
                }
            }   
            this->resize(this->size_ - count);   
        }

        /**
         * Removes from the container an element at an index
         * 
         * @param index Index of the element to be removed
         */
        void erase(const int& index) {
            for (int i = index; i < this->size_ - 1; i++) {
                this->arr_[i] = this->arr_[i + 1];
            }
            this->pop_back();
        }

    // https://www.google.com/search?channel=fs&client=ubuntu-sn&q=iterator+cpp 
    // class Iterator {
    // public:
    //     using iterator_category = std::random_access_iterator_tag;
    //     using value_type = T;
    //     using difference_type = std::ptrdiff_t;
    //     using pointer = T*;
    //     using reference = T&;

    //     // Default constructor
    //     Iterator() {}

    //     // Copy constructor
    //     Iterator(const Iterator& other) : cur(other.cur) {}

    //     // Overloaded constructor
    //     Iterator(Node* cur_node, Node* cur_tail) {
    //     this->cur = cur_node;
    //     this->tail = cur_tail;
    //     }

    //     // Assignment
    //     Iterator& operator=(const Iterator& that) {
    //     this->cur = that.cur;
    //     this->tail = that.tail;
    //     return *this;
    //     }

    //     // Prefix increment
    //     Iterator& operator++() {
    //     this->cur = this->cur->next;
    //     return *this;
    //     }

    //     // Postfix increment
    //     Iterator operator++(int) {
    //     Iterator tmp(*this);
    //     this->operator++();
    //     return tmp;
    //     }

    //     // Prefix decrement
    //     Iterator& operator--() {
    //     if (this->cur == nullptr) {
    //         this->cur = this->tail;
    //     } else {
    //         this->cur = this->cur->prev;
    //     }
    //     return *this;
    //     }

    //     // Postfix decrement
    //     Iterator operator--(int) {
    //     Iterator tmp(*this);
    //     this->operator--();
    //     return tmp;
    //     }

    //     // Inequality
    //     bool operator!=(Iterator that) const { return !(this->operator==(that)); }

    //     // Equality
    //     bool operator==(Iterator that) const { return this->cur == that.cur; }

    //     // lvalue dereference
    //     T& operator*() const { return this->cur->data; }

    //     // referring
    //     Iterator* operator->() { return this; }

    //     // Getter for cur
    //     Node* get_cur() { return this->cur; }

    // private:
    //     const vec<T> *vector_;
    //     int index;
    // };

    private:
        std::size_t size_ = 0; // The current size_ occupied by data
        std::size_t cap_ = 2; // The cap_acity of the array before needing realocation
        T *arr_ = new T[this->cap_];; // An array of type T
};

# endif
