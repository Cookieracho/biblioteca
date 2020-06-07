int libs(struct biblio libros[100],int cantl)
{	
	//--------------VARIABLES---------------
	int op,i,j,k,v,letra,cunt=0;
	char num[' '];
	
	/*
		cantl-> Cantidad de libros encontrados en el archivo
		op->Variable de control de opciones
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo 
		k->	Variable de control de posicion
		v-> Variable de control de posicion
	//	letra-> Variable que indica que hay una palabra
		cunt-> Numero de libros existentes
	*/
	//--------------------------------------


	cunt=cantl;
    FILE * filelib;
    filelib=fopen("libros1.txt","r+");
    
   
	do{	
		system("cls");
		printf("\n\n\n\t\t MENU LIBROS:\n\n");
		printf("\t\t 1) Agregar un libro \n\t\t 2) Eliminar un libro \n\t\t 3) Buscar un libro \n\t\t 4) Reportes \n\t\t 5) Volver al menu principal\n");	
		printf("\n\t\t Escriba el numero de su eleccion: ");
		do{
			//Validacion de que el numero ingresado no sea una letra
			do{
				fflush(stdin);
	        	gets(num);
	        	// Valida
			    //---------------------------------------------
			    if(validar_entero(num)==1)
			    	printf("\n\n\t La opcion ingresada no es valida. Introduzca un numero entero mayor a cero: ");
		   		
   			}while(v==1);
	    	op=atoi(num);
	    	//---------------Validacion de opciones--------------
	    	if(op!=1 && op!=2 && op!=3 && op!=4 && op!=5)
	    		printf("\n\n\t La opcion ingresada no es valida. Introduzca un numero del 1 al 5: ");
	   		//-------------------------------------------------------
		}while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5);
	
		//--------Evaluacion de opciones---------
		switch (op){
			case 1: cunt=add(libros,cunt);
					break;
			case 2: rip(libros,cunt);
					cunt--;
					break;
			case 3: search(libros,cunt);
					break;
			case 4: reportes(libros,cunt);
					break;
			case 5: system("cls");
					gotoxy(20,20);
					printf("Volviendo al men� principal...");
					break;											
		}
		//---------------------------------------
	}while(op!=5);
	//---------------Actualizacion del archivo principal de libros--------
	for(i=0;i<cunt;i++){
		fprintf(filelib,"%s\n",libros[i].clave); 		//Clave del libro
		fprintf(filelib,"%s\n",libros[i].autor); 		//Autor del libro
		fprintf(filelib,"%s\n",libros[i].titulo); 		//Titulo del libro
		fprintf(filelib,"%s\n",libros[i].pais); 		//Pa�s de origen del libro
		fprintf(filelib,"%s\n",libros[i].editorial); 	//Editorial del libro
		fprintf(filelib,"%d\n",libros[i].cat); 			//Categoria del libro
		fprintf(filelib,"%d\n",libros[i].edi); 			//Numero de de edicion del libro
		fprintf(filelib,"%d\n",libros[i].exi); 			//Cantidad de libros en existencia del libro
		fprintf(filelib,"%d\n",libros[i].dia); 			//Dia de publicacion del libro
		fprintf(filelib,"%d\n",libros[i].mes); 			//Mes de publicacion del libro
		fprintf(filelib,"%d\n",libros[i].ano); 			//A�o de publicacion del libro
		
	}
	
	fclose(filelib);
	return 0;
	
}

