#include "shell.h"

void add_alias(Alias **alias_list, const char *name, const char *value){

    Alias *new_alias = malloc(sizeof(Alias));
    if(!new_alias){
        perror("ERROR");
        return;
    }
    new_alias->name = strdup(name);
    new_alias->value = strdup(value);
    new_alias-> next = *alias_list;
    *alias_list = new_alias;
}

void print_alias(const Alias *alias_list, const char *name){

    const Alias *alias = alias_list;
    for(alias_list; alias; alias = alias->next){
        if(!name || strcmp(name, alias->name) == 0 ){
            printf("%s='%s'\n", alias->name, alias->value);
            if(name){
                break;
            }
        }
    }
}

void free_aliases(Alias *alias_list){
    while(alias_list){
        Alias *temp = alias_list;
        alias_list = alias_list->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}