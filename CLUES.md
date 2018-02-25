Ideal implementation for LRU Map is a doubly linked list paired with a hash map. Doubly linked list allows insertion and deletion in constant time while hash map allows access of values in constant time, as well.

In C++, doubly linked list via `list` allows O(1) deletion if you know the iterator through the `erase(iterator)` method. In `faster.cpp`, another hash map is added to keep track of the iterators and allow O(1) deletion. In `slower.cpp`, iterators are not stored. Instead, `remove(value)` was used. It runs in O(n) since all elements equal to the passed `value` are deleted.

For clarifications, feel free contact me through Facebook

- Gali Armero

## Pseudo code

### put
```
put(k):
    if k in cache:
        update its position to most recently used
        insert and store k
    else:
        if cache is full:
            remove oldest/LRU entry
        insert and store k
```

### get
```
get(k):
    if k in cache:
        update its position to most recently used
    
    return k
```

### print
Prints the cache from most recently used to least recently used.