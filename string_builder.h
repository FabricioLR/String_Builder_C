#ifndef STRING_BUILDER_H_
#define STRING_BUILDER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEFAULT_SIZE 10

struct StringBuilder {
	char *buffer;
	int length;
	int max_size;
};
typedef struct StringBuilder StringBuilder;

char *toString(StringBuilder *sb){
	sb->buffer[sb->length] = '\0';
	return sb->buffer;
}

int indexOf(StringBuilder *sb, char *string){
	int length = strlen(string);

	for (int i = 0; i < sb->length; i++){
		if (i + length >= sb->length) break;
		int count = 0;
		for (int j = 0; j < length; j++){
			if (sb->buffer[i + j] == string[j]) count++;
		}
		if (count == length) return i;
	}

	return -1;
}

char *substring(StringBuilder *sb, int start, int end){
	assert(start >= 0);
	assert(end >= start);
	assert(end < sb->length);

	char *buffer = (char *)malloc(end - start);

	int j = 0;
	for (int i = start; i < end; i++){
		buffer[j] = sb->buffer[i];
		j++;
	}

	return buffer;
}

char *reverse(StringBuilder *sb){
	char *buffer = (char *)malloc(sb->length);
	assert(buffer != NULL);

	strcpy(buffer, sb->buffer);

	for (int i = 0; i < sb->length / 2; i++){
		char temp = buffer[sb->length - 1 - i];
		buffer[sb->length - 1 - i] = sb->buffer[i];
		buffer[i] = temp;
	}

	return buffer;
}

void delete(StringBuilder *sb, int start, int end){
	assert(start >= 0);
	assert(end >= start);
	assert(end < sb->length);

	int length = end - start;

	char *buffer = (char *)malloc(sb->length - end);
	assert(buffer != NULL);

	int j = 0;
	for (int i = end; i < sb->length; i++){
		buffer[j] = sb->buffer[i];
		j++;
	}

	for (int i = 0; i < sb->length - end; i++){
		sb->buffer[start++] = buffer[i];
	}

	sb->length -= length;
}

void append(StringBuilder *sb, char *string){
	int length = strlen(string);

	if (sb->length + length > sb->max_size){
		if (((sb->length + length) % DEFAULT_SIZE) != 0) {
			sb->max_size = (((sb->length + length) / DEFAULT_SIZE) + 1) * DEFAULT_SIZE;
		} else {
			sb->max_size = (((sb->length + length) / DEFAULT_SIZE)) * DEFAULT_SIZE;
		}
		sb->buffer = (char *)realloc(sb->buffer, sb->max_size);
	}

	strcat(sb->buffer, string);
	sb->length += length;
}

void insert(StringBuilder *sb, int offset, char *string){
	assert(offset >= 0);

	int length = strlen(string);

	if (sb->length + length > sb->max_size){
		if (((sb->length + length) % DEFAULT_SIZE) != 0) {
			sb->max_size = (((sb->length + length) / DEFAULT_SIZE) + 1) * DEFAULT_SIZE;
		} else {
			sb->max_size = (((sb->length + length) / DEFAULT_SIZE)) * DEFAULT_SIZE;
		}
		sb->buffer = (char *)realloc(sb->buffer, sb->max_size);
	}

	char *buffer = (char *)malloc(sb->length - offset);
	assert(buffer != NULL);

	int j = 0;
	for (int i = offset; i < sb->length; i++){
		buffer[j] = sb->buffer[i];
		j++;
	}

	for (int i = 0; i < length; i++){
		sb->buffer[offset++] = string[i];
	}

	for (int i = 0; i < strlen(buffer); i++){
		sb->buffer[offset++] = buffer[i];
	}

	sb->length += length;
}

StringBuilder *stringBuilder_init(char *string){
	StringBuilder *sb = (StringBuilder *)malloc(sizeof(StringBuilder));

	int length = strlen(string);

	if (length > DEFAULT_SIZE){
		if ((length % DEFAULT_SIZE) != 0) {
			sb->max_size = ((length / DEFAULT_SIZE) + 1) * DEFAULT_SIZE;
		} else {
			sb->max_size = ((length / DEFAULT_SIZE)) * DEFAULT_SIZE;
		}
		sb->buffer = (char *)realloc(sb->buffer, sb->max_size);
	} else {
		sb->max_size = DEFAULT_SIZE;
		sb->buffer = (char *)malloc(sb->max_size);
	}

	assert(sb->buffer != NULL);

	strcpy(sb->buffer, string);
	sb->length = length;

	return sb;
}


#endif // STRING_BUILDER_H_