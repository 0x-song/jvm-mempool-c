//
// Created by song on 24-10-1.
//
#include "../../include/memory/memory_pool.h"
#include <stdio.h>
#include "../../include/memory/memory_chunk.h"

MemoryPool::~MemoryPool() {
    //_FUNCTION _func表示获取正在执行的方法的名称
    printf("%s\n", __FUNCTION__);
}

MemoryChunk * MemoryPool::alloc_chunk(unsigned int memory_size) {
    MemoryChunk * chunk = new MemoryChunk(memory_size, __FILE__, __LINE__);
    this->m_chunks.push_front(chunk);
    return chunk;
}

//打印所有的chunk
void MemoryPool::print_chunks() {
    printf("[打印未释放的内存信息]\n");
    list<MemoryChunk *>::iterator iterator;
    for (iterator = this->m_chunks.begin(); iterator != this->m_chunks.end(); iterator++) {
        MemoryChunk * chunk = *iterator;
        printf("[未释放的内存]申请位置:(%s, %d),内存大小:%d 字节\n",
            chunk->get_filename(), chunk->get_line(), chunk->get_size());
    }
}

void MemoryPool::free_chunks() {
    list<MemoryChunk *>::iterator iterator;
    for (iterator = this->m_chunks.begin(); iterator != this->m_chunks.end(); iterator++) {
        MemoryChunk * chunk = *iterator;
        delete chunk;
    }
    //清空list
    this->m_chunks.clear();
}