//------------AGREGAR LIBRO-------------
int add(struct biblio libros[100],int cunt){
	char num[' ']; //Variable auxiliar para las validaciones
	int booleano;  //Varaible que actua como bool que nos auxilia para las validaciones 
	int dia,mes,ano; //Variables enteras que nos sirven para validar la fecha de publicacion 
	int i;			//Variable de control de ciclo
	int c,j,lenaut; // Contador, variable de control de ciclo, y variable de longitud de cadena
	int op;			//Variable de control de opciones
	do{
	
	system("cls");
	printf("\n\n\t AGREGAR LIBRO \n\n");
	
		printf("\t Introduzca el titulo: ");
		fflush(stdin);
		gets(libros[cunt].titulo);
		// Convierte todo a mayusculas (asi como los siguientes ciclos despues del gets)
		for(j=0;libros[cunt].titulo[j]!='\0';j++)
			libros[cunt].titulo[j]= toupper(libros[cunt].titulo[j]);
		
		printf("\n\n\t Introduzca el nombre del autor: ");
		fflush(stdin);
		gets(libros[cunt].autor);
		for(j=0;libros[cunt].autor[j]!='\0';j++)
			libros[cunt].autor[j]= toupper(libros[cunt].autor[j]);
		
		printf("\n\n\t Introduzca la categoria del libro a a�adir\n\n 000 --- Inform�tica, informaci�n y obras generales\n\n ");
		printf("100 --- Filosof�a y psicolog�a\n\n");
		printf("200 --- Religi�n\n\n");
		printf("300 --- Ciencias sociales\n\n");
		printf("400 --- Lengua\n\n");
		printf("500 --- Ciencia\n\n");
		printf("600 --- Tecnologia y ciencia aplicada\n\n");
		printf("700 --- Arte y recreaci�n\n\n");
		printf("800 --- Literatura\n\n");
		printf("900 --- Historia y geografia\n\n");
		do
		{
			do
			{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);
				
				if(booleano ==0)
				{
					printf("\n\nLa categoria ingresada no es valida!\n");
					printf("Por favor introduzca una categoria valida\n\n");
				}
			}while(booleano==0);
			libros[cunt].cat=atoi(num);
			if(libros[cunt].cat!=0 && libros[cunt].cat!=100 && libros[cunt].cat!=200 && libros[cunt].cat!=300 && libros[cunt].cat!=400 && libros[cunt].cat!=500 && libros[cunt].cat!=600 && libros[cunt].cat!=700 && libros[cunt].cat!=800 && libros[cunt].cat!=900)
			{
				printf("\n\n La categoria ingresada no es valida!\n");
				printf("Por favor introduzca una categoria valida\n\n");
			}
		}while(libros[cunt].cat!=0 && libros[cunt].cat!=100 && libros[cunt].cat!=200 && libros[cunt].cat!=300 && libros[cunt].cat!=400 && libros[cunt].cat!=500 && libros[cunt].cat!=600 && libros[cunt].cat!=700 && libros[cunt].cat!=800 && libros[cunt].cat!=900);
		
		printf("Introduzca el nombre de la editorial: ");
		fflush(stdin);
		gets(libros[cunt].editorial);
		for(j=0;libros[cunt].editorial[j]!='\0';j++){
			libros[cunt].editorial[j]= toupper(libros[cunt].editorial[j]);
		}
		
		printf("Introduzca el pa�s: ");
		fflush(stdin);
		gets(libros[cunt].pais);
		for(j=0;libros[cunt].pais[j]!='\0';j++){
			libros[cunt].pais[j]= toupper(libros[cunt].pais[j]);
		}
		
		//..............Validacion de numero de edicion..........
		do{
			printf("Introduzca el numero de edicion: ");
			fflush(stdin);
			gets(num);
			booleano = revisarInt(num);
			
			if(booleano ==0)
			{
				printf("\n\n El numero de edicion que ingreso no es valido!\n");
				printf("Por favor introduzca un valor entero: \n\n");
			}
			
		}while(booleano==0);
		libros[cunt].edi=atoi(num);
		
		//...............VALIDACI�N DE CANTIDAD DE LIBROS EN EXISTENCIA.............
		do{
			printf("Introduzca la cantidad de libros en existencia que se agregaran: ");
			fflush(stdin);
			gets(num);
			booleano = revisarInt(num);
			
			if(booleano ==0)
			{
				printf("\n\n La cantidad de libros que ingreso no es valida!\n");
				printf("Por favor introduzca un numero entero\n\n");
			}
			
		}while(booleano==0);
		libros[cunt].exi=atoi(num);
		
		//......................VALIDACION DE FECHA DE PUBLICACION.................
		do{
			do{
			
				printf("Introduzca el dia de publicacion (1 para saltar): ");
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);													//Validacion del dia de publicacion 
				
				if(booleano ==0)
				{
					printf("\n\nEl dia introducido no es valido!\n");
					printf("Por favor introduzca un numero entero\n\n");
				}
			
			}while(booleano==0);
			libros[cunt].dia=atoi(num);
			
			do{
			
				printf("Introduzca el mes de publicacion (1 para saltar): ");;
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);													//Validacion del mes de publicacion 
				
				if(booleano ==0)
				{
					printf("\n\n El mes ingresado no es valido!\n");
					printf("Por favor introduzca un numero entero\n\n");
				}
			
			}while(booleano==0);
			libros[cunt].mes=atoi(num);
			
			do{
			
				printf("Introduzca el a�o de publicacion: ");;
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);													//Validacion del a�o de publicacion 
				
				if(booleano ==0)
				{
					printf("\n\nEl a�o ingresado no es valido!\n");
					printf("Por favor introduzca un valor entero\n\n");
				}
			
			}while(booleano==0);
			libros[cunt].ano=atoi(num);
			
			booleano= valifecha(libros[cunt].dia,libros[cunt].mes,libros[cunt].ano);
			
			if(booleano==0)
			{
				printf("\n\n La fecha ingresada no es valida!\n");
				printf("Por favor ingrese una fecha de publicaci�n valida\n\n");
			}
		}while(booleano==0);
		
		libros[cunt].vecesprestado=0;
		
			do{
			
				printf("\n\n Son correctos los datos que ingreso? [1.-Si/2.-No]: ");;
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);													//Validacion del a�o de publicacion 
				
				if(booleano ==0)
				{
					printf("\n\n Opcion no valida!\n");
					printf("Por favor ingrese una opcion valida\n\n");
				}
				op=atoi(num);
				if(booleano!=0&&(op!=1 && op!=2))
				{
					printf("\n\n Opcion no valida!\n");
					printf("Por favor ingrese una opcion valida\n\n");
				}
			}while(booleano==0 || (op!=1 && op!=2));
			
	}while(op!=1);
	
	
	//Generacion de la clave unica del libro
	int n1,n2,n3;
	char c1,c2,c3;
	n1=(libros[cunt].cat/10)/10;
	n2=(libros[cunt].cat/10)%10;
	n3=libros[cunt].cat%10;
	c1=n1+'0';
	c2=n2+'0';
	c3=n3+'0';

	libros[cunt].clave[0]=c1;
	libros[cunt].clave[1]=c2;
	libros[cunt].clave[2]=c3;
	lenaut=strlen(libros[cunt].titulo);
	// Llena los campos correspondientes al libro
	for(j=0,c=0;j<lenaut;j++)
		if(isalpha(libros[cunt].titulo[j])!=0||isdigit(libros[cunt].titulo[j])!=0)
		{
			libros[cunt].clave[3+c]=toupper(libros[cunt].titulo[j]);
			printf("%c",libros[cunt].clave[3+c]);
			c++;
			if(c==3)
				break;
		}
	// Si quedaron campos vac�os se llenan con 0's
	if(j==lenaut)
		for(j=c;j<3;j++)
			libros[cunt].clave[3+c]='0';
	lenaut=strlen(libros[cunt].autor);
	// Campos correspondientes al autor
	c=0;
	if(isalpha(libros[cunt].autor[0])!=0)
	{
		libros[cunt].clave[6]=toupper(libros[cunt].autor[0]);
		c++;
	}
	for(j=0;j<lenaut;j++)
	{
		if(libros[cunt].autor[j]==' '||libros[cunt].autor[j]=='.')
			if(isalpha(libros[cunt].autor[j+1])!=0)
			{
				libros[cunt].clave[6+c]=toupper(libros[cunt].autor[j+1]);
				c++;
				if(c==2)
					break;
			}
	}
	// Si quedan espacios vacios se llenan con 0
	if(j==lenaut)
		for(j=c;j<lenaut;j++)
			libros[cunt].clave[6+c]='0';
	libros[cunt].clave[8]='1';
	libros[cunt].clave[9]='\0';
	//Fin de generacion de la clave
	
	for(j=1;j<libros[cunt].exi;j++)
	{
		strcpy(libros[cunt+j].titulo,libros[cunt].titulo);
		libros[cunt+j].ano=libros[cunt].ano;
		strcpy(libros[cunt+j].autor,libros[cunt].autor);
		libros[cunt+j].cat=libros[cunt].cat;
		libros[cunt+j].dia=libros[cunt].dia;
		libros[cunt+j].edi=libros[cunt].edi;
		strcpy(libros[cunt+j].editorial,libros[cunt].editorial);
		libros[cunt+j].exi=libros[cunt].exi;
		libros[cunt+j].mes=libros[cunt].mes;
		strcpy(libros[cunt+j].pais,libros[cunt].pais);
		libros[cunt+j].vecesprestado=0;
		strcpy(libros[cunt+j].clave,libros[cunt].clave);
		libros[cunt+j].clave[8]=j+'1';
	}

	printf("\n\n Libro agregado con exito! \n\n");
	printf("Claves:");
	for(j=0;j<libros[cunt].exi;j++)
		printf("\n %s",libros[cunt+j].clave);
	cunt+=j;
	printf("\n\nRegresando al menu principal...\n\n\n\n");
	system("pause");
	return cunt;
}
//--------------------------------------

