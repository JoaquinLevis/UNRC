#include <stdio.h>

void ping(int x);
void pong(int x);

int main(){
    ping(0);

    return 0;
}


void ping(int x){
    if(x > 10){
    return;
    }else {
        printf("Ping\n");
        pong(x+1);
    }
}

void pong(int x){
    if(x > 10){
    return;
    }else {
        printf("Pong\n");
        ping(x+1);
    }
}

