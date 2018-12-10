#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dirent.h"
#include "../headers/Liste.h"

char ** dirtab(const char * s){
		int i, j;
		DIR * dir;
		struct dirent * e;
		i = 0;//compte les noms
		j = 0;//compte la somme des tailles des moms
		dir = opendir(s);
		while ((e = readdir(dir))){
			if ((strcmp(e -> d_name, ".") && strcmp(e -> d_name, ".."))){//on n'a pas besoin de . et .. 
				j += strlen(e -> d_name) + 1;// + 1 pour le 0 terminal
				i++;
			}
		}
 
		char ** p = (char **) malloc((i + 1) * sizeof(char *));//on alloue la place pour le tableau + 1 pour NULL
		char * r = (char *) malloc(j);//on alloue la place pour toutes les chaînes en tas
 
		rewinddir(dir);//on recommence la lecture
		i = 0;
		while ((e = readdir(dir))){
			if (strcmp(e -> d_name, ".") && strcmp(e -> d_name, "..")){
				p[i++] = strcpy(r, e -> d_name);    //on copie les caractères du nom dans le tas, et son pointeur dans le tableau
				r += strlen(r) + 1;              //mise à jour du pointeur de caractères du tas
			}
		}
		p[i] = NULL;
		closedir(dir);	
		return p;
}
