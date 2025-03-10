
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * a single entry of the name list contains
 * in addition to the name its pos and how
 * often it occurs
 */
typedef struct {
    int pos;
    char* name;
    int occurrence;
} entry_t ;

/** the capacity (maximum number of elements) of the name list */
unsigned list_capacity = 1000;

/** the length (actual number of elements) of the name list */
unsigned list_length = 0;

/** the name list (stored as an array on the heap) */
entry_t* name_list = NULL;


/**
 * Appends an entry to the list.
 * @param pos of the new entry
 * @param name of the new entry
 * @param occurrence of the new entry
 * @return pointer to updated list
 */
 entry_t* append_entry( int pos, char* name, int occurrence ) {
    if(list_length >= list_capacity){
        list_capacity += list_capacity / 2;
        name_list = realloc(name_list, list_capacity * sizeof(entry_t));
    }
    char* newName = malloc(100 * sizeof(char));
    memcpy(newName, name, 100 * sizeof(char));

    entry_t newEntry = {pos, newName, occurrence};
    name_list[list_length] = newEntry;
    list_length++;
    return name_list;
}


/**
 * Reads all the entries from standard inputs
 * (list is terminated by entry "0 END 0")
 */
void read_entries() {
    int pos; int occ; char name[100];
    // the following loop reads a new name in every iteration
    // until the end of the file (entry with pos 0)
    while (1) {
        scanf("%i %100s %i", &pos, name, &occ);
        if( pos == 0 ) break;
        append_entry( pos, name, occ );
    }
}


/**
 * Prints the list of names
 */
void print_list() {
    for(unsigned i=0; i<list_length; i++)
        printf("%6i | %20s | %6i\n", name_list[i].pos, name_list[i].name, name_list[i].occurrence);
}


/**
 * Returns the name of a given position
 * @param n given position
 * @returns position(or 0 if not found)
 */
char* name_of_pos( int r ) {
    for(int i = 0; i < list_length; i++){
        if(r == name_list[i].pos){
            return name_list[i].name;
        }
    }
    return NULL;
}


/**
 * Returns the position of a given name
 * @param n given name
 * @returns pos (or 0 if not found)
 */

unsigned pos_of_name( char* n ) {
    for (int i = 0; i < list_length; i++) {
        if (strcmp(name_list[i].name, n) == 0) {
            return name_list[i].pos;
        }
    }
    return 0;
}
int compare(const void *e1, const void *e2) {
    entry_t *entry1 = (entry_t*) e1;
    entry_t *entry2 = (entry_t*) e2;

    return strcmp(entry1->name, entry2->name);
}
// ----------------------

int main() {
    // initialize the name list by allocating memory on the heap
    // for the initial capacity of the list
    name_list = malloc(list_capacity * sizeof(entry_t) );
    // read list of names
    read_entries();

    // sort the list of names
    // TODO: qsort( ... );
    qsort(name_list, list_length, sizeof(entry_t), compare);

    // print resulting list
    print_list();

    // the user is asked for search strings
    char search_string[30];
    while( 1 ) {
        // make search string empty
        search_string[0] = '\0';
        // ask user for search string
        printf("Welcher Name oder welche Position soll gesucht werden (Ende mit ENTER)?\n");
        scanf("%30s", search_string);

        // if nothing was entered, program will quit
        if( strlen(search_string) == 0 ) break;

        // if search string contains a position, answer with:
        // printf("Auf Position %d steht der Name %s.\n", ..., ...);
        // printf("Position %d existiert nicht.\n", ...);

        // if search string contains a name, answer with:
        // printf("Der Name %s steht auf Position %d.\n", ..., ...);
        // printf("Der Name %s steht nicht in der Liste.\n", ...);

        int pos = atoi(search_string);

        if(pos != 0 || search_string[0] == '0'){
            if(name_of_pos(pos) != NULL){
                printf("Auf Position %d steht der Name %s.\n", pos, name_of_pos(pos));
            } else {
                printf("Position %d existiert nicht.\n", pos);
            }
        } else {
            if (pos_of_name(search_string) != NULL) {
                printf("Der Name %s steht auf Position %d.\n", search_string, pos_of_name(search_string));
            } else {
                printf("Der Name %s steht nicht in der Liste.\n", search_string);
            }
        }
    }
}
