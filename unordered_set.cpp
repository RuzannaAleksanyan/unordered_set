#include "unordered_set.h"
#include "iostream"

// Ctor
unordered_set::unordered_set() 
            : m_buckets{7}
{

} 

// Ctor
unordered_set::unordered_set(int init_size) 
            : m_buckets{init_size}
{

}

// Copy constructor
unordered_set::unordered_set(const unordered_set& other) 
            : m_buckets{other.m_buckets}
            , m_const_load_factor{other.m_const_load_factor}
{

}

// Copy assignment operator
unordered_set& unordered_set::operator=(const unordered_set& other) {
    if(this != &other) {
        m_buckets = other.m_buckets;
        m_const_load_factor = other.m_const_load_factor;
    }
    return *this;
}

// Move constructor
unordered_set::unordered_set(unordered_set&& other) 
            : m_buckets{std::move(other.m_buckets)}
            , m_const_load_factor{std::move(other.m_const_load_factor)}
{

} 

// Move assignment operator
unordered_set& unordered_set::operator=(unordered_set&& other) {
    if(this != &other) {
        m_buckets = std::move(other.m_buckets);
        m_const_load_factor = std::move(other.m_const_load_factor);
    }
    return *this;
}

// Dtor
unordered_set::~unordered_set() {
    clear();
}

void unordered_set::insert(const int key) {
    update_load_factor(); 

    int index = hash_function(key);
    if(!contains(key)) {
        m_buckets[index].push_front(key);
    }
}

void unordered_set::remove(const int key) {
    int index = hash_function(key);
    std::forward_list<int>& bucket = m_buckets[index];
    bucket.remove(key);
}

bool unordered_set::contains(const int key) const {
    int index = hash_function(key);

    for(auto& elem : m_buckets[index]) {
        if(elem == key) {
            return true;
        }
    }

    return false;
}

unordered_set::iterator unordered_set::find(const int key) {
    int bucket_index = hash_function(key);
    auto& bucket = m_buckets[bucket_index];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (*it == key) {
            return it; 
        }
    }

    return bucket.end(); 
}

int unordered_set::bucket_count() const {
    return m_buckets.size();
}

int unordered_set::bucket_size(int index) const {
    if(index < 0 || index >= m_buckets.size()) {
        return 0;
    }

    int count = 0;
    for(auto& elem : m_buckets[index]) {
        ++count;
    }
    return count;
}

float unordered_set::const_load_factor() const {
    return m_const_load_factor;
}

float unordered_set::load_factor() const {
    return static_cast<float>(size()) / m_buckets.size();
}

void unordered_set::reserve(int count) {
    int bucket_count = std::max(count, static_cast<int>(count / m_const_load_factor));
    rehash(bucket_count);
}

bool unordered_set::empty() const {
    for(auto& elem : m_buckets) {
        if(!elem.empty()) {
            return false;
        }
    }
    return true;
}

void unordered_set::clear() {
    for(auto& elem : m_buckets) {
        elem.clear();
    }
}

void unordered_set::print() const {
    for (int i = 0; i < m_buckets.size(); ++i) {
        std::cout << "Bucket " << i << ": ";
        for (const auto& elem : m_buckets[i]) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int unordered_set::size() const {
    int count = 0;
    for(auto& bucket : m_buckets) {
        for(auto& elem : bucket) {
            ++count;
        }
    }
    return count;
}

int unordered_set::hash_function(int key) const {
    return key % m_buckets.size();
}

void unordered_set::update_load_factor() {
    if(load_factor() > m_const_load_factor) {
        rehash(m_buckets.size() * 2);
    }
}

void unordered_set::rehash(int count) {
    std::vector<std::forward_list<int>> new_set(count);
    for(const auto& bucket : m_buckets) {
        for(int elem : bucket) {
            int new_index = hash_function(elem) % count;
            new_set[new_index].push_front(elem);
        }
    }
    m_buckets = std::move(new_set);
}
