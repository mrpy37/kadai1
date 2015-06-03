// created by Mariko Ono

/* 今できている段階のところまで，提出します．
 　 さらに今回はまだC++をあまり勉強できていないので
 　　Cのコードになっています．
 　　またあとで提出させてください．*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 256

char *alpha_sort( char *words )
{
    int i, j;
    char temp;
    int size ='a'-'A';
    
    for( i = 0; words[i]!=0; i++ ){
        for( j = i+1; words[j] != 0; j++ ){
            if( words[j]>='a' || words[j] == '\n' )
            {
                words[j] = words[j];
            }
            else{
                words[j] = words[j] + size;
            }
            
            if( words[i] > words[j] ){
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    return words;
}


int main( void )
{
    int i, j;
    char array[BUFFER];
    char words[BUFFER];
    char *ans;
    
    printf( "Insert text : " );
    scanf( "%s", array );
    //    length = strlen(array);
    
    alpha_sort( array );
    
    FILE *fp;
    char *filename = "dic.txt";
    char readline[BUFFER] = {'\0'};
    
    /* ファイルのオープン */
    if ( (fp = fopen(filename, "r")) == NULL ) {
        fprintf(stderr, "Error.\n");
        exit(EXIT_FAILURE);
    }
    
    /* ファイルの終端まで文字を読み取り表示する */
    while ( fgets(readline, BUFFER, fp) != NULL ) {
        strcpy( words, readline );
        alpha_sort(words);
        
        /* wordsにarrayが含まれたときwordsの元単語を表記 */
        if( strstr(words, array)!=NULL )
            //if( strstr(array, words)!=NULL )
            printf( "%s", readline );
    }
    
    /* ファイルのクローズ */
    fclose(fp);
    
    //入力した文字をソートしたものを表記
    printf("%s\n", array );
    
    return 0;
}
