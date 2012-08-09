#ifndef SHA1SUM_H
#define SHA1SUM_H

#include <stdio.h>
#include <string.h>
#include "sha1.h"

void GetStringSHA1_Hex(char *input, unsigned long length, char output[41]);
void GetFileSHA1_Hex(char *filepath, char *output);

#endif //SHA1SUM_H
