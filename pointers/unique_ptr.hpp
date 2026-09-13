#pragma once

template <typename T>
class UniquePtr {
private:
    T* ptr;
public:
    UniquePtr(T* p = nullptr) : ptr(p) {}
    ~UniquePtr() { delete ptr; }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }

    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }
};

template <typename T>
class UniquePtrArr {
private:
    T* ptr;
public:
    UniquePtrArr(T* p = nullptr) : ptr(p) {}
    ~UniquePtrArr() { delete[] ptr; }

    UniquePtrArr(const UniquePtrArr&) = delete;
    UniquePtrArr& operator=(const UniquePtrArr&) = delete;

    UniquePtrArr(UniquePtrArr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    UniquePtrArr& operator=(UniquePtrArr&& other) noexcept {
        if (this != &other) {
            delete[] ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator[](size_t idx) const {return ptr[idx];}

    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete[] ptr;
            ptr = p;
        }
    }
};