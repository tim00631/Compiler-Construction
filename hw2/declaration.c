typedef struct Entry {
    int index;
    char* name;
    char* kind;
    char* type;
    int scope;
    char* attribute;
    Entry *next;
}Entry;
typedef struct Header {
    int depth;
    int entry_num;
    Entry *table_root;
    Entry *table_tail;
    Header *pre;
}Header;

Header *header_root = NULL;
Header *cur_header = NULL;
//int entry_num = 0; // to record the number of entries
int depth = 0; // scope level