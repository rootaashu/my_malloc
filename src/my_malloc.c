#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE sizeof(Block)



typedef struct Block{
	size_t size;
	int free ;
	struct Block *next;
}Block;

Block *head = NULL;


void own_free(void *ptr){
	if (!ptr) return;
	Block *block = (Block *)ptr -1;
	block ->free =1;
}

void *heap_start = NULL;

void* own_malloc(size_t size)
{
	Block *block;
	
	block = sbrk(sizeof(Block) + size);

	if (block ==(void*) - 1)
		return NULL;

	block ->size = size;
	block ->free = 0;
	block ->next = NULL;

	if (head == NULL)
		head = block;

	return (void*)(block + 1);

}

int own_free_all()
{
	if(heap_start == NULL)
	{
		return -1;
	}
	return brk(heap_start);
}
int main(){
	
// Experimental code to test heap overwrite behavior 

	/*
	const char* message = "This is my HEAP message\0";
	const size_t message_bytes = strlen(message)*sizeof(char);
	char *memory =(char*) sbrk(message_bytes);

	strcpy(memory, message);
	
	const char* second_message = "Second!\0";
	const size_t second_length = strlen(second_message)*sizeof(char);
	char *second_memory = (char*) sbrk(second_length);
	strcpy(second_memory, second_message);
	brk(memory);
	const char* overwriting_message = "Overwritten\0!";
	const size_t overwriting_length = strlen(overwriting_message)*sizeof(char);
	char *newly_allocated_memory = sbrk(overwriting_length);
	strcpy(newly_allocated_memory, overwriting_message);
*/
	const char *message = "This is my own malloc!";
	size_t size = strlen(message)*sizeof(char);
	char * allocated_memory = own_malloc(size);
	strcpy(allocated_memory, message);
	own_free_all();
}
