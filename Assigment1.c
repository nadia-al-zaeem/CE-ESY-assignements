#include <stdio.h>
#include <string.h>

#define SMALL 5
#define LARGE 30

typedef struct
{
    char arr[LARGE];
    int head;
    cd int tail;
    int count;
    int size;
} CB;

void init(CB *c, int s)
{
    c->head = 0;
    c->tail = 0;
    c->count = 0;
    c->size = s;
}

int full(CB *c)
{
    if (c->count == c->size)
        return 1;
    return 0;
}

int empty(CB *c)
{
    if (c->count == 0)
        return 1;
    return 0;
}

void write(CB *c, char ch)
{
    if (full(c))
    {
        printf("Overflow -> %c\n", ch);
        return;
    }

    c->arr[c->tail] = ch;
    c->tail = (c->tail + 1) % c->size;
    c->count++;
}

char read(CB *c)
{
    if (empty(c))
    {
        printf("Underflow\n");
        return '\0';
    }

    char x = c->arr[c->head];
    c->head = (c->head + 1) % c->size;
    c->count--;

    return x;
}

void test(int s, char name[])
{
    CB c;
    init(&c, s);

    char str[100];
    strcpy(str, name);
    strcat(str, "CE-ESY");

    printf("\nSize = %d\n", s);
    printf("Input = %s\n", str);

    for (int i = 0; i < strlen(str); i++)
    {
        write(&c, str[i]);
    }

    printf("Output: ");
    while (!empty(&c))
    {
        printf("%c", read(&c));
    }

    printf("\n");

    if (empty(&c))
        printf("Empty now\n");
}

int main()
{
    char name[50];

    printf("Enter name: ");
    scanf("%s", name);

    test(SMALL, name);
    test(LARGE, name);

    return 0;
}