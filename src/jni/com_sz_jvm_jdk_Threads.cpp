#include "../../include/jni/com_sz_jvm_jdk_Threads.h"
#include "../../include/memory/memory_pool.h"

//内存模型的管理器
MemoryPool * global_memory = NULL;

//新生代
MemoryChunk * new_generation = NULL;
//老年代
MemoryChunk * old_generation = NULL;


JNIEXPORT void JNICALL Java_com_sz_jvm_jdk_Threads_createVM
  (JNIEnv *, jclass){
    global_memory = new MemoryPool();
    new_generation = global_memory->alloc_chunk(80);
    old_generation = global_memory->alloc_chunk(160);
  }
