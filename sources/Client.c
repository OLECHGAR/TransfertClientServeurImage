#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/Client.h"
#include "../headers/UploadClient.h"


int client_socket()
{
	int sock;
  struct sockaddr_in sin;
  
  /* Creation de la socket */
  sock = socket(AF_INET, SOCK_STREAM, 0);
 
  /* Configuration de la connexion */
  
  sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
 
  /* Tentative de connexion au serveur */
  
  connect(sock, (struct sockaddr*)&sin, sizeof(sin));
  printf("************* Connexion a %s sur le port %d ****************\n", inet_ntoa(sin.sin_addr),htons(sin.sin_port));

  if(sock)
  return sock;
  else
  return -1;
	}
