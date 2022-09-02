#include shell.h



int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    while (1)
    {
        PRINT("$ ");
        char *line = read_line();
        PRINT(line);

    }
}


char *read_line() {
    char *line = NULL;
    size_t buflen = 0;

    getline(&line, &buflen, stdin);
    return (line);

}