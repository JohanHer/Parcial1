const int SER = 2;
const int RCLK = 3;
const int SRCLK =4;
int cpatrones, tpatrones;
char opcion;

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

void RecibirMatriz(){
  char valor;
  int i=0, j=0;
  Serial.println("Para ingresar su patron, debe tener en cuenta que:");
  Serial.println("- El numero 1 se reflejara como el led encendido ");
  Serial.println("- El numero 0 se reflejara como el led apagado ");
  Serial.println("- Debe ingresar fila por fila ");
  
 
    for(int i=0; i<8; i++){
      Serial.print("Ingrese la columna");
      Serial.println(i+1);
       for(int j=0; j<8; j++){  
         Serial.print("Ingrese la fila ");
  	  Serial.print(j+1);
      Serial.println(":");
          while (Serial.available()==0){}
          
          valor = Serial.parseInt();
       	  matrizLed[i][j]= valor;
       }
     
    }
 
} 



void imagen(){
  int m;
  
  for (int i=7; i>=0; i--){
    for (int j=7; j>=0; j--){
     m= matrizLed[i][j];
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
  imagen();
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
    delay(3000);
  }
  else if (opcion==50){

    RecibirMatriz();
    
  }
  else if (opcion == 51){
   
    Serial.println("Ingrese la cantidad de patrones que desea: ");
    cpatrones = Serial.read();
  		
    Serial.println("Ingrese el tiempo entre patrones en segundos: ");
    tpatrones = Serial.read();
  		
    RecibirMatriz();
  }
      
}