#include <stdio.h>
#include "serial.h"
#include "memory.h"

static void *kmalloc(int size)
{
	char *p = (char *)memman_alloc_4k(MEMMAN_ADDR,size+4);
	*((int *)p) = size+4;
	return p + 4;
}

static void kfree(void *ptr)
{
	char *p = (char *)ptr;
	p = p - 4;
	memman_free_4k(MEMMAN_ADDR,p,*((int *)p));
}

size_t __write(FILE* instance, const char *bp, size_t n);
size_t __read(FILE* instance, char *bp, size_t n);
int __close(FILE* instance);
int __seek(FILE* instance, size_t offset, int base);
long __tell(FILE* instance);
int __eof(FILE* instance);

struct File_methods mth = {
	.write = __write,
	.read = __read,
	.close = __close,
	.seek = __seek,
	.tell = __tell,
	.eof = __eof,
};

FILE const __stdin = {
	(void *)1, &mth
};

FILE const __stdout = {
	(void *)2, &mth
};

FILE const __stderr = {
	(void *)2, &mth
};

FILE* const stdin = &__stdin;
FILE* const stdout = &__stdout;
FILE* const stderr = &__stderr;

FILE *__open(char *path, char *mode)
{
	/*FILE *f = (FILE *)malloc(sizeof(FILE));
	
	BYTE m = 0;
	if(strchr(mode,'r')) m |= FA_READ;
	if(strchr(mode,'w')) m |= FA_WRITE;
	
	//printk("%02x\n",m);
	
	f->obj = (FIL *)malloc(sizeof(FIL));
	
	f->vmt = &mth;
	
	f_open((FIL *)f->obj,path,m);
	
	return f;*/
	return NULL;
}

size_t __write(FILE* instance, const char *bp, size_t n)
{
	//struct TASK *task = task_now();
	int i;
	switch((int)instance->obj) {
	case 1:
		//for(i = 0; i < n; i++) fifo32_put(&(task->fifo),bp[i]);
		return i;
	case 2:
		uart_puts_with_len(bp, n);
		return n;
	}
	
	//UINT bw;
	//f_write((FIL *)instance->obj, bp, n, &bw);
	
	return 0;
}

size_t __read(FILE* instance, char *bp, size_t n)
{
	//struct TASK *task = task_now();
	int i;
	switch((int)instance->obj) {
	case 1:
		//for(i = 0; i < n && fifo32_status(&(task->fifo)); i++) bp[i] = fifo32_get(&(task->fifo));
		return i;
	case 2:
		return 0;
	}
	
	//UINT br;
	//f_read((FIL *)instance->obj, bp, n, &br);
	
	return 0;
}

int __close(FILE* instance)
{
	switch((int)instance->obj) {
	case 1:
		return -1;
	case 2:
		return -1;
	}
	
	return -1;//f_close(instance->obj);
}

int __seek(FILE* instance, size_t offset, int base)
{
	switch((int)instance->obj) {
	case 1:
		return -1;
	case 2:
		return -1;
	}
	
	int fofs = offset;
	
	/*switch(base) {
	case SEEK_CUR:
		fofs = f_tell((FIL *)instance->obj) + offset;
		break;
	case SEEK_END:
		fofs = f_size((FIL *)instance->obj) - offset;
		break;
	}*/
	
	//printk("SEEK %d:%d (%d)\n", base, offset, fofs);
	
	return -1;//f_lseek((FIL *)instance->obj, fofs);
}

long __tell(FILE* instance)
{
	switch((int)instance->obj) {
	case 1:
		return -1;
	case 2:
		return -1;
	}
	
	return -1;//f_tell((FIL *)instance->obj);
}

int __eof(FILE *instance)
{
	return 0;//f_eof((FIL *)instance->obj);
}

void *__malloc(size_t siz)
{
	return kmalloc(siz);
}

void __free(void *ptr)
{
	kfree(ptr);
}

void __assert_fail(const char *s, const char *f, unsigned int l)
{
	printf("ASSERT FAILED %s : %s:%d\n",s,f,l);
	for(;;);
}
