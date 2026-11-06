#include <stdio.h>
#include <unistd.h>

int main()
{
    char text[] = "Hello Hospital\n";
    write(1, text, sizeof(text) - 1);
    return 0;
}

