const int SER = 2;
const int RCLK = 3;
const int SRCLK =4;
int cpatrones, tpatrones;
char opcion;

//int **matrizLed, ***matriz3d;

 /* 
int definematriz(int matriz[][8]){
  matriz= new int *[8];
  for (int i=0; i<8; i++){
    matriz[i]= new int [8];
  }
}*/

int matrizLed [8][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};


void relojregistro(int parametro){
  digitalWrite(parametro, 0);
  digitalWrite(parametro, 1);
  digitalWrite(parametro, 0);
}


void verificacion(){
  for(int k=0; k<64; k++){
     digitalWrite(SER, 1);
     relojregistro(SRCLK);
     relojregistro(RCLK);
  }
  delay(5000);
    for(int k=0; k<64; k++){
     digitalWrite(SER, 0);
     relojregistro(SRCLK);
     relojregistro(RCLK);
  }
}  

void RecibirMatriz(int matriz[][8]){
  String valor; 
  long int fila;
  int b;
  Serial.println("Para ingresar su patron, debe tener en cuenta que:");
  Serial.println("- El numero 1 se reflejara como el led encendido ");
  Serial.println("- El numero 0 se reflejara como el led apagado ");
  Serial.println("- Debe ingresar fila por fila");
  
 
  for(int i=0; i<8; i++){
     Serial.print("Ingrese la fila ");
     Serial.println(i+1);
     while (Serial.available()==0){}
     valor = Serial.readStringUntil('\n'); 
     fila = valor.toInt();
     Serial.println(fila);
     for (int j=7; j>=0 ;j--){
         b=fila%10;
         //*(*(matriz+i)+j)=b;
         matriz[i][j]=b;
         fila=fila/10;  
       }
    }
} 



void imagen(int matriz[][8]){
  int m;
  
  for (int i=7; i>=0; i--){
    for (int j=7; j>=0; j--){
     //m= *(*(matriz+i)+j);
      m=matriz[i][j];
     Serial.println(m);
     digitalWrite(SER, m);
     relojregistro(SRCLK);
      relojregistro(RCLK);
    }
  }
}

void publik(){
}

void setup(){
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  
}

void loop(){
  Serial.println("Bienvenido al menu de inicio"); 
  Serial.println("Ingrese el numero de lo que desea realizar"); 
  Serial.println("1. Verificar el funcionamiento de los 64 LEDs"); 
  Serial.println("2. Mostrar un patron"); 
  Serial.println("3. Secuencia de patrones");
  
  while(Serial.available()==0){}
  	opcion = Serial.read();
  
  
  if (opcion==49){
    verificacion();
  }
  else if (opcion==50){

    RecibirMatriz(**matrizLed);
    imagen(**matrizLed);
  }
  else if (opcion == 51){
   
    Serial.println("Ingrese la cantidad de patrones que desea: ");
    while(Serial.available()==0){}
    cpatrones = Serial.parseInt();
  		
    Serial.println("Ingrese el tiempo entre patrones en segundos: ");
    while(Serial.available()==0){}
    tpatrones = Serial.parseInt();
    
    int pmatriz[cpatrones][8][8]={};
  		
    //RecibirMatriz();
  }
      
}