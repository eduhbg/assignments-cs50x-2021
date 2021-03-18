#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the user name and say hello
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}