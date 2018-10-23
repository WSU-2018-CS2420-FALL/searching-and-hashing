#ifndef _LINEAR_HASHTABLE_H
#define _LINEAR_HASHTABLE_H

template <typename T>
struct Cell {
    T key;
    bool empty = true;
};

template <typename T>
class LinearHashtable {
public:
    LinearHashtable(unsigned capacity = 499): sz(0), capacity(capacity),
    htable(new Cell<T>[capacity]()) {}
    LinearHashtable(const LinearHashtable<T>& t)= delete;
    LinearHashtable<T>& operator=(const LinearHashtable<T>& t)= delete;

    bool add(T e){
        if(sz == capacity) return false;

        unsigned t = hashCode(e);
        if(htable[t].empty){
            htable[t] = {e, false}; 
        }else{
            unsigned i = 1;
            while(!htable[(t + i) % capacity].empty) i++;
            htable[(t+i) % capacity] = {e, false};
        }
        sz++;
        return true;
    }

    bool remove(T e){
        if(sz == 0) return false;

        unsigned t = hashCode(e);
        if(htable[t].key == e){
            htable[t].empty = true;
            sz--;
            return true; 
        }else{
            unsigned i = 1;
            while(i < capacity){
                if( htable[(t+i) % capacity].key == e){
                    htable[(t+i) % capacity].empty = true;
                    sz--;
                    return true; 
                }
                i++;
            }
            
        }

        return false;
    }

    bool contains(T e) const {
        if(sz == 0) return false;

        unsigned t = hashCode(e);
        if(htable[t].key == e){
            return true; 
        }else{
            unsigned i = 1;
            while(i < capacity){
                if( htable[(t+i) % capacity].key == e){
                    return true; 
                }
                i++;
            }
            
        }

        return false;
    }
    ~LinearHashtable(){ delete[] htable; }
private:
    unsigned capacity;
    unsigned sz;
    Cell<T>* htable;

    unsigned hashCode(T k){
        return k % capacity;
    }
};
#endif