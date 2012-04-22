/*
    file    dbg_new_delete.cpp
    date    2012/02/29 
    author  Azuma_Yoshitaka
*/

#ifdef _DEBUG

#include "dbg_new_delete.h"
#include <map>

using std::map;

// ==================================================
// struct
// ==================================================
typedef struct MEM_INFO {
    unsigned int id;
    char* file;
    int line;
    MEM_INFO() : id(0), file(NULL), line(0) {}
}MEM_INFO ;
// ==================================================
// typedef 
// ==================================================
typedef std::map<void*, MEM_INFO>       MEM_INFO_MAP;
typedef MEM_INFO_MAP::iterator          MEM_INFO_MAP_IT;
typedef std::pair<void*, MEM_INFO>      MEM_INFO_PAIR;
// ==================================================
// static var
// ==================================================
static unsigned int new_count = 0;
static MEM_INFO_MAP mem_info_map;
static MEM_INFO_MAP* memInfoMap() { return &mem_info_map; }
// ==================================================
// static function
// ==================================================

// ==================================================
// function
// ==================================================
void* operator new(size_t size, char* file, int line)
{
    void* ptr = malloc(size);

    MEM_INFO_MAP *p_mem = memInfoMap();

    MEM_INFO mem_info;
    mem_info.id = new_count++;
    mem_info.file = file;
    mem_info.line = line;
    MEM_INFO_PAIR pair(ptr, mem_info);
    p_mem->insert(pair);

    return (void*)((char*)ptr);
}

void* operator new[](size_t size, char* file, int line) {
    void* ptr = malloc(size);

    MEM_INFO_MAP *p_mem = memInfoMap();

    MEM_INFO mem_info;
    mem_info.id = new_count++;
    mem_info.file = file;
    mem_info.line = line;
    MEM_INFO_PAIR pair(ptr, mem_info);
    p_mem->insert(pair);
    return (void*)((char*)ptr);
}

void operator delete(void* p)
{
    MEM_INFO_MAP *p_mem = memInfoMap();

    MEM_INFO_MAP_IT it = p_mem->find(p);
    if ( it != mem_info_map.end() ) {
        MEM_INFO p_mem_info = it->second;

        p_mem->erase(it);
    }
    else {
        //DebugAssert(false);   stl“à‚ÅŠm•Û‚³‚ê‚½‚à‚Ì‚ª–³‚¢‚Æ“{‚ç‚ê‚½c
    }

    free(p);
}

void operator delete[](void* p)
{
    MEM_INFO_MAP *p_mem = memInfoMap();

    MEM_INFO_MAP_IT it = p_mem->find(p);
    if ( it != mem_info_map.end() ) {
        MEM_INFO p_mem_info = it->second;

        p_mem->erase(it);
    }
    else {
        //DebugAssert(false);   stl“à‚ÅŠm•Û‚³‚ê‚½‚à‚Ì‚ª–³‚¢‚Æ“{‚ç‚ê‚½c
    }
    free(p);
}


void leak_check_dump(const char* str)
{
    const int NAME_SIZE = 128;
    char file_name[NAME_SIZE];
    file_name[0] = '\0';
    sprintf_s(file_name, NAME_SIZE, "%s_LEAK.txt", str);

    FILE *fp;
    fopen_s(&fp, file_name, "w");
    MEM_INFO_MAP *p_mem = memInfoMap();

    MEM_INFO_MAP_IT it = p_mem->begin();
    while ( it != mem_info_map.end() ) {
        MEM_INFO mem_info = it->second;
        fprintf(fp, "ID: %10d FILE: %s, LINE: %d\n", mem_info.id, mem_info.file, mem_info.line);
        ++it;
    }

    fclose(fp);
}

#endif	// _DEBUG
