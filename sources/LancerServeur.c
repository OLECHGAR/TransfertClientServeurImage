#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

#include "../headers/Serveur.h"

#include "../headers/ReadImage.h"

#include "../headers/SendImage.h"

#include "../headers/Liste.h"

#include "../headers/MimeTypes.h"





int main(void) {
 
 /* Socket et contexte d'adressage du client */
  struct sockaddr_in csin;
  int csock,sock,x;
 
   char PATH[]= "../doc/Images/";
   	      
   char nom[MAX]="";

  
  sock = serveur_socket();
  if(sock ==-1)
   perror("erreur creation sock");
  socklen_t crecsize = sizeof(csin);
  /* Attente d'une connexion client */
	
	while(1){
	  csock = accept(sock, (struct sockaddr*)&csin, &crecsize);
	  int pid = fork();
	  if(pid == 0){    
      label:printf("********* Un client se connecte avec la socket %d de %s:%d **********\n  ",csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port)); 
       x=readchoix(csock);
       switch(x)
       { case 1 : printf("****************************  Download  *****************************\n");
		   printf("***************************  ListeImages  *****************************\n");
		 
		 char ** t = (char **) malloc(MAX * sizeof(char *));

		 t = dirtab("../doc/Images");
		 
        int i;
		for (i = 0 ; t[i] != NULL; i++)	
		{  write(csock,t[i],MAX);
			printf("%s\n", t[i]);
	     }
	     write(csock,"sortie",MAX);
	     

	     read(csock,nom,MAX);
	     
	     printf("le nom est: %s", nom);
	     strcat(PATH,nom);
	     send_image(csock,PATH);
 		strcpy(PATH,"");
	     goto label;
		   break;
		   
	     case 2 : printf("****************************  Upload  *******************************\n");

	      receive_image(csock,2);
	      int res;
	     /* res= MimeTypes();
	      if(res==0)
	      {
	      	 unlink ("../doc/UploadImages/ImageTestes");goto label;
		  }*/
              goto label;
      
	     break;
             
             case 0 :
	  shutdown(csock,2);
	  close(csock);
	  close(sock);
            printf("****************************  Good By  *******************************");
          exit (0);   
                 default : goto label;break ;
		   
		   }

	  return EXIT_SUCCESS;   	
		  
		   }
		   }
		  

}
