/*
 * Project: Dynamic Phonebook Manager (IETI Lab 6)
 * File: phonebook_manager.c
 * Aim: This program manages a phone agenda using structures, providing 
 * functionality for searching, adding new contacts, and alphabetical sorting.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    int tel[10]; 
}PERSON; 

void read(PERSON *p, int n){
    for(int i=0; i<n; i++){
        printf("enter data for person %d\n", i+1); 
        printf("name: "); 
        scanf("%s", p[i].name); 
        
        printf("phone number (with space between digits): "); 
        for(int j=0; j<10; j++)
           scanf("%d", &p[i].tel[j]); 
    }
}

PERSON* add(PERSON *p, int *n, char *name){
    p= realloc(p, (*n+1)*sizeof(PERSON)); 
    
    strcpy(p[*n].name, name); 
    printf("enter phone number: "); 
    for(int j=0; j<10; j++)
           scanf("%d", &p[*n].tel[j]); 
    (*n)++; 
    
    return p; 
}

void sort(PERSON *p, int n){
    int sorted; 
    do{
        sorted=1; 
        for(int i=0; i<n-1; i++)
          if(strcmp(p[i].name, p[i+1].name) > 0 ){
              PERSON aux; 
              aux = p[i];
              p[i] = p[i+1]; 
              p[i+1]= aux; 
              sorted=0; 
          }
    }while(sorted==0); 
}

int main(void){
  printf("PHONE AGENDA\n"); 
  
  printf("enter the number of people in the agenda: "); 
  int n; 
  scanf("%d", &n); 
  
  PERSON *p= malloc(n*sizeof(PERSON));
  if(!p){
      printf("insufficient memory.\n"); 
      exit(1); 
  }
  
  read(p, n); 
  
  printf("enter the name of the searched person: "); 
  char name[50]=""; 
  scanf("%s", name); 
  
  int found=0; 
  for(int i=0; i<n; i++)
    if(strcmp(p[i].name, name)==0){
        printf("the phone number for the searched person is: "); 
        for(int j=0; j<10; j++)
           printf("%d", p[i].tel[j]); 
           
        found=1; 
        break; 
    }
    if(found==0) {
        printf("that person does not appear in the agenda.\n"); 
        printf("do you want to add them? (YES/NO): "); 
        char choice[5]=""; 
        scanf("%s", choice); 
        if(strcmp(choice, "YES")==0)
           p = add(p, &n, name); 
        else printf("person will not be added."); 
    }
        
  sort(p, n); 
  printf("this is the agenda in alphabetical order: \n"); 
  for(int i=0; i<n; i++){
  printf("\n%d. %s with phone number: ", i+1, p[i].name); 
      for(int j=0; j<10; j++)
         printf("%d", p[i].tel[j]); 
  }
  
  free(p); 
  return 0;     
}