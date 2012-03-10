#include "TextureTable.h"

TextureTable::TextureTable(void)
{
	size = 0;
	capacity = 10;
}


TextureTable::~TextureTable(void)
{
}

void TextureTable::add(TextureEntry t){
	table[size] = t;
	size++;
}

GLuint TextureTable::convertNameToId(char* name){
	for(int i = 0; i < size; i++){
		if(strcmp(table[i].getFileName(),name) == 0){
			return table[i].getTextureId();
		}
	}
	return 0;
}