//------------ELIMINAR LIBRO-------------
void rip(struct biblio libros[100],int cunt){	//funcion que elimina el libro deseado
	int i,l,v=0,op,booleano;
	char num[' '],cla[' '];
	struct biblio aux[' '];
	do{
		system("cls");
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
			
				tabla(libros,l,i);
				l++;		
		}
		
		printf("\n\n\n\n\n\n");
	
		do{
			printf("Introduzca la clave del libro que desea eliminiar: ");
			fflush(stdin);
			gets(cla);
			
				do{
			
				printf("\n\n Esta seguro que desea eliminar el libro con esta clave? [1.-Si/2.-No]: ");
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);													//Validacion del a�o de publicacion 
				
				if(booleano ==0)
				{
					printf("\n\n Opcion no valida!\n");
					printf("Por favor ingrese una opcion valida\n\n");
				}
				op=atoi(num);
			}while(booleano==0 || (op!=1 && op!=2));
			
		}while(op!=1);
		booleano=0;
		for(i=0;i<cunt;i++)
			if(strcmp(libros[i].clave,cla)==0){
				l=i;
				booleano=1;
				break;
			}
		
		if(booleano==0)
			printf("\n\nLo sentimos, no encontramos ningun libro con la clave que ingreso.\n\n");
		
		else{
				
			for(i=0;i<cunt;i++){
				if(i!=l){
					aux[v]=libros[i];
					v++;
				}
			}
			v=0;
			for(i=0;i<cunt-1;i++){
				libros[i]=aux[v];
				v++;
			}
		}
		
		
	}while(booleano==0);
	
	printf("Libro eliminado con exito\n\n");	
	system("pause");
	return;	
}
//--------------------------------------

