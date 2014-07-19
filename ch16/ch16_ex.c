#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};


int main(int argc, char *argv[]){
	struct Person joe = { "Joe Schmoe", 18, 72, 150 }; 

    printf("Name    : %s\n", joe.name);
	printf("Age     : %d\n", joe.age);
	printf("Height  : %d\n", joe.height);
	printf("Weight  : %d\n", joe.weight);

	printf("Joe is at memory location %p:\n", joe);


    free(joe.name);
	free(joe);
    return 0;

}
