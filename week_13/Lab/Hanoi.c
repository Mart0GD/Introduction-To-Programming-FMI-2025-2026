#include <stdio.h>

#define TOWERS 3

void play_hanoi();
void hanoi(int disk, int from, int to);

int main(){
    play_hanoi();
}

void play_hanoi(){
    hanoi(3, 1, 3);
}

void hanoi(int disk, int from, int to){
    if(disk == 0) return;

    int go_to_pole = 6 - from - to;

    hanoi(disk - 1, from, go_to_pole);
    printf("Moved disk %d from %d to %d\n", disk, from, to);
    hanoi(disk - 1, go_to_pole, to);
}