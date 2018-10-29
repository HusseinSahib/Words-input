/*
Author: Hussein Sahib
Date: 10/21/2018
This program asks user to input how many words they wish to enter and out puts the same words in a different format
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int wordnum();
void takeinp(char**, int i);
void printarr(char**,int);

int main()
{
    int wordcount = wordnum();
    char** sentence;
    sentence = malloc(wordcount* sizeof(char*));
    for (int i = 0; i < wordcount; i++)
    {
        sentence[i] = malloc(30 * sizeof(char));
    }
    takeinp(sentence,wordcount);
    printarr(sentence,wordcount);
    for (int i = 0; i < wordcount; i++)
    {
        free(sentence[i]);
    }
    free(sentence);
    return 0;
}

int wordnum()
{
    int count;
    printf("How many words do you wish to enter?");
    scanf("%d",&count);
    return count;
}

void takeinp(char** sentence, int wordcount)
{
    char** words;
    words = malloc(wordcount * sizeof(char*));
    printf("Enter %d words now:", wordcount);
    for (int i = 0; i < wordcount; i++)
    {
        words[i] = malloc(30 * sizeof(char));
        scanf(" %s", words[i] );
    }
    for (int j = 0; j < wordcount; j++)
    {
        strcpy(sentence[j], words[j]);
    }
    for (int i = 0; i < wordcount; i++)
    {
        free(words[i]);
    }
    free(words);
    return 0;
}
void printarr(char** sentence, int leng)
{
    int i;
    printf("Here are your words:");
    for(i=0; i < leng; i++ )
    {
        printf("\n%s",*(sentence+i));
    }
}
