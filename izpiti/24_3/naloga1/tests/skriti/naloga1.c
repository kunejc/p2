#include <stdlib.h>

#include "naloga1.h"

void nastavi(Vozlisce* zacetek)
{
	Vozlisce *trenutno = zacetek;
	if (trenutno->naslednje != NULL)
	{
		while (trenutno->naslednje->naslednje != NULL)
		{
			trenutno->nn = trenutno->naslednje->naslednje;
			trenutno = trenutno->naslednje;
		}
		trenutno->nn = NULL;
		trenutno = trenutno->naslednje;
	}
	trenutno->nn = NULL;
	

}

#ifndef test
int main() { return 0; }
#endif
