#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <memory>

template <typename T>
class Vector {
public:
    // Member types
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    // Constructors
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    explicit Vector(size_type count) {
        data_ = new T[count]();
        size_ = count;
        capacity_ = count;
    }

    Vector(size_type count, const T& value) {
        data_ = new T[count];
        size_ = count;
        capacity_ = count;
        std::fill_n(data_, count, value);
    }

    Vector(std::initializer_list<T> init) : Vector(init.size()) {
        std::copy(init.begin(), init.end(), data_);
    }

    Vector(const Vector& other) : Vector(other.size_) {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    Vector(Vector&& other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // Destructor
    ~Vector() {
        delete[] data_;
    }

    // Assignment operators
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            Vector temp(other);
            swap(temp);
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    Vector& operator=(std::initializer_list<T> init) {
        Vector temp(init);
        swap(temp);
        return *this;
    }

    // Element access
    reference at(size_type pos) {
        if (pos >= size_) throw std::out_of_range("Vector::at");
        return data_[pos];
    }

    const_reference at(size_type pos) const {
        if (pos >= size_) throw std::out_of_range("Vector::at");
        return data_[pos];
    }

    reference operator[](size_type pos) {
        return data_[pos];
    }

    const_reference operator[](size_type pos) const {
        return data_[pos];
    }

    reference front() {
        return data_[0];
    }

    const_reference front() const {
        return data_[0];
    }

    reference back() {
        return data_[size_ - 1];
    }

    const_reference back() const {
        return data_[size_ - 1];
    }

    T* data() noexcept {
        return data_;
    }

    const T* data() const noexcept {
        return data_;
    }

    // Iterators
    iterator begin() noexcept {
        return data_;
    }

    const_iterator begin() const noexcept {
        return data_;
    }

    const_iterator cbegin() const noexcept {
        return data_;
    }

    iterator end() noexcept {
        return data_ + size_;
    }

    const_iterator end() const noexcept {
        return data_ + size_;
    }

    const_iterator cend() const noexcept {
        return data_ + size_;
    }

    // Capacity
    bool empty() const noexcept {
        return size_ == 0;
    }

    size_type size() const noexcept {
        return size_;
    }

    size_type max_size() const noexcept {
        return std::numeric_limits<size_type>::max();
    }

    void reserve(size_type new_cap) {
        if (new_cap > capacity_) {
            T* new_data = new T[new_cap];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
            capacity_ = new_cap;
        }
    }

    size_type capacity() const noexcept {
        return capacity_;
    }

    void shrink_to_fit() {
        if (capacity_ > size_) {
            T* new_data = new T[size_];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
            capacity_ = size_;
        }
    }

    // Modifiers
    void clear() noexcept {
        size_ = 0;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) reserve(capacity_ > 0 ? 2 * capacity_ : 1);
        data_[size_++] = value;
    }

    void push_back(T&& value) {
        if (size_ == capacity_) reserve(capacity_ > 0 ? 2 * capacity_ : 1);
        data_[size_++] = std::move(value);
    }

    void pop_back() {
        if (size_ > 0) --size_;
    }

    iterator insert(const_iterator pos, const T& value) {
        size_type index = pos - data_;
        if (size_ == capacity_) reserve(capacity_ > 0 ? 2 * capacity_ : 1);
        for (size_type i = size_; i > index; --i) {
            data_[i] = data_[i - 1];
        }
        data_[index] = value;
        ++size_;
        return data_ + index;
    }

    iterator insert(const_iterator pos, T&& value) {
        size_type index = pos - data_;
        if (size_ == capacity_) reserve(capacity_ > 0 ? 2 * capacity_ : 1);
        for (size_type i = size_; i > index; --i) {
            data_[i] = data_[i - 1];
        }
        data_[index] = std::move(value);
        ++size_;
        return data_ + index;
    }

    iterator erase(const_iterator pos) {
        size_type index = pos - data_;
        for (size_type i = index; i < size_ - 1; ++i) {
            data_[i] = std::move(data_[i + 1]);
        }
        --size_;
        return data_ + index;
    }

    iterator erase(const_iterator first, const_iterator last) {
        size_type start_index = first - data_;
        size_type end_index = last - data_;
        size_type count = end_index - start_index;
        for (size_type i = start_index; i < size_ - count; ++i) {
            data_[i] = std::move(data_[i + count]);
        }
        size_ -= count;
        return data_ + start_index;
    }

    void resize(size_type count, T value = T()) {
        if (count > size_) {
            reserve(count);
            std::fill(data_ + size_, data_ + count, value);
        }
        size_ = count;
    }

    void swap(Vector& other) noexcept {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

private:
    T* data_;
    size_type size_;
    size_type capacity_;
};

// Non-member functions
template <typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
    return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vector<T>& lhs, const Vector<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(rhs < lhs);
}

template <typename T>
bool operator>(const Vector<T>& lhs, const Vector<T>& rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs < rhs);
}

template <typename T>
void swap(Vector<T>& lhs, Vector<T>& rhs) noexcept {
    lhs.swap(rhs);
}

#endif
