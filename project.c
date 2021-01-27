#include "project.h"

void fatal(const char*);
void onExit(void);
void onInterrupt(int);

int main(void) {
    if (gpioInitialise() < 0) {
        fatal("could not initialize gpio\n");
    }
    if (atexit(onExit)) {
        gpioTerminate();
        fatal("could not set exit function\n");
    }
    signal(SIGINT, onInterrupt);

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1) {
        printf("> ");
        nread = getline(&line, &len, stdin);
        if (nread < 0) fatal("bad input");
        if (0 /* test for command */) {
            // do something with the command
        } else {
            puts(
                "Commands: \n"
                "No commands\n"
            );
        }
    }
    
    exit(EXIT_FAILURE); // unreachable
}

void fatal(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// runs after a call to exit()
void onExit(void) {
    gpioTerminate();
    printf("\ngoodbye\n");
}

// ctrl+c handler
void onInterrupt(int signum) {
    exit(EXIT_SUCCESS);
}

