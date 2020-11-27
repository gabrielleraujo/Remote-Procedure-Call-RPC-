// Versão de processo único do printmensg.c:

/* printmsg.c: print a message on the console */
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
    //printf("Message here:\n");
    char *message;
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <message>\n", argv[0]);
        exit(1);
    }
    message = argv[1];
    if (!printmessage(message)) // if is 0, false.
    {
        fprintf(stderr, "%s: couldn't print your message.\n", argv[0]);
        exit(1);
    }
    printf("Message Delivered!\n");
    exit(1);
}

/* Print a message to the console.
* Return a boolean indicating whether
* the message was actually printed. */

printmessage(char *msg)
{
    printf("%s\n", msg);
    return(1);
}

/*Para uso local em uma única máquina, este programa pode ser compilado e executado da seguinte forma:

* If you stay on Windows VS Code, so press the F6 to open a C/C++ run compile.

* $ cc printmsg.c -o printmsg
* $ ./printmsg "Hello, there."
* Message delivered!
* $
*/

// Se a função de impressão() for transformada em um procedimento remoto,ela pode ser chamada de qualquer lugar da rede. rpcgen torna mais fácil fazer isso:

