#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
  char name[50];
  int purchased;
} Item;

int main() {
  int list_size = 0;
  Item *list = NULL;

  // Add or remove items
  char choice;
  while (1) {
    printf("1. Add item\n2. Remove item\n3. Show list\n4. Exit\n");
    scanf("%c", &choice);

    switch (choice) {
      case '1':
        list_size++;
        list = realloc(list, sizeof(Item) * list_size);
        printf("Enter item name: ");
        scanf("%s", list[list_size - 1].name);
        list[list_size - 1].purchased = 0;
        break;
      case '2':
        if (list_size == 0) {
          printf("List is empty!\n");
        } else {
          int item_id;
          printf("Enter item ID to remove: ");
          scanf("%d", &item_id);
          if (item_id > 0 && item_id <= list_size) {
            for (int i = item_id - 1; i < list_size - 1; i++) {
              list[i] = list[i + 1];
            }
            list_size--;
            list = realloc(list, sizeof(Item) * list_size);
          } else {
            printf("Invalid item ID!\n");
          }
        }
        break;
      case '3':
        if (list_size == 0) {
          printf("List is empty!\n");
        } else {
          for (int i = 0; i < list_size; i++) {
            printf("%d. %s %s\n", i + 1, list[i].name, list[i].purchased ? "(Purchased)" : "");
          }
        }
        break;
      case '4':
        free(list);
        return 0;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }
}