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


int main(void) {
	int sock;
	char nom[MAX]="";
	char PATH[MAX]="";
	int x;
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


	label:printf("*******  Pour 'Download' tapez 1 , pour 'Upload' tapez 2 :  *********\n") ;
	scanf("%d",&x);
	sendchoix( x , sock) ;
	switch(x)
	{
		case 1 : printf("****************************  Download  *****************************\n"); 
		printf("***************************  ListeImages  *****************************\n");
		char tmp[MAX];
		int i;
		for (i = 0 ; i<MAX ;i++)
		{ 
			read(sock,tmp,MAX);	
			if(strcmp(tmp,"sortie")==0){break;}
				printf("%s\n", tmp);
               }
        printf("***************  Entrez le nom de votre photo  *********************\n");
        scanf("%s", nom);
        printf("le nom est : %s", nom);
        write(sock,nom,MAX);

	      receive_image(sock);
	      moveDownload();
	      afficher_image("../doc/DownloadImages/ImagesTestes");

	  break;  
	  
	case 2 : printf("****************************  Upload  *******************************\n");
	         printf("***************  Entrez le path de votre photo  ********************\n");
	         scanf("%s",PATH);
	         
	         send_image(sock, PATH);
            
             break;
             
	default : printf("***********************  Nombre entré inconnu  **********************\n");goto label;
	
	  }
	  

    return EXIT_SUCCESS;

}

