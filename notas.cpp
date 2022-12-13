#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "estudiantes.dat";

struct Estudiante{

	char nombre[50];
	char apellido[50];
	float prom;
};
 void ingresar_estudiante();
 void abrir_estudiante();
 void eliminar_estudiante();
 int main (){
	abrir_estudiante();
 ingresar_estudiante();
	return 0;	
}


void abrir_estudiante(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"| "<<"PROMEDIO"<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" | "<<estudiante.prom<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	
	
		Estudiante estudiante;
		 string nombre,apellido;
		 int nota1, nota2, nota3, nota4;
         int suma;
         float prom;
		do{
			fflush(stdin);
			        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str());
		cout<<"Ingrese la nota 1: ";
		cin>>nota1;
			cout<<"Ingrese la nota 2: ";
		cin>>nota2;
			cout<<"Ingrese la nota 3: ";
		cin>>nota3;
			cout<<"Ingrese la nota 4: ";
		cin>>nota4;
          suma=nota1+nota2+nota3+nota4;
          estudiante.prom=suma/4;
          cout<<"su promedio es: "<<prom<<endl;
          if(estudiante.prom<=60)
          {
          	cout<<"el estudiante perdio"<<endl;
		  }else{
		  	cout<<"el estudiante gano"<<endl;
		  }
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();
}

