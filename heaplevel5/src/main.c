/*
 * main.c
 * Copyright (C) 2018 hzshang <hzshang15@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#define POOL_SIZE 0x10
int pool_size[POOL_SIZE];
char* pool[POOL_SIZE];

void menu() {
    puts("1. Add note");
    puts("2. Show note");
    puts("3. Edit note");
    puts("4. Delete note");
    puts("5. Exit");
    printf(">> ");
}
int read_num(){
    char buf[0x20];
    fgets(buf,0x20,stdin);
    return atoi(buf);
}
void add_note() {
    int idx,size;
    for(idx = 0; idx < POOL_SIZE && pool[idx]; idx++);
    if (idx == POOL_SIZE) {
        puts("Full!");
        return;
    }
    printf("Size:");
    size=read_num();
    if(size>0x200)
        size=0x200;
    pool[idx]=(char*)malloc(size);
    pool_size[idx]=size;
}

void show_note(){
    printf("Input your id:");
    unsigned int idx=read_num();
    if(idx<POOL_SIZE && pool[idx]){
        puts(pool[idx]);
    }else{
        puts("Are u a hacker?");
    }
}
void edit_note(){
    printf("Input your id:");
    unsigned int idx=read_num();
    if(idx<POOL_SIZE && pool[idx]){
        printf("Content:");
        fgets(pool[idx],pool_size[idx],stdin);
    }else{
        puts("Are u a hacker?");
    }
}
void dele_note(){
    printf("Input your id:");
    unsigned int idx=read_num();
    if(idx<POOL_SIZE){
        free(pool[idx]);
    }else{
        puts("Are u a hacker?");
    }
}
#define ll unsigned long long
int main(int argc, char *argv[]) {
    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);
    while(1) {
        menu();
        switch(read_num()) {
        case 1:
            add_note();
            break;
        case 2:
            show_note();
            break;
        case 3:
            edit_note();
            break;
        case 4:
            dele_note();
            break;
        case 5:
            exit(0);
            break;
        default:
            puts("em?");
            exit(0);
        }
    }
    return 0;
}
