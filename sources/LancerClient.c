#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>  
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  
#include <sys/file.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>  
#include "../headers/Client.h" 
#include "../headers/ReadImage.h" 
#include "../headers/SendImage.h" 
#include "../headers/Liste.h"

int main(void) 
{
	int sock; 
	char nom[MAX]=""; 
	char PATH[MAX]=""; 
	int x; 
	char tmp[MAX];
	char c;
	FILE *fic;
	
	sock =client_socket();  
	if(sock==-1) 
		perror("erreur creation sock");   
	printf("*********************************************************************\n"); 
	printf("*********************************************************************\n"); 
	printf("*********************** LECHGAR Othman ******************************\n"); 
	printf("************************ ZAHIR Loubna *******************************\n"); 
	printf("************************* ABBOU Manal  ******************************\n"); 
	printf("************************* ATIF Kenza ********************************\n"); 
	printf("*********************************************************************\n"); 
	printf("*********************************************************************\n");  
	while(1)
	{ 
		label: printf("*******  Pour 'Download' tapez 1 , pour 'Upload' tapez 2 :  *********\n") ; 
		printf("************************ Pour Quiter 0 ******************************\n") ; 
		scanf("%d",&x); 
		sendchoix( x , sock) ; 
		switch(x) 
		{ 
			case 1 : printf("****************************  Download  *****************************\n"); 
			printf("***************************  ListeImages  *****************************\n");

                char T[MAX][MAX];
		 char P[MAX][MAX];
		int i;
		for (i = 0 ; i<MAX ;i++)
		{ 
			read(sock,tmp,MAX);	
			if(strcmp(tmp,"sortie")==0){strcpy(T[i],"stop");break;}
			strcpy(T[i],tmp);
              

               }
               for (i = 0 ;  i<MAX;i++)
		{ 
				
		        strcpy(P[i],T[i]);}

              label2:for (i = 0 ;strcmp( P[i], "stop")!=0 ;i++)
		{ 
				
		        printf("%s\n", P[i]);

}
        printf("***************  Entrez le nom de votre photo  *********************\n");
        scanf("%s", nom);
        printf("le nom est : %s \n", nom);
	int j = 0 ;
      for(j=0 ;j<MAX;j++)
       { if(strcmp(nom,T[j])==0)
        {
        write(sock,nom,MAX);
        receive_image(sock,1);
        afficher_image("../doc/DownloadImages/ImageTest");
        goto label;}}
         
        printf("*********  Photo non disponible dans la liste d'images  ***********\n");goto label2;


			case 2 : printf("****************************  Upload  *******************************\n"); 
			printf("***************  Entrez le path de votre photo  ********************\n"); 
			scanf("%s",PATH); 
			send_image(sock, PATH); 
			strcpy(PATH,""); 
			printf("************************ Incompatible file ***************************\n"); 
			printf("************************   Avec ces types  ***************************\n");
			read(sock, tmp , MAX); 
			//afficher mimetype 
			fic=fopen("../doc/Images/MimeTypes.txt","r" );
			while(EOF != (c = fgetc(fic)))
			{
				if (c != '\n')
				{
					fscanf(fic,"%s",tmp);
					printf("%s\n",tmp);
				}
			}
			goto label;  
			
			case 0 :     return 0; 
			
			default : printf("***********************  Nombre entré inconnu  **********************\n");
			goto label;
			break;  
		}  
	}  
	return EXIT_SUCCESS; 
} 
