#ifndef HASH_SET
#define HASH_SET

#include <vector>
#include <forward_list>

class unordered_set {
private:
    std::vector<std::forward_list<int>> m_buckets; 
    float m_const_load_factor = 0.7; 

    int hash_function(int key) const; 
    void update_load_factor(); 
    void rehash(int count); 

public:
    using iterator = std::forward_list<int>::iterator;

    unordered_set(); // Default constructor
    explicit unordered_set(int init_size); // Constructor with initial size
    unordered_set(const unordered_set& other); // Copy constructor
    unordered_set& operator=(const unordered_set& other); // Copy assignment operator
    unordered_set(unordered_set&& other); // Move constructor
    unordered_set& operator=(unordered_set&& other); // Move assignment operator
    ~unordered_set(); // Destructor

    // Element manipulation
    void insert(const int key); 
    void remove(const int key); 
    bool contains(const int key) const;
    iterator find(const int key);

    // Bucket interface
    int bucket_count() const;
    int bucket_size(int index) const;

    // Hash policy
    float const_load_factor() const;
    float load_factor() const;
    void reserve(int count); 

    // Information about the hash set
    bool empty() const;
    void clear(); 
    void print() const; 
    int size() const; 
};

#endif
