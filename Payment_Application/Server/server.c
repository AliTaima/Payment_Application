#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\card\card.h"           //---------------delete this -----
#include "..\terminal\terminal.h"	//---------------delete this -----
#include "server.h"
//the valid accounts database
ST_accountsDB_t database[255] = {	2000.0, RUNNING, "8989374615436851",
									3000.0, BLOCKED, "6317671354844040",
									4000.0, RUNNING, "7302230192665200",
									5000.0, BLOCKED, "7499520760027320",
									6000.0, RUNNING, "6994230236969710",
									7000.0, BLOCKED, "6430918395350910",
									8000.0, RUNNING, "8593572954922380",
									9000.0, BLOCKED, "6797043202807190",
									10000.0, RUNNING, "6173128629492300",
									11000.0, BLOCKED, "5807007076043875"
};
int main()
{
	printf("the balance for index 2 = %.1f", database[2].balance);
	return 0;
}