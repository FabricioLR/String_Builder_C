#include <stdio.h>
#include "../string_builder.h"


int main(){
	StringBuilder *sb = stringBuilder_init("hello, world");

	printf("initial sb: %s\n", toString(sb));

	append(sb, "  teste - teste");
	printf("appended: %s\n", toString(sb));
	insert(sb, 0, "ola");
	printf("inserted: %s\n", toString(sb));
	delete(sb, 4, 9);
	printf("delete 4, 9: %s\n", toString(sb));
	printf("reversed: %s\n", reverse(sb));
	printf("substring 5, 9: %s\n", substring(sb, 5, 9));
	//replace(sb, string, string);
	//replaceAll(sb, string, string);
	printf("indexOf '- ': %d\n", indexOf(sb, "- "));

	printf("\n\nfinal sb: %s\nlength: %d\nmax_size: %d\n", toString(sb), sb->length, sb->max_size);

	return 0;
}