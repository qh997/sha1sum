#include "sha1sum.h"

int main()
{
    char out[41];
    GetStringSHA1_Hex("abc", 3, out);
    printf("%s\n", out);

    GetFileSHA1_Hex("/home/gengs/Documents/HR/copy.xls", out);
    printf("%s\n", out);

    return 0;
}

void toHexString(SHA1Context sha1, char output[41])
{
    strcpy(output, "");
    
    for(int i = 0; i < 5 ; i++)
    {
        char str[9];
        sprintf(str, "%x", sha1.Message_Digest[i]);
        strcat(output, str);
    }
}

void GetStringSHA1_Hex(char *input, unsigned long length, char output[41])
{
    if (NULL == input || NULL == output)
        return;

    SHA1Context sha1;

    SHA1Reset(&sha1);
    SHA1Input(&sha1, input, length);
    SHA1Result(&sha1);

    toHexString(sha1, output);
}

void GetFileSHA1_Hex(char *filepath, char *output)
{
    SHA1Context sha1;
    FILE *file  = NULL;
    int len = 0;
    unsigned char buffer[0x0400] = {0};

    file = fopen(filepath, "rb");

    if (NULL == (file = fopen(filepath, "rb")))
        return;

    SHA1Reset(&sha1);

    while (len = fread(buffer, 1, 1024, file))
    {
        SHA1Input(&sha1, buffer, len);
    }

    fclose(file);

    SHA1Result(&sha1);
    toHexString(sha1, output);

    return;
}