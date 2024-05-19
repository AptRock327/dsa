#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Warning: the function changes the argument
unsigned int hashString(char* str)
{
	unsigned int hash = 0;
	while(*str)
	{
		hash+=*str;
		str++;
	}
	return hash;
}

//Adds an entry to a hash map
//@hash - value for future lookup
//@entry - the entry to be found there
void addEntry(char** hashMap, char* hash, const char* entry)
{
	strcpy(hashMap[hashString(hash)], entry);
}

//Gets an entry from a hash map
//@hash - lookup value
char* getEntry(char** hashMap, char* hash)
{
	return hashMap[hashString(hash)];
}

int main(int argc, char** argv)
{
	//Allocate hash map
	char** keys = malloc(40 * 255); //40 elements
	for(int i = 0; i < 40 * 255; i++) keys[i] = malloc(40); //with a maximum length of 40 characters
	
	//Initialize hash map
	addEntry(keys, "Ctrl+N", "action.file.new");
	addEntry(keys, "Ctrl+O", "action.file.open");
	addEntry(keys, "Ctrl+S", "action.file.save");
	addEntry(keys, "Ctrl+Shift+S", "action.file.saveAs");
	addEntry(keys, "Ctrl+F4", "action.exit");
        
	//Display hash map based on strings in O(1)
	printf("%s\n%s\n%s\n%s\n%s\n", getEntry(keys, "Ctrl+N"), getEntry(keys, "Ctrl+O"), getEntry(keys, "Ctrl+S"), getEntry(keys, "Ctrl+Shift+S"), getEntry(keys, "Ctrl+F4"));

	//Exit with 0 and therefore deallocate
	return 0;
}
