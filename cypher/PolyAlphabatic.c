//DCBAHGFEMLKJIZYXWVUTSRQPON
//TMKGOYDSIPELUAVCRJWXZNHBQF
//GOYDSIPELUAVCRJWXZNHBQFTMK

#include<stdio.h>
int numSet;
char *setOfAlpabet[5];
char setUpAlpha[26];
char plaintext[10];
char cipherText[10];

void show()
{
    printf("\n");
    for(int i=0; i<numSet; i++)
    {
        printf("%s\n",setOfAlpabet[i]);
        printf("%c\n",setOfAlpabet[i][1] );
    }
}


void encode()
{

    for(int i=0; i<strlen(plaintext); i++)
    {
        int round = i%numSet;
        int result = setOfAlpabet[round][plaintext[i]%65];
        printf("round of set = %d\nresult = %c-%d\n\n",round,result,result );
        cipherText[i] =  result;
    }
    printf("%s\n",cipherText);
}

int main()
{

    printf("====Poly nad Mono phabetic====\n");
    printf("in put amount of Alphabet sets :");
    scanf("%d", &numSet);

    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    for(int i=0; i<numSet; i++)
    {
        printf("cipherText Aphabet %d\n",i+1);
        printf("input :");
        scanf(" %s",setUpAlpha);

        setOfAlpabet[i] = malloc(strlen(setUpAlpha) + 1);
        strcpy(setOfAlpabet[i], setUpAlpha);
    }

    printf("input Plaintext- limit in 10 : ");
    scanf("%s",plaintext);
    encode();
    //show();



}
