const int SER = 2;
const int RCLK = 3;
const int SRCLK =4;
int cpatrones, tpatrones;
char opcion;

int **puntero_matriz, ***puntero_matriz3d;

 
void definematrizbidi(){
  puntero_matriz = new int*[8];
  for(int i=0; i<8; i++){
    puntero_matriz[i] = new int[8];
  }
  for(int j=0; j<8; j++){
    for(int k=0; k<8; k++){
      *(*(puntero_matriz+j)+k)=0;     
    }
  }
}

void definematriztridi(int cpatrones){
  puntero_matriz3d = new int**[cpatrones];
  for(int i=0; i<cpatrones; i++){
    puntero_matriz3d[i] = new int*[8];
  
  	for(int j=0; j<8; j++){
    puntero_matriz3d[i][j] = new int[8];
  }
  }
  for(int i=0; i<cpatrones; i++){
    for(int j=0; j<8; j++){
      for(int k=0; k<8; k++){
        *(*(*(puntero_matriz3d+i)+j)+k)=0;
      }
    }
  }
}
void RecibirMatrizbidi(){
  char num_vol = 49;
  String valor; 
  long int fila;
  Serial.println("Para ingresar su patron, debe tener en cuenta que:");
  Serial.println("- El numero 1 se reflejara como el led encendido ");
  Serial.println("- El numero 0 se reflejara como el led apagado ");
  Serial.println("- Debe ingresar fila por fila");
  for(int i=0; i<=7; i++){
     Serial.print("Ingrese la fila ");
     Serial.println(i+1);
     while (Serial.available()==0){}
     valor = Serial.readStringUntil('\n');
     valor = num_vol + valor;
     fila = valor.toInt();
     for (int j=7; j>=0; j--){      
         *(*(puntero_matriz+i)+j)=fila%10;          
         fila=fila/10;                            
      }
   }  
} 

void RecibirMatriztridi(int cpatrones){
  char num_vol = 49;
  String valor; 
  long int fila;
  Serial.println("Para ingresar su patron, debe tener en cuenta que:");
  Serial.println("- El numero 1 se reflejara como el led encendido ");
  Serial.println("- El numero 0 se reflejara como el led apagado ");
  Serial.println("- Debe ingresar fila por fila");
  
  for(int i=0; i<cpatrones; i++){
    Serial.print("Ingrese la cara ");
     Serial.println(i+1);
  for(int j=0; j<=7; j++){
     Serial.print("Ingrese la fila ");
     Serial.println(j+1);
     while (Serial.available()==0){}
     valor = Serial.readStringUntil('\n');
     valor = num_vol + valor;
     fila = valor.toInt();
     for (int k=7; k>=0; k--){      
         *(*(*(puntero_matriz3d+i)+j)+k)=fila%10;          
         fila=fila/10;                            
      }
   }
  }
} 

void relojregistro(int parametro){
  digitalWrite(parametro, 0);
  digitalWrite(parametro, 1);
  digitalWrite(parametro, 0);
}

void imagen(){
  int m;   
  for (int i=7; i>=0; i--){
    for (int j=7; j>=0; j--){
      m=*(*(puntero_matriz+i)+j);      
      digitalWrite(SER, m);
      relojregistro(SRCLK);
      relojregistro(RCLK);
    }
    Serial.println(' ');
  }
}

void publik(int tpatrones, int cpatrones){
  int m;   
  for (int i=0; i<cpatrones; i++){
    for (int j=7; j>=0; j--){
      for(int k=7; k>=0; k--){
      m=*(*(*(puntero_matriz3d+i)+j)+k);      
      digitalWrite(SER, m);
      relojregistro(SRCLK);
      relojregistro(RCLK); 
      }
    }
    Serial.println(' ');
    delay(tpatrones);
  }
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

void publik(){}

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
    definematrizbidi();
    RecibirMatrizbidi();
    imagen();
  }
  else if (opcion == 51){
   
    Serial.println("Ingrese la cantidad de patrones que desea: ");
    while(Serial.available()==0){}
    cpatrones = Serial.parseInt();
  		
    Serial.println("Ingrese el tiempo entre patrones en milisegundos: ");
    while(Serial.available()==0){}
    tpatrones = Serial.parseInt(); 
    
    definematriztridi(cpatrones);
    RecibirMatriztridi(cpatrones);
    publik(tpatrones, cpatrones);
  }
}