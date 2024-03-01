#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "list.h"
#include "get.h"

typedef struct information {
    char *id;
    int time_arrived;
    int time_service;
    struct information *next;
} information;

queue *new_queue() {
    queue *table = (queue *) calloc(1, sizeof(queue));
    table->size = 0;
    table->head = NULL;
    table->tail = NULL;
    return table;
}

struct information *new_information() {
    information *person = (information *) malloc(sizeof(information));
    person->time_service = 0;
    person->time_arrived = 0;
    person->id = NULL;
    person->next = NULL;
    return person;
}

int is_time(queue *table) {
  return table->head->time_arrived;
}

int time_to_out(queue *table) {
  return table->head->time_arrived + table->head->time_service;
}

void retime(queue *table, int ta, int ts) {
  table->head->time_arrived = ta + ts;
}

int queue_put_in(queue *table, struct information person) {
  information *new = new_information();
  new->id = (char *) malloc((strlen(person.id) + 1) * sizeof(char));
  strcpy(new->id, person.id);
  new->time_arrived = person.time_arrived;
  new->time_service = person.time_service;
  new->next = NULL;
  if (table->head == NULL) {
    table->head = new;
    table->tail = new;
  } else {
    table->tail->next = new;
    table->tail = new;
  }
  (table->size)++;
  return 0;
}

int put(queue *table, char *id, int time_arrived, int time_service) {
  information *new = new_information();
  new->id = (char *) malloc((strlen(id) + 1) * sizeof(char));
  strcpy(new->id, id);
  new->time_arrived = time_arrived;
  new->time_service = time_service;
  new->next = NULL;
  if (table->head == NULL) {
    table->head = new;
    table->tail = new;
  } else {
    table->tail->next = new;
    table->tail = new;
  }
  (table->size)++;
  return 0;
}

int queue_get(queue *table, struct information *person) {
  if (table->head == NULL) {
    return -1;
  }
  information *tmp = table->head;
  table->head = table->head->next;
  if (table->head == NULL) {
    table->tail = NULL;
  }
  (table->size)--;
  *person = *tmp;
  person->id = (char *) malloc((strlen(tmp->id) + 1) * sizeof(char));
  strcpy(person->id, tmp->id);
  free(tmp->id);
  free(tmp);
  return 0;
}

int get(queue *table, char **id, int *time_arrived, int *time_service) {
  if (table->head == NULL) {
    return -1;
  }
  information *tmp = table->head;
  table->head = table->head->next;
  if (table->head == NULL) {
    table->tail = NULL;
  }
  (table->size)--;
  *id = (char *) malloc((strlen(tmp->id) + 1) * sizeof(char));
  strcpy(*id, tmp->id);
  *time_arrived = tmp->time_arrived;
  *time_service = tmp->time_service;
  free(tmp->id);
  free(tmp);
  return 0;
}

int queue_is_empty(queue *table) {
  if (table->head == NULL) {
    return 0;
  } else {
    return 1;
  }
}

void queue_print(queue *table) {
  information *curr = table->head;
  while (curr != NULL) {
    printf("%s ", curr->id);
    curr = curr->next;
  }
  printf("\n");
}

void queue_delete(queue *table) {
  information *curr = table->head;
  while (curr != NULL) {
    information *next = curr->next;
    free(curr->id);
    free(curr);
    curr = next;
  }
  table->head = NULL;
  table->tail = NULL;
  table->size = 0;
  free(table);
}

