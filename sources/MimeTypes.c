#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/MimeTypes.h"

 int find(char *fileName,char *strSearch) {

  FILE *f;
  char c;
  int found=0;
  int pos=0;
  int length;

  f = fopen(fileName,"r");
  if( f == NULL )
    return 0;

  length=strlen(strSearch);

  while( fread(&c,1,1,f)>0 && !found ) {

    if( c==strSearch[pos] ) {
      pos++;
    } else {
      if(pos!=0) {
        // On doit rembobiner !
        fseek(f,-pos,SEEK_CUR);
        pos=0;
      }
    }

    found = (pos==length);

  }
  fclose(f);

  return found;

}
int MimeTypes()
{
    int c;
    FILE *sortie = popen("file --mime-type -b ../doc/UploadImages/ImageTest>../doc/fichier.txt", "r");
    if(sortie == NULL)
    {
        perror("Erreur popen ");
        exit(EXIT_FAILURE);
 
    }
    
    while ((c = fgetc(sortie)) != EOF )
		 putchar(c);
       
   
    pclose(sortie);
    int res;
     char chaine[100];
    FILE* fichier = fopen("../doc/fichier.txt","r");
    if (fichier!=NULL)                          
    fgets(chaine,80,fichier);
    res=find("../doc/Images/MimeTypes.txt",chaine);
return res ; 
}

// Retourne 1 si la chaine est trouve dans le
// fichier specifie, sinon 0 
