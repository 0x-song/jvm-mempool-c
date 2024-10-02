//
// Created by song on 24-10-1.
//

#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H
#include <list>
using namespace std;
#include "memory_chunk.h"

class MemoryPool {

    //所有需要释放的内存
private:
    list<MemoryChunk *> m_chunks;

    //析构函数需要做一些处理
public:
    ~MemoryPool();

    MemoryChunk *alloc_chunk(unsigned int memory_size);

    //打印所有的chunk
    void print_chunks();

    void free_chunks();
};

#endif //MEMORY_POOL_H
