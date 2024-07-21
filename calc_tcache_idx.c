#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/*
We emulate the structure of MallocChunk
*/

struct malloc_chunk{
	size_t prev_size;
    size_t size;

    struct malloc_chunk* fd;
    struct malloc_chunk* bk;

    struct malloc_chunk* fd_nextsize;
    struct malloc_chunk* bk_nextsize;
};

/*
some macro define
 */

#define SIZE_SZ (sizeof(size_t))

#define MALLOC_ALIGNMENT (2 * SIZE_SZ < __alignof__ (long double) \
			  ? __alignof__ (long double) : 2 * SIZE_SZ)

#define MALLOC_ALIGN_MASK (MALLOC_ALIGNMENT - 1)

#define MIN_CHUNK_SIZE        (offsetof(struct malloc_chunk, fd_nextsize))

#define MINSIZE  \
  (unsigned long)(((MIN_CHUNK_SIZE+MALLOC_ALIGN_MASK) & ~MALLOC_ALIGN_MASK))

#define request2size(req)                                         \
  (((req) + SIZE_SZ + MALLOC_ALIGN_MASK < MINSIZE)  ?             \
   MINSIZE :                                                      \
   ((req) + SIZE_SZ + MALLOC_ALIGN_MASK) & ~MALLOC_ALIGN_MASK)

# define csize2tidx(x) (((x) - MINSIZE + MALLOC_ALIGNMENT - 1) / MALLOC_ALIGNMENT)

# define usize2tidx(x) csize2tidx (request2size (x))

int main(){

}