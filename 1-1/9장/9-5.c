/*
#include <stdio.h>
#include <string.h>

void main()
{
    char sentence[100] = "";
    char word[20];

    do {
        printf("�ܾ�? ");
        scanf("%s", word);
        strcat(sentence, word);         // �Է¹��� �ܾ sentence�� ���� ���δ�.
        strcat(sentence, " ");          // �ܾ ������ �� �ֵ��� ��ĭ�� ���δ�.
    } while (strcmp(word, ".") != 0);   // "."�� �Էµ� ������ �ݺ��Ѵ�.

    printf("%s\n", sentence);
}
*/