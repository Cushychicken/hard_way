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

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("age: %d\n", who->age);
	printf("height: %d\n", who->height);
	printf("weight: %d\n", who->weight);
}

int main(int argc, char *argv[]){
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 32, 64, 140);

	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Joe is at memory location %p:\n", frank);
	Person_print(frank);

	joe->age += 20;
	joe->height -= 2;
	Person_print(joe);

	Person_destroy(joe);
	Person_destroy(frank);

    return 0;

}
