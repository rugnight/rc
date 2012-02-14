//============================================================================
// Name        : rc/util/util_file.cpp
// Author      :
// Version     :
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

namespace rc {

/* ファイルをバッファに読み込む */
char* createBufferFromFile(const char *file)
{
    FILE *fptr;
    long length;
    char *buf;

    fptr = fopen(file, "rb"); 
    if (!fptr) 
        return NULL;
    fseek(fptr, 0, SEEK_END);      // ファイルサイズを計測
    length = ftell(fptr);
    buf = (char*)malloc(length+1); // バッファを確保（NULL文字領域も追加で確保
    fseek(fptr, 0, SEEK_SET);      // ファイルポインタを先頭に戻し、サイズ分をバッファに書きこむ
    fread(buf, length, 1, fptr);
    fclose(fptr);
    buf[length] = 0;

    return buf;
}


}; // namespace rc
