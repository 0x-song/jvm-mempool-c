//
// Created by song on 24-10-1.
//

#ifndef MEMORY_CHUNK_H
#define MEMORY_CHUNK_H

class MemoryChunk {

private:
    /**
     * 创建Chunk的文件名
     */
    char *m_filename;

    /**
     * 创建Chunk的文件位置
     */
    unsigned int m_line;

    /**
     * 该Chunk的内存大小
     */
    unsigned int m_size;

    /**
     * 以多少字节对齐
     */
    unsigned int m_align_size;

    /**
     * 该Chunk包含多少Cell
     */
    unsigned int m_cell_num;

    /**
     * 被用了的Cell数量
     */
    unsigned int m_used_cell_num;

    /**
     * 当前Cell的起始位置
     *      复制算法用
     */
    unsigned int m_cell_start;

   /**
    * 存储数据的地方
    */
    void * m_data;

public:
    MemoryChunk(unsigned int size, char * filename, unsigned int line);

    ~MemoryChunk();

    char *get_filename();
    unsigned int get_line();
    unsigned int get_size();
    void * get_data();
    unsigned int get_align_size();
    unsigned int get_cell_num();

};

#endif //MEMORY_CHUNK_H
