#include <iostream>
#include <map>
#include <list>

using namespace std;

class LruMap
{
    private:
        int capacity;
        map<int, int> cache;
        list<int> lru_ordered_list;
        
    public:
        LruMap(int c) : capacity(c) {}

        void put(int k, int v)
        {
            // If value is in cache
            if (cache.find(k) != cache.end())
            {
                move_as_most_recently_used(k);
            }
            else
            {
                if (cache.size() == capacity)
                {
                    remove_least_recently_used();
                }

                // Insert key to the back of LRU
                lru_ordered_list.push_back(k);
            }
            
            cache[k] = v; // Put/Update the value in cache
        }

        int get(int k)
        {
            if (cache.find(k) != cache.end())
            {
                move_as_most_recently_used(k);
                return cache[k];
            }
            return -1;
        }

        void print()
        {
            int i = 0;
            cout << "[";
            for (list<int>::iterator it = lru_ordered_list.begin(); it != lru_ordered_list.end(); ++it, ++i)
            {
                if (i)
                    cout << ",";
                cout << *it;
            }
            cout << "]" << endl;
        }

    private:
        void move_as_most_recently_used(int k)
        {
            lru_ordered_list.remove(k);
            lru_ordered_list.push_back(k);
        }

        void remove_least_recently_used()
        {
            cache.erase(lru_ordered_list.front());
            lru_ordered_list.pop_front();
        }
};

int main()
{
    int capacity, num_ops;
    int k, v;
    int n = 1;
    string op;
    while (cin >> capacity)
    {
        cin >> num_ops;
        LruMap map(capacity);
        cout << "CASE " << n++ << ":" << endl;

        while (num_ops--)
        {
            cin >> op;

            if (op == "put")
            {
                cin >> k >> v;
                map.put(k, v);
            }
            else if (op == "get")
            {
                cin >> k;
                cout << "=" << map.get(k) << endl;
            }
            else
            {
                map.print();
            }
        }
        cout << endl;
    }

    return 0;
}