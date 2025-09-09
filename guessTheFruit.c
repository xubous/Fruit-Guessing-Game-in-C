#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define null NULL
#define endl printf ( "\n" )
#define maxWords 26


void clear ( );
void menu ( );
int readInt ( char * );
char readChar ( char * );
void getcharCleanLine ( );
FILE * readFile ( );
char * * listWords ( FILE * );
void draw ( char *, int, char * );
void lettersAreadyTyped ( char [ ], int );
void compare ( char *, int );
void start ( );


void clear ( )
{
    #ifdef _WIN32
        system ( "cls" );
    #else
        system ( "clear" );
    #endif
}

void menu ( )
{
    printf ( "%s\n", "----------------------------------------" );
    printf ( "\n%s\n\n", " Try To Guess What The Fruit Is  :) " );
    printf ( "%s\n", " 0 - Exit" );
    printf ( "%s\n\n", " 1 - Play" );
    printf ( "%s\n", "----------------------------------------" );
}

int readInt ( char * string )
{
    int a = 0;

    printf ( "%s\n", string );
    scanf ( "%d", & a );

    return a;
}

char readChar ( char * string )
{
    char a = 0;

    printf ( "%s\n", string );
    scanf ( " %c", & a );

    return tolower ( a );
}

void getcharCleanLine ( )
{
    int c;
    while ( ( c = getchar ( ) ) != '\n' && c != EOF );
}

FILE * readFile ( )
{
    FILE * file = fopen ( "words.txt", "r" );

    if ( ! file )
    {
        file = fopen ( "words.txt", "w" );

        if ( ! file )
        {
            printf ( "%s\n", "File Not Founded" );
            return null;
        }

        const char * words [ ] = {
            "Abacaxi","Acerola","Amora","Banana","Caju","Coco","Framboesa","Goiaba","Graviola","Jabuticaba","Kiwi","Laranja","Limao","Maca","Mamao","Manga","Maracuja","Melancia","Melao","Morango","Pera","Pessego","Pitanga","Roma","Tangerina","Uva"
        };

        for ( int i = 0; i < maxWords; i ++ )
        {
            fprintf ( file, "%s\n", words [ i ] );
        }

        fclose ( file );
        file = fopen ( "words.txt", "r" );
    } else
        {
            printf ( "%s\n", "File Founded" );
        }

    return file;
}

char * * listWords ( FILE * file )
{
    char * * array = ( char * * ) malloc ( maxWords * sizeof ( char * ) );

    if ( ! array ) return null;
     
    int i = 0;
    char assistant [ 50 ];

    while ( i < maxWords && fscanf ( file, "%s", assistant ) != EOF )
    {
        // printf ( "%s\n", assistant );
        array [ i ] = ( char * ) malloc ( ( strlen ( assistant ) + 1 ) * sizeof ( char ) );

        strcpy ( array [ i ], assistant );
        i ++;
    }

    // for ( int i = 0; i < maxWords; i ++ )
    // {
    //     printf ( "%s\n", array [ i ] );
    // }

    return array;
}

void draw ( char * wordSorted, int lenWordSorted, char * correctLetters )
{
    clear ( );
    endl;

    for ( int i = 0; i < lenWordSorted; i ++ )
    {
        if ( correctLetters [ i ] )
        {
            printf ( " %c ", wordSorted [ i ] );
        } else
            {
                printf ( " _ " );
            }
    }

    endl;
    endl;
}

void lettersAreadyTyped ( char lettersTyped [ ], int lettersTypedSize )
{
    if ( lettersTypedSize > 0 )
    {
        endl;
        printf ( " Letters typed: ( " );
        for ( int i = 0; i < lettersTypedSize; i ++ )
        {
            printf ( "[%c]  ", lettersTyped [ i ] );
        }
        printf ( " )" );
        endl;
    }
}

void compare ( char * wordSorted, int lenWordSorted )
{
    char lettersTyped [ 26 ] = { 0 };
    int index = 0;

    char * correctLetters = ( char * ) calloc ( lenWordSorted, sizeof ( char ) ) ;
    if ( ! correctLetters ) return ;

    int newSizeWordSorted = lenWordSorted;
    char option;

    while ( newSizeWordSorted > 0 )
    {
        draw ( wordSorted, lenWordSorted, correctLetters );
        lettersAreadyTyped ( lettersTyped, index );
        option = readChar ( "\n Write A Letter :" );

        if ( option == '/' )
        {
            break;
        }

        int alreadyType = 0;

        for ( int i = 0; i < index; i ++ )
        {
            if ( lettersTyped [ i ] == option )
            {
                alreadyType = 1;
                break;
            }
        }

        if ( alreadyType )
        {
            printf ( "Try Other Letter!\n" );
            getcharCleanLine ( );
            getchar ( );
            continue;
        }

        lettersTyped [ index ++ ] = option;

        int check = 0;

        for ( int i = 0; i < lenWordSorted; i ++ )
        {
            if ( tolower ( wordSorted [ i ] ) == option && ! correctLetters [ i ] )
            {
                correctLetters [ i ] = 1;
                newSizeWordSorted --;
                check = 1;
            }
        }

        if ( ! check )
        {
            printf ( " \nClick Enter And Try Again !\n" );
            getcharCleanLine ( );
            getchar ( );
        }

    }
    clear ( );
    printf ( " You Win ! Word : %s\n\n", wordSorted );
    printf ( " Enter To Continue...\n\n" );
    getcharCleanLine ( );
    free ( correctLetters );
}

void start ( )
{
    srand ( time ( null ) );

    FILE * file = readFile ( );
    char * * list = listWords ( file );
    int index = rand ( ) % maxWords;
    int lenWordSorted = strlen ( list [ index ] );
    char * wordSorted = ( char * ) malloc ( ( lenWordSorted + 1 ) * sizeof ( char ) );

    strcpy ( wordSorted, list [ index ] );

    fclose ( file );
    for ( int i = 0; i < maxWords; i ++ )
    {
        free ( list [ i ] );
    }
    free ( list );

    compare ( wordSorted, lenWordSorted );
    free ( wordSorted );
    endl;
}


int main ( )
{
    int option = 0;

    clear ( );
    
    do
    {
        clear ( );
        menu ( );
        option = readInt ( "Choose An Option :" );

        switch ( option )
        {
            case 0 :  
            {
                clear ( );
                printf ( "End\n" );
                break;
            }

            case 1 :
            {
                clear ( );
                start ( );
                getcharCleanLine ( );
                break;
            }

            default: break;
        }

    } while ( option != 0 );
    

    return 0;
}