int queue_make(queue *table) {
  scanf("%*[^\n]");
  scanf("%*c");
  printf("\nEnter Your Example In One String In Format \"char string/positive integer number/positive integer number\"\n");
  char *str;
  str = readline();
  if (!str) {
    free(str);
    return -1;
  } else {
    int number_of_persons = 0;
    char **array = split_string(str, &number_of_persons);

    if (array == NULL) {
      for (int ind = 0; ind < number_of_persons; ind++) {
        free(array[ind]);
      }
      free(array);
      free(str);
      return -1;
    } else {
      for (int i = 0; i < number_of_persons; i++) {
        information *person = new_information();
        int ind_ta = 0, ind_ts = 0, ta_size = 0, ts_size = 0, *ta = NULL, *ts = NULL;
        
        for (int ind_id = 0; ind_id < strlen(array[i]); ind_id++) {
          if (array[i][ind_id] != '/') {
            person->id = (char *) realloc(person->id, (ind_id + 2) * sizeof(char));
            (person->id)[ind_id] = array[i][ind_id];
          } else if (array[i][ind_id] == '/') {
            person->id = (char *) realloc(person->id, (ind_id + 2) * sizeof(char));
            (person->id)[ind_id] = '\0';
            ind_ta = ind_id + 1;
            break;
          } else if (array[i][ind_id] == '\0') {
            printf("\nIncorrect Input, Plese Repeat Your Input Correctly\n");
            free(person->id);
            free(person);
            for (int ind = 0; ind < number_of_persons; ind++) {
              free(array[ind]);
            }
            free(array);
            free(str);
            return 2;
          }
        }
        
        if (!(person->id) || ind_ta == 0) {
          printf("\nIncorrect Input, Plese Repeat Your Input Correctly\n");
            free(person->id);
            free(person);
            for (int ind = 0; ind < number_of_persons; ind++) {
              free(array[ind]);
            }
            free(array);
            free(str);
            return 2;
        } else {
          for (ind_ta; ind_ta <= strlen(array[i]); ind_ta++) {
            if (array[i][ind_ta] >= '0' && array[i][ind_ta] <= '9') {
              ta_size++;
              ta = (int *) realloc(ta, ta_size * sizeof(int));
              ta[ta_size - 1] = array[i][ind_ta] - '0';
            } else if (array[i][ind_ta] == '/') {
              ind_ts = ind_ta + 1;
              break;
            } else {
              printf("\nIncorrect Input, Please, Repeat Your Input Correctly\n");
              if (!ta) {
                free(ta);
              }
              free(person->id);
              free(person);
              for (int ind = 0; ind < number_of_persons; ind++) {
                free(array[ind]);
              }
              free(array);
              free(str);
              return 2;
            }
          }
          for (int k = 0; k < ta_size; k++) {
            person->time_arrived += power(10, ta_size - k - 1) * ta[k];
          }
          for (ind_ts; ind_ts < strlen(array[i]); ind_ts++) {
            if (array[i][ind_ts] < '0' || array[i][ind_ts] > '9' || array[i][ind_ts] == EOF || array[i][ind_ts] == '\0') {
              printf("\nIncorrect Input, Please, Repeat Your Input Correctly\n");
              free(ta);
              if (!ts) {
                free(ts);
              }
              free(person->id);
              free(person);
              for (int ind = 0; ind < number_of_persons; ind++) {
                free(array[ind]);
              }
              free(array);
              free(str);
              return 2;
            } else {
              ts_size++;
              ts = (int *) realloc(ts, ts_size * sizeof(int));
              ts[ts_size - 1] = array[i][ind_ts] - '0';
            }
          }
          for (int l = 0; l < ts_size; l++) {
            person->time_service += power(10, ts_size - l - 1) * ts[l];
          }
        }
        queue_put_in(table, *person);
        free(ta);
        free(ts);
        free(person->id);
        free(person);
      }
    }
    for (int ind = 0; ind < number_of_persons; ind++) {
      free(array[ind]);
    }
    free(array);
    free(str);
    return 0;
  }
}

void queue_insert_sorted(queue *q, struct information *item) {
    if (q->head == NULL || item->time_arrived < q->head->time_arrived) {
        item->next = q->head;
        q->head = item;
        if (q->tail == NULL) {
            q->tail = item;
        }
        q->size++;
    } else {
        information *curr = q->head;
        while (curr->next != NULL && curr->next->time_arrived < item->time_arrived) {
            curr = curr->next;
        }
        item->next = curr->next;
        curr->next = item;
        if (item->next == NULL) {
            q->tail = item;
        }
        q->size++;
    }
}

void queue_sort(queue* table) {
  information *curr = table->head;
  table->head = NULL;
  table->tail = NULL;
  table->size = 0;
  while (curr != NULL) {
    information *next = curr->next;
    queue_insert_sorted(table, curr);
    curr = next;
  }
}

void resize(queue *table, int new_size) {
    table->size = new_size;
}