//------------BUSCAR LIBRO-------------
void search(struct biblio libros[100],int cunt){
	int booleano,op; //Varaible que actua como bool que nos auxilia para las validaciones // Variable de control de opciones
	char num[' '];//Variable auxiliar para las validaciones
	
	do{
		
		//Formato de men� de busquedas
		system("cls");
		gotoxy(20,2);
		printf("BUSQUEDA DE LIBROS\n\n\n\n\n");
		printf("\t\tIngrese el tipo de busqueda que desea realizar\n\n");
		printf("\t\t1.- Busqueda de libros por autor\n\n");
		printf("\t\t2.- Busqueda de libros por categoria\n\n");
		printf("\t\t3.- Busqueda de libros por identificador\n\n");
		printf("\t\t4.- Busqueda de libros por nombre\n\n");
		printf("\t\t5.- Regresar al men� de libros\n\n");
		do{
		
			do{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);							//Validacion de la opcion a elegir 
					
				if(booleano ==0)
				{
					printf("\n\n El numero ingresado no es valido!\n");
					printf("Por favor ingrese un numero valido\n\n");
				}
					
			}while(booleano==0);
			op=atoi(num);
			
			
			if(op!=1 && op!=2 && op!=3 && op!=4 && op!=5)
			{
				printf("\n\n La opcion ingresada no es valida!\n");
				printf("Por favor ingrese una opcion valida\n\n");
				system("pause");
			}
			
		}while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5);
		
		switch (op){
			case 1: asearch(libros,cunt);
					break;
			case 2: csearch(libros,cunt);
					break;
			case 3: isearch(libros,cunt);
					break;
			case 4: nsearch(libros,cunt);
					break;		
			case 5:	system("cls");
					gotoxy(20,10);
					printf("Regresando al menu libros...\n\n\n");					
					break;
		}
	}while(op!=5);
}

void asearch(struct biblio libros[100],int cunt){ 
	int i,l,cant,op,booleano;
	char nom[' '],num[' '];		
	cant=0;
	/*
	i->	Variable de control de ciclo
	l->	Variable de control de posicion
	cant-> Cantidad de lbros encontrados
	op-> Variable de control de opciones
	booleano->	Varaible que actua como bool que nos auxilia para las validaciones
	nom[' ']->	Variable auxiliar para las validaciones
	num[' ']->	Variable auxiliar para las validaciones
	*/
	
	do{
		
		system("cls");
		gotoxy(20,2);
	
		printf("BUSQUEDA DE LIBROS POR AUTOR\n\n");
		printf("Introduzca el nombre del autor que desea buscar:  ");
		fflush(stdin);
		gets(nom);
		for(i=0;nom[i]!='\0';i++){
			nom[i]= toupper(nom[i]);
		}
		system("cls");
		encabezado();
		
		l=8;
		for(i=0;i<cunt;i++)
		{
			if(strstr(libros[i].autor,nom)!=NULL){
				
					tabla(libros,l,i);
					cant++;
					l++;
			}
		
		}
		
		if(cant==0)
		printf("\n\nLo sentimos, no pudimos encontrar algun libro relacionado con el autor mencionado\n\n");
		
		printf("\n\n Desea seguir buscando libros por sus autores? [1.-Si |||| 2.-No]\n\n");
		do{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);							//Validacion de la opcion a elegir 
					
				if(booleano ==0)
				{
					printf("\n\n El numero ingresado no es valido!\n");
					printf("Por favor ingrese un numero valido\n\n");
				}
				
				op=atoi(num);
					
		}while(booleano==0 || (op!=1 && op!=2));
			
	}while(op!=2);
}

void csearch(struct biblio libros[100],int cunt){ //Busqueda de libro por la categoria a la que pertenece
	int i,l,cant,op,booleano;
	char nom[' '];
	cant=0;
	char num[' '];
	/*
	num[' ']->	Variable auxiliar para las validaciones
	i->	Variable de control de ciclo
	l->	Variable de control de posicion
	cant-> Cantidad de lbros encontrados
	op-> Variable de control de opciones
	booleano->	Varaible que actua como bool que nos auxilia para las validaciones
	nom[' ']->	Variable auxiliar para las validaciones
	*/
	
	do{
		
		system("cls");
		gotoxy(20,2);
	
		printf("BUSQUEDA DE LIBROS POR CATEGORIA\n\n");
		printf("Ingrese la categoria del libro a buscar\n\n 000 --- Inform�tica, informaci�n y obras generales\n\n ");
		printf("100 --- Filosof�a y psicolog�a\n\n");
		printf("200 --- Religi�n\n\n");
		printf("300 --- Ciencias sociales\n\n");
		printf("400 --- Lengua\n\n");
		printf("500 --- Ciencia\n\n");
		printf("600 --- Tecnologia y ciencia aplicada\n\n");
		printf("700 --- Arte y recreaci�n\n\n");
		printf("800 --- Literatura\n\n");
		printf("900 --- Historia y geografia\n\n");
		do{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);							//Validacion de la opcion a elegir 
					
				if(booleano ==0)
				{
					printf("\n\n El numero ingresado no es valido!\n");
					printf("Por favor ingrese un numero valido\n\n");
				}
				
				op=atoi(num);
					
		}while(booleano==0);
		
		system("cls");
		encabezado();
		l=8;
		for(i=0;i<cunt;i++)
		{
			if(libros[i].cat==op){
				
					tabla(libros,l,i);
					l++;
					cant++;
					
			}
		
		}
		
		if(cant==0)
			printf("\n\nLo sentimos, no pudimos encontrar algun libro relacionado con la categoria mencionada\n\n");
		
		printf("\n\n Desea seguir buscando libros por el tipo de categoria? [1.-Si |||| 2.-No]\n\n");
		do{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);							//Validacion de la opcion a elegir 
					
				if(booleano ==0)
				{
					printf("\n\n�El numero ingresado no es valido!\n");
					printf("Por favor ingrese un numero valido\n\n");
				}
				
				op=atoi(num);
					
		}while(booleano==0 || (op!=1 && op!=2));
			
	}while(op!=2);
}

