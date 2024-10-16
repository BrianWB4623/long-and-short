#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

 int main(int argc, char *argv[]){
    int countUp=0;//counter for line uppercase
    int countLow=0;//counter for lines lowercase
    if(argc!=4){//makes sure put in 3 arguments
        printf("Must supply 3 arguments, 1.File to read, 2.File to write upper, 3.Another File to Write lower");
        exit(1);
    }
    FILE *in=fopen(argv[1],"r");//opens read file
    FILE *out1=fopen(argv[2],"w");//opens write file 1
    FILE *out2=fopen(argv[3],"w");//opens write file 2

    if (!in||out1==NULL||out2==NULL){//Do they open
        printf("Cant open file for reading\n");//error
        exit(1);
    }
    while(!feof(in)){//while we are not done with read file
        char line[1000];//makes a string to holf the line
        fgets(line, 1000, in);//takes in the line
        if(strlen(line)<20){//is the length less than 20
            for(int i=0;line[i];i++)//iterates
            line[i]=toupper(line[i]);//sets to uppercase
            fprintf(out1,"%s\n",line);//prints to out1
            countUp++;//increments
        }
        else if(strlen(line)>=20){//same just with lowercase
            for(int i=0;line[i];i++)
            line[i]=tolower(line[i]);
            fprintf(out2,"%s\n",line);
            countLow++;
        }
        //printf("%s", line);
    }
    printf("%d lines printed to %s\n",countUp,argv[2]);
    printf("%d lines printed to %s\n",countLow,argv[3]);
    fclose(in);
    fclose(out1);
    fclose(out2);
    
    //return 0;
 }