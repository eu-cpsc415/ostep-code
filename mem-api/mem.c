#include <malloc.h>
#include <stdio.h>
#include <unistd.h>

// Global variable, stored in the data segment
int global_var = 10;

// Constant global variable, stored in the read-only data segment
const int const_global_var = 20;

struct state {
    int score;
    int health;
    int level;
};

void init(struct state* s)
{
    s->score = 0;
    s->health = 100;
    s->level = 1;
}

void update(struct state* s, int score)
{
    s->score += score;
    s->health -= 10;
    s->level += 1;
}

int main(int argc, char* argv[])
{
    // Stack
    int score = 42;
    struct state s1;

    // Initialize the state
    init(&s1); // Notice the & (address-of operator)

    // Pointer on stack, points to -> allocated memory on heap
    struct state* s2 = malloc(sizeof(struct state));

    // Initialize the state
    init(s2);

    // Update the state
    update(&s1, score);

    // Print addresses and values
    printf("Process ID: %d  (pmap %d)\n", getpid(), getpid());
    printf("Global variable: %p\n", (void*)&global_var);
    printf("Const global variable: %p\n", (void*)&const_global_var);
    printf("Stack variable (score): %p\n", (void*)&score);
    printf("Heap variable (s2): %p\n", (void*)s2);
    printf("s1: score=%d, health=%d, level=%d\n", s1.score, s1.health, s1.level);
    printf("s2: score=%d, health=%d, level=%d\n", s2->score, s2->health, s2->level);

    while (1) {
        // Infinite loop to keep the program running
        // so you can use pmap to inspect the memory layout
    }

    // Free the allocated memory (never reached if infinite loop is left as is above)
    free(s2);

    return 0;
}
