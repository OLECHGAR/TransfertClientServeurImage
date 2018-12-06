	CC = gcc -Wall -c 


bin/Liste.o : sources/Liste.c headers/Liste.h
	$(CC) -o bin/Liste.o sources/Liste.c
	

bin/Client.o : sources/Client.c headers/Client.h
	$(CC) -o bin/Client.o sources/Client.c
	
bin/LancerClient.o : sources/LancerClient.c headers/Client.h
	$(CC) -o bin/LancerClient.o sources/LancerClient.c
	

	
bin/Serveur.o : sources/Serveur.c headers/Serveur.h
	$(CC) -o bin/Serveur.o sources/Serveur.c
	
bin/LancerServeur.o : sources/LancerServeur.c headers/Serveur.h
	$(CC) -o bin/LancerServeur.o sources/LancerServeur.c	
	
	
bin/SendImage.o : sources/SendImage.c headers/SendImage.h
	$(CC) -o bin/SendImage.o sources/SendImage.c
	
bin/ReadImage.o : sources/ReadImage.c headers/ReadImage.h
	$(CC) -o bin/ReadImage.o sources/ReadImage.c
	
bin/MimeTypes.o : sources/MimeTypes.c headers/MimeTypes.h
	$(CC) -o bin/MimeTypes.o sources/MimeTypes.c
	
	
all :  bin/Liste.o  bin/LancerClient.o bin/Client.o bin/LancerServeur.o bin/Serveur.o bin/SendImage.o bin/ReadImage.o bin/MimeTypes.o 

	gcc -o bin/LancerClient bin/LancerClient.o  bin/Client.o bin/SendImage.o bin/ReadImage.o bin/Liste.o
	gcc -o bin/LancerServeur bin/LancerServeur.o  bin/Serveur.o bin/ReadImage.o bin/SendImage.o bin/Liste.o bin/MimeTypes.o 


clean : 
	rm -f bin/*
