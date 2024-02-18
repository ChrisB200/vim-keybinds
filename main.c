#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_BIND_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_CATEGORY_LENGTH 100

typedef struct Keybind
{
    char bind[MAX_BIND_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    struct Keybind *p_next;
} Keybind;

Keybind *create_bind(char *p_bind, char *p_description, char *p_category)
{
    Keybind *newBind = (Keybind *)malloc(sizeof(Keybind));
    strncpy(newBind->bind, p_bind, MAX_BIND_LENGTH);
    strncpy(newBind->description, p_description, MAX_DESCRIPTION_LENGTH);
    strncpy(newBind->category, p_category, MAX_CATEGORY_LENGTH);
    newBind->p_next = NULL;

    return newBind;
}

void add_next_bind(Keybind *p_keybind, Keybind *p_nextBind)
{
    if (p_keybind == NULL || p_nextBind == NULL)
    {
        printf("\n Task allocation failed");
    }
    else
    {
        Keybind *p_current = p_keybind;
        while (p_current->p_next != NULL)
        {
            p_current = p_current->p_next;
        }
        p_current->p_next = p_nextBind;
    }
}


void display_list(Keybind *p_bind)
{
    Keybind *p_currentBind = p_bind;
    
    int index = 0;
    while (p_currentBind != NULL)
    {
        index++;
        printf("%d: %s - %s - %s\n", index, p_currentBind->bind, p_currentBind->description, p_currentBind->category);
        p_currentBind = p_currentBind->p_next;
    }
}

void free_list(Keybind *p_bind)
{
    if (p_bind == NULL)
        return;

    free_list(p_bind->p_next);

    free(p_bind);
}

int main()
{
    Keybind *test1 = create_bind("Test 1", "Test Description 1", "Test Category");
    Keybind *test2 = create_bind("Test 2", "Test Description 2", "Test Category");
    Keybind *test3 = create_bind("Test 3", "Test Description 3", "Test Category");
    Keybind *test4 = create_bind("Test 4", "Test Description 4", "Test Category");
    Keybind *test5 = create_bind("Test 5", "Test Description 5", "Test Category");
    Keybind *test6 = create_bind("Test 6", "Test Description 6", "Test Category");
    Keybind *test7 = create_bind("Test 7", "Test Description 7", "Test Category");
    Keybind *test8 = create_bind("Test 8", "Test Description 8", "Test Category");
    Keybind *test9 = create_bind("Test 9", "Test Description 9", "Test Category");

    add_next_bind(test1, test2);
    add_next_bind(test1, test3);
    add_next_bind(test1, test4);
    add_next_bind(test1, test5);
    add_next_bind(test1, test6);
    add_next_bind(test1, test7);
    add_next_bind(test1, test8);
    add_next_bind(test1, test9);

    display_list(test1);

    free_list(test1);

    return 0;
}
