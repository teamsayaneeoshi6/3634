#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "functions.h"
#include "functions.c"
/
int main (int argc, char **argv) {

	//seed value for the randomizer 
  double seed = clock(); //this will make your program run differently everytime
  //double seed = 0; //uncomment this and your program will behave the same everytime it's run

  srand(seed);

  int bufferSize = 1024;
  unsigned char *message = (unsigned char *) malloc(bufferSize*sizeof(unsigned char));

  printf("Enter a message to encrypt: ");
  int stat = scanf (" %[^\n]%*c", message); //reads in a full line from terminal, including spaces

  //declare storage for an ElGamal cryptosytem
  unsigned int n, p, g, h;

  printf("Reading file.\n");

  /* Q2 Complete this function. Read in the public key data from public_key.txt,
    convert the string to elements of Z_p, encrypt them, and write the cyphertexts to 
    message.txt */

  //First, use n, p, g, h from public_key.txt to encrypt message

  FILE *file;
  file=fopen("public_key.txt","r");

  if(file!=NULL){

    fscanf("%u \n%u \n%u \n%u \n",n,p,g,h);

  }
  fclose(file);

  //Convert message to int
  unsigned int Z;
  convertStringToZ(message,strlen(message),*Z,strlen(message));

  //Encrypt
  unsigned int Nints=strlen(message)/sizeof(Z);
  unsigned int *a=(unsigned int *)malloc(Nints*sizeof(unsigned int));
  
  ElGamalEncrypt(Z,*a,Nints,p,g,h);
  
  //Z is now encrypted
  //write into message.txt

  file=fopen("message.txt","w");

  fprintf("%d \n",sizeof(Z));
  for(int j=0;j<sizeof(Z);j++){
  
     fprintf("%d %d \n",Z[j],a[j]);
  
  }
  
  return 0;
}




























