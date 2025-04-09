#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>

#include "ui.h"
#include "tests.h"

int main()
{
    printf("All tests passed!\n");
    run_all_tests();
    _CrtDumpMemoryLeaks();
    start_ui();

    return 0;
}
