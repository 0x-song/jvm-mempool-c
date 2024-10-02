#include "../../include/memory/memory_chunk.h"
#include "../../include/common.h"

//申请的字节数并不等于最终申请成功的字节数，还需要考虑对齐的问题
MemoryChunk::MemoryChunk(unsigned int size, char * filename, unsigned int line)
    :m_filename(filename)
    ,m_line(line)
    ,m_size(size)
{
    m_align_size = ALIGN_SIZE;
    //这里面-1主要的目的是考虑到刚好申请16字节，假如对齐也是16字节，那么会造成浪费的情况
    //如果不-1，那么最终会申请32字节；-1最终申请16字节；
    m_cell_num = ((size - 1) / m_align_size) + 1;
    m_size = m_align_size * m_cell_num;
    this->m_data = calloc(m_size, sizeof(unsigned char));
    if(NULL == m_data) {
        printf("分配内存失败");
        exit(-1);
    }
}

MemoryChunk::~MemoryChunk() {
    printf("[调用析构函数%s]释放资源\n", __func__);
    if (m_data) {
        printf("\t 释放资源, 申请内存位置( %s:%d )，内存大小:%d 字节\n", m_filename, m_line, m_size);

        free(m_data);
    }
}

char * MemoryChunk::get_filename() {
    return this->m_filename;
}

unsigned int MemoryChunk::get_line() {
    return this->m_line;
}

unsigned int MemoryChunk::get_size() {
    return this->m_size;
}

void * MemoryChunk::get_data() {
    return this->m_data;
}

unsigned int MemoryChunk::get_align_size() {
    return this->m_align_size;
}

unsigned int MemoryChunk::get_cell_num() {
    return this->m_cell_num;
}
