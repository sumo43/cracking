from queue import Queue
class LRU_Cache:
    maxsize = None
    queue = Queue()
    hashtable = dict()
    def __init__(self, maxsize):
        self.maxsize = maxsize
        self.size = 0
    def put(self, key, value): 
        if self.size == self.maxsize:
            old_key = self.queue.get()
            self.hashtable.pop(old_key, None)
            self.queue.put(key)
            self.hashtable[key] = value
            self.size = 1
        else:
            self.queue.put(key)
            self.hashtable[key] = value
            self.size += 1
    def get(self, key):
        return self.hashtable[key]

if __name__ == "__main__":
    cache = LRU_Cache(2)
    cache.put('one', 'test1')
    cache.put('two', 'test2')
    cache.put('three', 'test3')
    print(cache.get('two'))
        
    

