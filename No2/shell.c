#include "common.h"
#include "shell.h"

#define MAX_COMMAND_LEN         100

void shell(void)
{
    unsigned short com[MAX_COMMAND_LEN];

    while (TRUE) {
        puts(L"wcatOS> ");
        if (gets(com, MAX_COMMAND_LEN) <= 0)
            continue;

        if (!strcmp(L"hello", com))
            puts(L"Hello UEFI!\r\n");
        else if (!strcmp(L"Nim", com))
            puts(L"I like Nim.\r\n");
        else if (!strcmp(L"cls", com))
            cls();
        else
            puts(L"Command not found.\r\n");     
    }
}
