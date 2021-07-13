#include "basicas.cpp"
void inicia(int *pA,int max);
void menu(int *pA,int &N);
void lectura(int *pA,int &N);
void mostrar(int *pA,int N);
void promedio(int *pA,int N);
void menor(int *pA,int N);
void mayor(int *pA,int N);
void ascendente(int *pA,int N);
void descendente(int *pA,int N);
void insertarpos(int *pA,int &N);
void eliminarpos(int *pA,int &N);
void liberar(int *pA);

main()
{
	int *pA=new int[MAX];
   int N=0;
   inicia(pA,MAX);
   menu(pA,N);

getch();
}
void inicia(int *pA,int max)
{
	iniciaVE(pA,max);
}
void menu(int *pA,int &N)
{
	int op;
   do
   {
   	//clrscr();
      printf("\n\n*** MENU ***");
      printf("\n1.Lectura");
      printf("\n2.Mostrar");
      printf("\n3.Promedio");
      printf("\n4.Mayor");
      printf("\n5.Menor");
      printf("\n6.Orden Ascendente");
      printf("\n7.Orden Descendente");
      printf("\n8.Insertar");
      printf("\n9.Eliminar");
		printf("\n10.Salir");
		op=leeEntero("\n\nIngrese opcion: ",1,10);

      switch(op)
      {
      	case 1 : lectura(pA,N);
         	break;
         case 2 : mostrar(pA,N);
         	break;
         case 3 :	promedio(pA,N);
         	break;
         case 4 :	mayor(pA,N);
         	break;
         case 5 :	menor(pA,N);
         	break;
         case 6 : ascendente(pA,N);
         	break;
      	case 7 : descendente(pA,N);
         	break;
         case 8 : insertarpos(pA,N);
         	break;
         case 9 : eliminarpos(pA,N);
         	break;
         case 10 : printf("\nGracias por utilizar mi programa");
                  liberar(pA);
      }
      getch();
   }while(op!=10);
}

void lectura(int *pA,int &N)
{
	N=leeEntero("\nIngrese el numero de elementos: ",1,MAX);
   printf("\n");
   for(int i=0;i<N;i++)
   {
   	do
      {
      	printf("Elemento[%d]:",i+1);
         scanf("%d",pA+i);
      }while(!(*pA+i>0));
   }
}

void mostrar(int *pA,int N)
{
   printf("\n Elementos:\n");
	for(int i=0;i<N;i++)
   {
   	printf("\n Elemento[%d]:%d",i+1,*(pA+i));
   }
}
void promedio(int *pA,int N)
{
	int sum=0;
   float prom;
   if(N>0)
   {
   	for(int i=0;i<N;i++)
   		sum+=*(pA+i);
   	prom=(float)sum/N;
      printf("\n");
   	printf("El promedio de los elementos es: %.2f",prom);
   }
   else
   	printf("\n No hay datos");
}
void mayor(int *pA,int N)
{
	int may=0;
   if(N>0){
   for(int i=0;i<N;i++)
   {
   	if(*(pA+i)> may)
      {
      	may=*(pA+i);
      }
   }
   printf("\nEl numero mayor es: %d",may);
   }
   else
   	printf("\n No hay datos");
}

void menor(int *pA,int N)
{
	int men=10000;
   if(N>0){
   for(int i=0;i<N;i++)
   {
   	if(*(pA+i)< men)
      {
      	men=*(pA+i);
      }
   }
   printf("\nEl numero menor es: %d",men);
   }
   else
   	printf("\n No hay datos");
}

void ascendente(int *pA,int N)
{
   int aux;
   printf("\nOrden Ascendentemente:\n");
   for(int i=0;i<N-1;i++)
        for(int j=i+1;j<N;j++)
				if(*(pA+i)>*(pA+j))
        		{
            	aux=*(pA+i);
            	*(pA+i)=*(pA+j);
            	*(pA+j)=aux;
        		}
   for(int i=0;i<N;i++)
   	printf("\n Elemento[%d]: %d",i+1,*(pA+i));
}
void descendente(int *pA,int N)
{
   int aux;
   printf("\nOrden Descendentemente:");
   printf("\n");
   for(int i=0;i<N-1;i++)
   {
        for(int j=i+1;j<N;j++)
        {
				if(*(pA+i)<*(pA+j))
        		{
            	aux=*(pA+i);
            	*(pA+i)=*(pA+j);
            	*(pA+j)=aux;
        		}
        }
   }
   for(int i=0;i<N;i++)
   	printf("\n Elemento[%d]: %d",i+1,*(pA+i));
}
void insertarpos(int *pA,int &N)
{
   int num,pos;
   printf("\nIngrese numero del elemento a insertar: ");
   scanf("%d",&num);
   printf("Ingrese la posicion en la que desee insertar:");
   scanf("%d",&pos);
   for(int i=N;i>=pos;i--)
   {
   	*(pA+i)=*(pA+i-1);
   }
   *(pA+pos-1)=num;
   N=N+1;
   for(int i=0;i<N;i++)
   	printf("\n Elemento[%d]: %d",i+1,*(pA+i));
}
void eliminarpos(int *pA,int &N)
{
   int num,pos;
   printf("\nIngrese la posicion que desea eliminar:");
   scanf("%d",&pos);
   for(int i=pos;i<=N;i++)
   {
   	*(pA+i)=*(pA+i+1);
   }
   N=N-1;
   for(int i=0;i<N;i++)
   	printf("\n Elemento[%d]: %d",i+1,*(pA+i));
}
void liberar(int *pA)
{
	delete[]pA;
}
