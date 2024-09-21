// Name:10c.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:12 Sep 2024

// 10. Write a separate program using sigaction system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>

// Signal handler for SIGFPE (floating-point exception)
void handle_sigfpe(int sig) {
    printf("Caught SIGFPE: Floating-point exception occurred.\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa_fpe;

    // Set up the SIGFPE handler
    sa_fpe.sa_handler = handle_sigfpe;
    sigemptyset(&sa_fpe.sa_mask);
    sa_fpe.sa_flags = 0;
    sigaction(SIGFPE, &sa_fpe, NULL);

    printf("Genarating SIGFPE\n");
    int x=1;
    int zero=0;
    int res=x/zero;

    printf("Result: %d\n", res); // This line will not be reached

    return 0;
}

// Output:
// Genarating SIGFPE
// Caught SIGFPE: Floating-point exception occurred.




// Output:
// Generating SIGFPE
// Caught SIGFPE (Divide by zero)


