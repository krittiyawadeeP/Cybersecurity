#include<stdio.h>
    int key;
    char planText[10];
    char cipherText[10];
    int choice;

    void Cipher(sighn){
    printf("in put Key : ");
    scanf("%d", &key);
    printf("\nin put Text(uppercase) : ");
    scanf("%s", planText);
    printf("\nafter = \n");

    for(int i=0; i<strlen(planText); i++)
    {
        int result = (planText[i]-'A'+(key*sighn)%26)+'A'; //notshure

        printf("%c -> %c\n", planText[i],result);
        cipherText[i] = result;
    }

    //for(int i=0;i<10;i++)
    printf("result = %s\n", cipherText);

    }

int main()
{

    printf("====Shift Cipher====\n"); //\n+++encode++\nin put String limit in 10\n");
    printf("encode(1) or decode(0) : ");
    scanf("%d",&choice);

    if(choice)
    {
    printf("encode");
        Cipher(1);
    }
    else
    {
     printf("decode");
         Cipher(-1);
    }
}
