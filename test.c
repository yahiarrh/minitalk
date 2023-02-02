// #include <unistd.h>
// #include <stdio.h>
// #include <signal.h>

// int main ()
// {
//     pid_t pid;
//     NSIG    
//     pid = getpid();
//     while (1)
//     {
//         printf("PID is : %d\n", pid);
//         pause();
//     }
    
// }

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
void forkexample()
{
    int x = 1;
    pid_t x1;
  
    if ((x1 = fork()) == 0)
        printf("Child has x = %d\n", ++x);
    else
        printf("Parent has x = %d\n", --x);
    printf("%d\n",x1);
}
int main()
{
    forkexample();
    return 0;
}