void nsearch(struct biblio libros[100],int cunt){ //Busqueda de libro por el nombre del libro 
	int i,l,cant,op,booleano;
	char nom[' '];
	cant=0;
	char num[' '];
	/*
	num[' ']->	Variable auxiliar para las validaciones
	i->	Variable de control de ciclo
	l->	Variable de control de posicion
	cant-> Cantidad de lbros encontrados
	op-> Variable de control de opciones
	booleano->	Varaible que actua como bool que nos auxilia para las validaciones
	nom[' ']->	Variable auxiliar para las validaciones
	*/
	
	do{
		
	system("cls");
	gotoxy(20,2);
	
		printf("BUSQUEDA DE LIBROS POR TITULO\n\n");
		printf("Introduzca el titulo del libro que desea buscar:  ");
		fflush(stdin);
		gets(nom);
		for(i=0;nom[i]!='\0';i++){
			nom[i]= toupper(nom[i]);
		}
		
		system("cls");
		encabezado();		
		l=8;
		for(i=0;i<cunt;i++)
		{
			if(strstr(libros[i].titulo,nom)!=NULL){
				
					tabla(libros,l,i);
					l++;
					cant++;
					
			}
		
		}
		
		if(cant==0)
			printf("\n\n Lo sentimos, no pudimos encontrar algun libro con el titulo mencionado\n\n");
		
		printf("\n\n Desea seguir buscando libros por su titulo? [1.-Si |||| 2.-No]\n\n");
		do{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);							//Validacion de la opcion a elegir 
					
				if(booleano ==0)
				{
					printf("\n\n�El numero ingresado no es valido!\n");
					printf("Por favor ingrese un numero valido\n\n");
				}
				
				op=atoi(num);
					
		}while(booleano==0 || (op!=1 && op!=2));
			
	}while(op!=2);

}

void isearch(struct biblio libros[100],int cunt){ //Busqueda de libro por el su identificador
	int i,l,cant,op,booleano,cl;
	char nom[' '];
	cant=0;
	char num[' '];
	/*
	num[' ']->	Variable auxiliar para las validaciones
	i->	Variable de control de ciclo
	l->	Variable de control de posicion
	cant-> Cantidad de lbros encontrados
	op-> Variable de control de opciones
	booleano->	Varaible que actua como bool que nos auxilia para las validaciones
	nom[' ']->	Variable auxiliar para las validaciones
	*/
	do
	{
	system("cls");
	gotoxy(20,2);
	
		printf("BUSQUEDA DE LIBROS POR IDENTIFICADOR\n\n");
		printf("Introduzca la clave del libro que desea buscar:  ");
		fflush(stdin);
		gets(nom);	
		for(i=0;nom[i]!='\0';i++)
			nom[i]= toupper(nom[i]);
		
		system("cls");
		encabezado();
		l=8;
		for(i=0;i<cunt;i++)
		{
			if(strcmp(libros[i].clave,nom)==0){
				
					tabla(libros,l,i);
					l++;
					
					cant++;
					break;
			}
		
		}
		
		if(cant==0)
			printf("\n\nLo sentimos, no pudimos encontrar algun libro con el identificador mencionado\n\n");
		
		printf("\n\n Desea seguir buscando libros por su identificador? [1.-Si |||| 2.-No]\n\n");
		do{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);							//Validacion de la opcion a elegir 
					
				if(booleano ==0)
				{
					printf("\n\n El numero ingresado no es valido!\n");
					printf("Por favor ingrese un numero valido\n\n");
				}
				
				op=atoi(num);
					
		}while(booleano==0 || (op!=1 && op!=2));
			
	}while(op!=2);
	
}

//----------FIN DE BUSQUEDAS---------

//------------REPORTES DE LIBROS--------
void reportes(struct biblio libros[100],int cunt){
	int booleano,op;
	char num[' '];
	/*
	op-> Variable de control de opciones
	booleano->	Varaible que actua como bool que nos auxilia para las validaciones
	num[' ']->	Variable auxiliar para las validaciones
	*/
	do{
	
		//Formato de men� de reportes de libros
		system("cls");
		gotoxy(20,2);
		printf("REPORTES DE LIBROS %d\n\n\n\n\n",cunt);
		printf("\t\tIngrese el tipo de reporte que desea ver\n\n");
		printf("\t\t1.- Reporte de libros por titulo\n\n");
		printf("\t\t2.- Reporte de libros por autor\n\n");
		printf("\t\t3.- Reporte de libros por a�o de publicacion\n\n");
		printf("\t\t4.- Reporte de libros por pa�s\n\n");
		printf("\t\t5.- Reporte de libros por editorial\n\n");
		printf("\t\t6.- Reporte de libros por cantidad de veces prestado\n\n");
		printf("\t\t7.- Reporte de libros por clave	\n\n");
		printf("\t\t8.- Reporte de libros por estado \n\n");
		printf("\t\t9.- Regresar al menu principal de libros \n\n");
		do{
		
			do{
				fflush(stdin);
				gets(num);
				booleano = revisarInt(num);							//Validacion de la opcion a elegir 
					
				if(booleano ==0)
				{
					printf("\n\n El numero ingresado no es valido!\n");
					printf("Por favor ingrese un numero valido\n\n");
				}
					
			}while(booleano==0);
			op=atoi(num);
			
			
			if(op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=7 && op!=8 && op!=9)
			{
				printf("\n\n La opcion ingresada no es valida!\n");
				printf("Por favor ingrese una opcion valida\n\n");
				system("pause");
			}
			
		}while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=7 && op!=8 && op!=9);
		
		switch (op){
			case 1: rtitulo(libros,cunt);
					break;
			case 2: rautor(libros,cunt);
					break;
			case 3: rano(libros,cunt);
					break;
			case 4: rpais(libros,cunt);
					break;		
			case 5: reditorial(libros,cunt);
					break;	
			case 6: rcant(libros,cunt);
					break;	
			case 7: rclave(libros,cunt);
					break;
			case 8: redo(libros,cunt);
					break;										
			case 9:	system("cls");
					gotoxy(20,10);
					printf("Regresando al menu libros...\n\n\n");					
					break;
		}
	}while(op!=9);
	return;
}

