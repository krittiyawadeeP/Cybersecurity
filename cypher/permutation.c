//done
//Once upon  a time there was a little girl called snow white
//2 4 1 3 5
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int aOrder[10];
int bOrder[10];
char text[100];
char newtext[100];
char cipher[100];
int size;
int lenNewSize;

int normalize()
{

    int j=0;
    for (int i=0; i<strlen(text); i++)
    {
        if(text[i] != ' '  && text[i] != '\n' )
        {
            if(text[i] < 'a')
                newtext[j] =  text[i]+32;
            else
                newtext[j] =  text[i];
            j++;
        }
    }
    printf("\n[Step 1] Remove spaces & convert to lowercase : \t%s\n",newtext);

    int k;
    for( k=j; k%size != 0; k++)
    {
        newtext[k] = rand() % 26 + 97;
    }

    newtext[k] = '\0';
    printf("[Step 2] Pad random characters to fit block size (%d) : \t%s\n",size,newtext);
    return k; //newSizeText
}


void permutationCipher()
{
    char cipher[100];

    for (int i = 0; i < lenNewSize; i += size)
    {
        for (int j = 0; j < size; j++)
        {
            cipher[i + bOrder[j] - 1] = newtext[i + j];
        }
    }

    cipher[lenNewSize] = '\0';
    printf("[Step 3] Permutation Cipher Result : \t\t\t%s\n", cipher);
}

int main()
{
    srand(time(NULL));
    printf("====Permutation Cipher====\n");

    printf("input text :");
    fgets(text,100,stdin);  //รวมช่องว่าง

    printf("input size of secret key : ");
    scanf("%d",&size);
    printf("Input secret key (permutation order) :\n");
    for(int i=0; i<size; i++)
    {
        printf("order %d : ",i+1);
        scanf(" %d",&bOrder[i]);
    }
    lenNewSize = normalize();
    permutationCipher();

}
