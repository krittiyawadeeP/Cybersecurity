//THISISATESTMESSAGE
//SESAME

#include<stdio.h>
int main()
{
    char secretKey[10];
    char plaintext[20];
    char ciphertext[20];

    printf("====Vigenere Cipher====\n");
    printf("input Secret Key(limit10) :");
    scanf("%s",secretKey);
    printf("input Plaintext :");
    scanf("%s",plaintext);

    for(int i=0,j=0; i<strlen(plaintext); j++,i++)
    {
        printf("secretKey = %d, %c(%d)\n",j%strlen(secretKey),secretKey[j%strlen(secretKey)],secretKey[j%strlen(secretKey)]);
        int result = (((secretKey[j%strlen(secretKey)])+plaintext[i])%65)%26;
        printf("result = %c(%d)\n\n",result+65,result+65);
        ciphertext[j] = result+65;
    }


    printf("ciphertext = %s\n",ciphertext);
    /*
    for(int i=0,j=0;i<strlen(plaintext);j++,i++)
    {
        //for(int j=0;j<strlen(secretKey);j++)
        //{
            printf("j Mod strlen(secretKey) = %d, %c(%d)\n",j%strlen(secretKey),secretKey[j%strlen(secretKey)],secretKey[j%strlen(secretKey)]);

            int result = (((secretKey[j%strlen(secretKey)])+plaintext[i]))%90; //ถ้า % 90 จะได้ค่า 0–89
            printf("%d -%c\n]\n",result,result);
            ciphertext[j] = result;
        //}
    }
    printf("ciphertext = %s\n",ciphertext);*/

    return 0;
}