void encabezado(){					//Formato de tabla 
	
		gotoxy(5,8);
		printf("Clave");
		gotoxy(20,8);
		printf("Autor");
		gotoxy(45,8);
		printf("Titulo");
		gotoxy(70,8);
		printf("Categoria");
		gotoxy(85,8);
		printf("Pais");
		gotoxy(100,8);
		printf("Editorial");
		gotoxy(115,8);
		printf("N_Edicion");
		gotoxy(125,8);
		printf("Existencia");
		gotoxy(135,8);
		printf("Dia");
		gotoxy(145,8);
		printf("Mes");
		gotoxy(155,8);
		printf("A�o");
		gotoxy(165,8);
		printf("Veces prestado");
	
}

void tabla(struct biblio libros[100],int l,int i){		//Impresion de los datos de la tabla	

			
			gotoxy(5,l+3);
			printf("%s",libros[i].clave);
			gotoxy(20,l+3);
			printf("%s",libros[i].autor);
			gotoxy(45,l+3);
			printf("%s",libros[i].titulo);
			gotoxy(70,l+3);
			printf("%d",libros[i].cat);
			gotoxy(85,l+3);
			printf("%s",libros[i].pais);
			gotoxy(100,l+3);
			printf("%s",libros[i].editorial);
			gotoxy(115,l+3);
			printf("%d",libros[i].edi);
			gotoxy(125,l+3);
			printf("%d",libros[i].exi);
			gotoxy(135,l+3);
			printf("%d",libros[i].dia);
			gotoxy(145,l+3);
			printf("%d",libros[i].mes);
			gotoxy(155,l+3);
			printf("%d",libros[i].ano);	
			gotoxy(165,l+3);
			printf("%d",libros[i].vecesprestado);
}

