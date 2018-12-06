#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>   
#include <unistd.h>  
#include <stdlib.h>


   #include <errno.h>
#include "../headers/SendImage.h"
#define MAX 500
  //Send Choix
void sendchoix(int x , int sock)
{ write(sock,&x,sizeof(x));
	}


   void send_image(int socket, char* PATH){

   FILE *picture;
   int size, read_size, stat, packet_index;
   char send_buffer[10240], read_buffer[256];
   packet_index = 1;
  //path d'image
   picture = fopen(PATH, "r");
   printf("Getting Picture Size\n");   

   if(picture == NULL) {
        printf("Error Opening Image File"); } 

   fseek(picture, 0, SEEK_END);
   size = ftell(picture);
   fseek(picture, 0, SEEK_SET);
   printf("Total Picture size: %i\n",size);

   //Send Picture Size
   printf("Sending Picture Size\n");
   write(socket, (void *)&size, sizeof(int));

   //Send Picture as Byte Array
   printf("Sending Picture as Byte Array\n");

   do { //Read while we get errors that are due to signals.
      stat=read(socket, &read_buffer , 255);
      printf("Bytes read: %i\n",stat);
   } while (stat < 0);

   printf("Received data in socket\n");
   printf("Socket data: %s\n", read_buffer);

   while(!feof(picture)) {
   //while(packet_index = 1){
      //Read from the file into our send buffer
      read_size = fread(send_buffer, 1, sizeof(send_buffer)-1, picture);

      //Send data through our socket 
      do{
        stat = write(socket, send_buffer, read_size);  
      }while (stat < 0);

      printf("Packet Number: %i\n",packet_index);
      printf("Packet Size Sent: %i\n",read_size);     
      printf(" \n");
      printf(" \n");


      packet_index++;  

      //Zero out our send buffer
      bzero(send_buffer, sizeof(send_buffer));
     }
    }

	
void afficher_image(char* PATH) {
	char chaine [50]= "eog ";
	strcat(chaine,PATH);
	system(chaine);
}
void moveDownload()
{
	char* tab="mv ImageTestes ";
	char rest[50]="../doc/DownloadImages";
	strcat(tab,rest);
	printf("%s",tab);
	system(tab);
}


