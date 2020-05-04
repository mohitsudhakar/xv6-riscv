#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


/* Note: No () allowed in debug msg.

Example:

Start:
msprog 1 Process id {curproc} out of {numprocs} started.
Exit:
msprog 2 Process id {curproc} out of {numprocs} exited.
Open:
msprog 3 Calling open in process id {curproc}.
*/

int main(int argc, char *argv[]){
  if (argc < 3) {
    printf("Usage: msprog <hook> <debug_message>\n");
    printf("Note: hooks are 1 for start, 2 for exit, 3 for open.\n");
    exit(0);
  }

  int hook = atoi(argv[1]);

  int i, j, k=0;
  char str[1024];
  memset(str, 0, 1024*sizeof(char));
  for (i = 2; i < argc; i++) {
    int len = strlen(argv[i]);
    for (j = 0; j < len; j++) {
      str[k++] = argv[i][j];
    }
    if (i < argc-1)
        str[k++] = ' ';
  }
  str[k++] = '\0';

  printf("Arguments given: hook=%d, debug_message=%s\n", hook, str);
  mohit(str, hook);
  exit(0);
}