void rtitulo(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por el titulo del libro
		
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *reptit;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*reptit-> Apuntador al archivo de reporte
		*/

		reptit=fopen("rep_lib_tit.txt","w");
		
		if(reptit == NULL)
		{
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tError! Fallo en el sistema.\n\n\n\n\n");   
			exit(1);             
		}
		
		system("cls");
		
		gotoxy(50,2);
		
		printf("REPORTE DE LIBROS POR TITULO\n\n\n\n\n");
		fprintf(reptit,"REPORTES DE LIBROS POR TITULO\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		
		//Ordenamiento por titulo
		
			for(i=0;i<cunt;i++){
			
		      for(j=i+1;j<cunt;j++){
		      	
		         if(strcmp(libros[i].titulo,libros[j].titulo)>0)
				 {
		            aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;

		         }
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------
		
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(reptit,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_tit.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			
		printf("\n\n\n\n\t\t");
		fclose(reptit);
		system("pause");
		
		
}


void rautor(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por el nombre del autor del libro
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *repau;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*repau-> Apuntador al archivo de reporte
		*/
		
	
		repau=fopen("rep_lib_aut.txt","w");
		
		system("cls");
		
		gotoxy(50,2);
		printf("REPORTES DE LIBROS POR AUTOR\n\n\n\n\n");
		fprintf(repau,"REPORTES DE LIBROS POR AUTOR\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		
		//Ordenamiento por autor
		
			for(i=0;i<cunt;i++){
			
		      for(j=i+1;j<cunt;j++){
		      		
		         if(strcmp(libros[i].autor,libros[j].autor)>0)
				 {
		            aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;
		            
		         }
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------
		
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(repau,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		
		fclose(repau);
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_aut.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			
		printf("\n\n\n");
		system("pause");
		
		
}

void rpais(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por el pa�s de origen del libro
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *repai;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*repai-> Apuntador al archivo de reporte
		*/	
		repai=fopen("rep_lib_pai.txt","w");
		
		
		system("cls");
		
		gotoxy(20,2);
		printf("REPORTES DE LIBROS POR PAIS\n\n\n\n\n");
		fprintf(repai,"REPORTES DE LIBROS POR PAIS\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		
		//Ordenamiento por autor
		
			for(i=0;i<cunt;i++){
			
		      for(j=i+1;j<cunt;j++){
		      	
		         if(strcmp(libros[i].pais,libros[j].pais)>0)
				 {
		            aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;
		            
		         }
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------	
		
		//Formato de tabla 
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(repai,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_pai.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			

		printf("\n\n\n\n\n\n");
		fclose(repai);
		system("pause");
		
		
}

void reditorial(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por el nombre de la editorial del libro
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *repedi;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*repedi-> Apuntador al archivo de reporte
		*/	
		repedi=fopen("rep_lib_edi.txt","w");
		system("cls");
		
		gotoxy(20,2);
		printf("REPORTES DE LIBROS POR EDITORIAL\n\n\n\n\n");
		fprintf(repedi,"REPORTES DE LIBROS POR EDITORIAL\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		
		//Ordenamiento por autor
		
			for(i=0;i<cunt;i++){
			
		      for(j=i+1;j<cunt;j++){
		      	
		         if(strcmp(libros[i].editorial,libros[j].editorial)>0)
				 {
		            aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;
		            
		         }
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------
		
		//Formato de tabla 
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(repedi,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_edi.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			
		printf("\n\n\n\n\n\n");
		fclose(repedi);
		system("pause");
		
		
}

void rclave(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por la clave del libro
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *repcla;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*repcla-> Apuntador al archivo de reporte
		*/	
		repcla=fopen("rep_lib_cla.txt","w");
		system("cls");
		
		gotoxy(20,2);
		printf("REPORTES DE LIBROS POR CLAVE\n\n\n\n\n");
		fprintf(repcla,"REPORTES DE LIBROS POR CLAVE\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		
			//Ordenamiento por autor
		
			for(i=0;i<cunt;i++){
			
		      for(j=i+1;j<cunt-1;j++){
		      	
		         if(libros[i].clave>libros[j].clave){
		            aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;
		            
		         }
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------	
		
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(repcla,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_cla.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			
		printf("\n\n\n\n\n\n");
		fclose(repcla);
		system("pause");
		
		
}

void rcant(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por la cantidad de veces que ha sido prestado
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *repcan;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*repcan-> Apuntador al archivo de reporte
		*/	
		repcan=fopen("rep_lib_can.txt","w");
		system("cls");
		
		gotoxy(20,2);
		printf("REPORTES DE LIBROS POR CANTIDAD DE VECES PRESTADO\n\n\n\n\n");
		fprintf(repcan,"REPORTES DE LIBROS POR CANTIDAD DE VECES PRESTADO\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		//Ordenamiento por autor
		
			for(i=0;i<cunt;i++){
			
		      for(j=i+1;j<cunt;j++){
		      	
		         if(libros[i].vecesprestado<libros[j].vecesprestado){
		           aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;
		         }
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------	
		
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(repcan,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_can.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			
		printf("\n\n\n\n\n\n");
		fclose(repcan);
		system("pause");
		
		
}

void rano(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por el a�o de publicacion
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *repano;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*repcan-> Apuntador al archivo de reporte
		*/	
		repano=fopen("rep_lib_ano.txt","w");
		system("cls");
		
		gotoxy(20,2);
		printf("REPORTES DE LIBROS POR A�O\n\n\n\n\n");
		fprintf(repano,"REPORTES DE LIBROS POR A�O\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		//Ordenamiento por autor
		
			for(i=0;i<cunt;i++){
			
		      for(j=i+1;j<cunt;j++){ //Ordenamiento por a�o, mes, dia
		      	
		         if((libros[i].ano>libros[j].ano) ){
		            aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;
		        }
		        else
		        	if(libros[i].ano==libros[j].ano)
		        		if(libros[i].mes>libros[j].mes)
		        		{
		        			aux=libros[i];
				            libros[i]=libros[j];
				            libros[j]=aux;
						}
						else
							if(libros[i].dia>libros[j].dia)
							{
								aux=libros[i];
					            libros[i]=libros[j];
					            libros[j]=aux;
							}
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------
		
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(repano,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_ano.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			
		printf("\n\n\n\n\n\n");
		fclose(repano);
		system("pause");
		
		
}

void redo(struct biblio libros[100],int cunt){ 		//Reporte de libros ordenados por el estado del libro
		char temp[' '];
		int ban,l;
		struct biblio aux;
		FILE *repedo;
		int i,j;
		/*
		i-> Variable de control de ciclo
		j-> Variable de control de ciclo
		ban-> Variable auxiliar para el acomodo de variables
		l->	Variable de control de posicion
		aux-> Estructura auxiliar que nos sirve para el ordenamiento de los campos
		temp[' ']->	Variable auxiliar para el ordenamiento de valores
		*repcan-> Apuntador al archivo de reporte
		*/	
		repedo=fopen("rep_lib_edo.txt","w");
		system("cls");
		
		gotoxy(20,2);
		printf("REPORTES DE LIBROS POR ESTADO\n\n\n\n\n");
		fprintf(repedo,"REPORTES DE LIBROS POR ESTADO\nCLAVE\tAUTOR\tTITULO\tCATEGORIA\tPAIS\tEDITORIAL\tN_EDICION\tEXISTENCIA\tDIA\tMES\tA�O");
		//Ordenamiento por autor
		
			for(i=0;i<cunt;i++){
			
		      for(j=0;j<cunt-1;j++){
		      	
		         if(libros[i].edi==0){
		            aux=libros[i];
		            libros[i]=libros[j];
		            libros[j]=aux;
		            
		         }
		         
		      }
			}
		//-------------Fin del ordenamiento---------------------	
		
		//-------------Fin del ordenamiento---------------------
		
		encabezado();
		l=8;
		
		//-------------Escritura de la tabla--------------------
		for(i=0;i<cunt;i++)
		{
				fprintf(repedo,"\n%s\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t",libros[i].clave,libros[i].autor,libros[i].titulo,libros[i].cat,libros[i].pais,libros[i].editorial,libros[i].edi,libros[i].exi,libros[i].dia,libros[i].mes,libros[i].ano);
				tabla(libros,l,i);
				l++;		
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\t\t LISTO, PARA ABRIR EL ARCHIVO EN EXCEL, UBIQUE EL ARCHIVO 'rep_lib_edo.txt' Y SIGA LAS INSTRUCCIONES EN EL MANUAL DE USUARIO.");			
		printf("\n\n\n\n\n\n");
		fclose(repedo);
		system("pause");
		
		
}
//-------------FIN DE REPORTES DE LIBROS----------------------


//-------CONTEO DE LA CANTIDAD DE LIBROS EN EL ARCHIVO--------
int contarlibros(struct biblio libros[100]) // esta funcion leera todos los libros del archivo y los pasara al struct libros, aparte de regresar la cantidad de libros.
{
	int cantlib=0; //Cantidad de libros encontrados en el archivo 
	FILE *librosfile; //Apuntador al archivo

	librosfile = fopen("libros1.txt","r"); 
	if(librosfile == NULL)
	{
		librosfile = fopen("libros1.txt","w+"); 
		if(librosfile==NULL)
		{
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tError! Fallo en el sistema.\n\n\n\n\n");   
			system("pause");
			exit(1); 
		}    
	}
	fscanf(librosfile,"%s\n",&libros[cantlib].clave);
	while(feof(librosfile)==0){
		
		fgets(libros[cantlib].autor,1000,librosfile);
		libros[cantlib].autor[strlen(libros[cantlib].autor)-1]=' ';
		fgets(libros[cantlib].titulo,1000,librosfile);	
		libros[cantlib].titulo[strlen(libros[cantlib].titulo)-1]=' ';
		fgets(libros[cantlib].pais,1000,librosfile);
		libros[cantlib].pais[strlen(libros[cantlib].pais)-1]=' ';
		fgets(libros[cantlib].editorial,1000,librosfile);
		libros[cantlib].editorial[strlen(libros[cantlib].editorial)-1]=' ';
		fscanf(librosfile,"%d",&libros[cantlib].cat);
		fscanf(librosfile,"%d",&libros[cantlib].edi);
		fscanf(librosfile,"%d",&libros[cantlib].exi);
		fscanf(librosfile,"%d",&libros[cantlib].dia);
		fscanf(librosfile,"%d",&libros[cantlib].mes);
		fscanf(librosfile,"%d\n",&libros[cantlib].ano);
		cantlib++;
		fscanf(librosfile,"%s\n",&libros[cantlib].clave);
	}
	
	/*
	for(i=0;i<cantlib;i++)
	{
		printf("\n\n clave: %s",libros[i].clave);
		printf("\n\n autor: %s",libros[i].autor);
		printf("\n titulo: %s",libros[i].titulo);
		printf("\n pais: %s",libros[i].pais);
		printf("\n edit: %s",libros[i].editorial);
		printf("\n categoria: %d",libros[i].cat);
		printf("\n edicion: %d",libros[i].edi);
		printf("\n existencia: %d",libros[i].exi);
		printf("\n dia: %d",libros[i].dia);
		printf("\n mes: %d",libros[i].mes);
		printf("\n ano: %d",libros[i].ano);
		
	}
	
	
		system("pause");
	*/	
	fclose(librosfile);
	return cantlib;
	 // Regresamos la cantidad de libros leidos.
}

void impresionlibros(struct biblio libros[100],int cantlibros)
{
	/*
		SE GUARDAN TODOS LOS DATOS DEL STRUCT LIBROS EN EL ARCHIVO LIBROS
	*/
	FILE *ap;
	int i;
	ap=fopen("libros1.txt","w");
	if(ap==NULL)
	{
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tError! Fallo en el sistema.\n\n\n\n\n");  
		system("pause"); 
		exit(1); 
	}
	for(i=0;i<cantlibros;i++){
		fprintf(ap,"%s\n",libros[i].clave); 		//Clave del libro
		fprintf(ap,"%s\n",libros[i].autor); 		//Autor del libro
		fprintf(ap,"%s\n",libros[i].titulo); 		//Titulo del libro
		fprintf(ap,"%s\n",libros[i].pais); 		//Pa�s de origen del libro
		fprintf(ap,"%s\n",libros[i].editorial); 	//Editorial del libro
		fprintf(ap,"%d\n",libros[i].cat); 			//Categoria del libro
		fprintf(ap,"%d\n",libros[i].edi); 			//Numero de de edicion del libro
		fprintf(ap,"%d\n",libros[i].exi); 			//Cantidad de libros en existencia del libro
		fprintf(ap,"%d\n",libros[i].dia); 			//Dia de publicacion del libro
		fprintf(ap,"%d\n",libros[i].mes); 			//Mes de publicacion del libro
		fprintf(ap,"%d\n",libros[i].ano); 			//A�o de publicacion del libro
		
	}
	fclose(ap);
	return;
}