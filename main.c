#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_BIND_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_CATEGORY_LENGTH 100

// A datatype for categories
typedef struct Category
{
    char name[MAX_CATEGORY_LENGTH];
    struct Category *p_next;
} Category;

// A datatype for keybinds
typedef struct Keybind
{
    char bind[MAX_BIND_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct Category *p_category;
    struct Keybind *p_next;
} Keybind;


// Creates the new bind
Keybind *create_bind(char *p_bind, char *p_description, Category *p_category)
{
    // Allocates memory and returns a bind
    Keybind *newBind = (Keybind *)malloc(sizeof(Keybind));
    strncpy(newBind->bind, p_bind, MAX_BIND_LENGTH);
    strncpy(newBind->description, p_description, MAX_DESCRIPTION_LENGTH);
    newBind->p_category = p_category;
    newBind->p_next = NULL;

    return newBind;
}

// Creates the category
Category *create_category(char *p_name)
{
    // Allocates memory and returns a category
    Category *newCategory = (Category *)malloc(sizeof(Category));
    strncpy(newCategory->name, p_name, MAX_CATEGORY_LENGTH);
    newCategory->p_next = NULL;

    return newCategory;
}

// Appends the binds into a linked list
void append_bind(Keybind *head, Keybind *p_keybind)
{
    // Checks to see whether the binds are null
    if (head == NULL || p_keybind == NULL)
    {
        printf("\n Task allocation failed");
    }
    else
    {
        // Traverses linked list until there are no more elements and adds it to the end
        Keybind *p_current = head;
        while (p_current->p_next != NULL)
        {
            p_current = p_current->p_next;
        }
        p_current->p_next = p_keybind;
    }
}

// Appends the categories into a linked list
void append_category(Category *head, Category *p_category)
{
    // Checks to see whether the binds are null
    if (head == NULL || p_category == NULL)
    {
        printf("\n Task allocation failed");
    }
    else
    {
        // Traverses linked list until there are no more elements and adds it to the end
        Keybind *p_current = head;
        while (p_current->p_next != NULL)
        {
            p_current = p_current->p_next;
        }
        p_current->p_next = p_category;
    }
}


// Prepends the binds into the keybinds linked list
void prepend_bind(Keybind *head, Keybind *p_keybind)
{
    if (head == NULL || p_keybind == NULL)
    {
        printf("\n Prepending keybind failed");
    }
    else
    {
        // Checks to see if there are elements within the linked list
        if (head->p_next != NULL)
        {
            // Sets the keybind to be the next after head by swapping its pointers
            p_keybind->p_next = head->p_next;
            head->p_next = p_keybind;
        }
        else
        {
            head->p_next = p_keybind;
        }
    }
}

// Prepends the category into the categories linked list
void prepend_category(Category *head, Category *p_category)
{
    if (head == NULL || p_category == NULL)
    {
        printf("\n Prepending category failed");
    }
    else
    {
        // Checks to see if there are elements within the linked list
        if (head->p_next != NULL)
        {
            // Sets the category to be the next after head by swapping its pointers
            p_category->p_next = head->p_next;
            head->p_next = p_category;
        }
        else
        {
            head->p_next = p_category;
        }
    }
}


// Displays the keybinds list
void display_keybinds(Keybind *head)
{
    Keybind *p_currentBind = head;
    
    // Traverses linked list and prints to the console the binds' bind, description, and category
    int index = 0;
    while (p_currentBind != NULL)
    {
        index++;
        printf("%d: %s - %s - %s\n", index, p_currentBind->bind, p_currentBind->description, p_currentBind->p_category->name);
        p_currentBind = p_currentBind->p_next;
    }
}

// Displays the categories list
void display_categories(Category *head)
{
    Category *p_currentCategory = head;
    
    // Traverses linked list and prints to the console the category's name
    int index = 0;
    while (p_currentCategory != NULL)
    {
        index++;
        printf("%d: %s\n", index, p_currentCategory->name);
        p_currentCategory = p_currentCategory->p_next;
    }
}

// Recursively frees all the memory within the linked list
void free_keybind_list(Keybind *head)
{
    // Checks to see if the bind is null
    if (head == NULL)
        return;
    
    // Reruns the function for the next element in the list
    free_keybind_list(head->p_next);

    // Frees the current bind
    free(head);
}

// Recursively frees all the memory within the linked list
void free_category_list(Category *head)
{
    // Checks to see if the category is null
    if (head == NULL)
        return;
    
    // Reruns the function for the next element in the list
    free_category_list(head->p_next);

    // Frees the current category
    free(head);

}

// Initialises the head of the keybinds linked list
Keybind *init_keybind_head()
{
    Keybind *head = (Keybind *)malloc(sizeof(Keybind));
    strncpy(head->bind, "", MAX_BIND_LENGTH);
    strncpy(head->description, "", MAX_DESCRIPTION_LENGTH);
    head->p_category = NULL;
    head->p_next = NULL;

    return head;
}

// Initialises the head of the categories linked list
Category *init_category_head()
{
    Category *head = (Category *)malloc(sizeof(Category));
    strncpy(head->name, "", MAX_CATEGORY_LENGTH);
    head->p_next = NULL;

    return head;
}

void input_bind(Keybind *head)
{
    char bind[MAX_BIND_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];

    printf("What is the keybind? ");
}

// Main function
int main()
{
    // Create head nodes
    Keybind *keybindHead = init_keybind_head();
    Category *categoryHead = init_category_head();

    // Frees all the memory used up by the keybinds linked list
    free_keybind_list(keybindHead);
    
    // Frees all the memory used up by the categories linked list
    free_category_list(categoryHead);

    return 0;
}
