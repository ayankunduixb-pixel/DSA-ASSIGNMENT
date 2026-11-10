// Write a program to implement ‘Tower of Hanoi’

#include <stdio.h>

void towerOfHanoi(int n,char source,char auxiliary, char destination){
    if(n == 1){
        printf("Move disk 1 from %c to %c\n",source,destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n-1,source,destination,auxiliary);

    // Move the largest disk to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d",&n);

    if(n == 0){
        printf("Enter a positive number of disks.\n");
        return 0;
    }

    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}