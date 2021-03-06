#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//prototipo de funciones
int** crearMatrix(int, int, int);
void printMatrix(int**, int, int);
void liberarMatriz(int**&, int);
void conway(int**, int, int, int, int);
int encontrarVecinos(int**, int, int, int, int);

int main(int argc, char** argv) {
    int op = 0;
    
    while(op!=3){
        cout << "DIOSITO" << endl;
        cout << "1. Jugar con un tablero aleatorio" << endl;
        cout << "2. Jugar con tablero predefinido" << endl;
        cout << "3. Salir" << endl;
        cout << "" << endl;
        cout << "Ingresa opción: ";
        cin  >> op;
        
        cout << "" << endl;
        switch(op){
            case 1: {
                int filas=0, columnas=0, celulas=0, turnos=0;
                cout << "Filas: ";
                cin >> filas;
                while(filas<=1){
                    cout << "Filas: ";
                    cin >> filas;
                }
                cout << "Columnas: ";
                cin >> columnas;
                while(columnas<=1){
                    cout << "Columnas: ";
                    cin >> columnas;
                }
                cout << "Células: ";
                cin >> celulas;
                while(celulas<=0 || celulas>columnas*filas){
                    cout << "Células: ";
                    cin >> celulas;
                }
                cout << "Turnos: ";
                cin >> turnos;
                while(turnos<=0){
                    cout << "Turnos: ";
                    cin >> turnos;
                }
                
                int** matrixTemp = crearMatrix(filas, columnas, celulas);        //inicializa la matriz en 0
                conway(matrixTemp, filas, columnas, turnos, 1);
                liberarMatriz(matrixTemp, filas);
                
            } break;
            case 2: {
                int x=6, y=7, turnos=8;
                /*int temp_mat [x][y] = {                                   //EJEMPLO DE LA PáGINA 2
                    {0,0,0,0,0,0,0},
                    {0,0,1,0,1,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,1,1,1,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0}
                  
                    
                 * 
                };*/
                
                cout << "Turnos: ";
                cin >> turnos;
                
                x = 20;
                y = 20;	

                int temp_mat [20][20] = {                                   //EJEMPLO DE LA PáGINA 3
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0},
                {0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},
                {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                };
                
                int** mat = new int*[x];
                for(int i = 0; i < x ; i++){
                    mat[i] = new int[y];
                    for(int j = 0; j < y ; j++){
                        mat[i][j] = temp_mat[i][j];
                    }
                }
                
                conway(mat, x, y, turnos, 1);
                liberarMatriz(mat, x);
                
            } break;
            case 3: {
                cout << "Nos vemos, creador" << endl;
            } break;
            default: cout << "Opción no válida" << endl;
        }
        cout << "" << endl;
        
    }
    return 0;
}

int** crearMatrix(int size, int size2, int celulas){
    int** matriz = NULL;
    if(size>1 && size2>1){                                                      //SAFE CODE
        matriz = new int*[size];                                    //filas

        for(int i=0; i < size; i++){
            matriz[i] = new int[size2];                             //columnas
        }
        int celulasCreadas=0;
        for(int i=0; i<size; i++){
            for(int j=0; j<size2; j++){
                if(celulasCreadas<celulas){
                    matriz[i][j] = (0) + rand()%((1+1) - (0));
                    if(matriz[i][j]==1){
                        celulasCreadas++;
                    }
                } else{
                    matriz[i][j] = 0;
                }
                
            }
        }
    } else
        cout << "La matriz será nula. Dimensiones no permitidas" << endl;
    return matriz;
}

void printMatrix(int** matrix, int filas, int columnas){
    if(matrix!=NULL && filas>1 && columnas>1){                                                 //SAFE CODE
        for(int i=0; i<filas; i++){
            for(int j=0; j<columnas; j++){
                if(matrix[i][j] == 0){                                          //0: célula sin vida
                    cout << ".\t";
                } else if(matrix[i][j] == 1){                                   //1: célula viva
                    cout << "@\t";
                } else if(matrix[i][j] == 2){                                   //2: célula muerta q puede revivir
                    cout << "~\t";
                }
                //cout << std::to_string(matrix[i][j]) +"\t";
            }
            cout << "" << endl;
        }
    } else {
        cout << "Nula, no se puede imprimir por su contenido o dimensión" << endl;
    }
}

void liberarMatriz(int**& matrix, int size){
    if(matrix != NULL){                                                             //SAFE CODE
        for(int i = 0; i < size; i++){
            if(matrix[i] != NULL){
                delete[] matrix[i];
            }
            matrix[i] = NULL;
        }
    }
    
    if(matrix != NULL){
        delete[] matrix;
        matrix = NULL;
    }
}

void conway(int** mat, int x, int y, int turnos, int turnoActual){
    if(mat!=NULL){
        cout << "Presiona Enter..." << endl;
        cin.ignore();
        if(turnos==0){
            cout << "GAME OVER" << endl;
        } else {
            cout << "GENERACIÓN " << std::to_string(turnoActual) << endl;
            printMatrix(mat, x, y);

            int** matAnterior = mat;

            int** nuevaMat = crearMatrix(x, y, 2);
            for(int m=0; m<x; m++){
                for(int n=0; n<y; n++){
                    nuevaMat[m][n] = encontrarVecinos(matAnterior, x, y, m, n);
                }
            }

            conway(nuevaMat, x, y, turnos-1, turnoActual+1);
        }
    }
    
}

int encontrarVecinos(int** mat, int x, int y, int i, int j){
    
    int vecinos=0;
    if((i-1>=0) && (j-1>=0) && mat[i-1][j-1]==1){                       //diagonal izq arriba
        vecinos++;
    }
    if((i-1>=0) && mat[i-1][j]==1){                                     //arriba
        vecinos++;
    }
    if((i-1>=0) && (j+1<y) && mat[i-1][j+1]==1){                        //diagonal der arriba
        vecinos++;
    }
    if((j+1<y) && mat[i][j+1]==1){                                      //derecha
        vecinos++;
    }
    if((i+1<x) && (j+1<y) && mat[i+1][j+1]==1){                         //diagonal der abajo
        vecinos++;
    }
    if((i+1<x) && mat[i+1][j]==1){                                      //abajo
        vecinos++;
    }
    if((i+1<x) && (j-1>=0) && mat[i+1][j-1]==1){                        //diagonal izq abajo
        vecinos++;
    }
    if((j-1>=0) && mat[i][j-1]==1){                                     //izquierda
        vecinos++;
    }
    
    
    
    //decisión a partir de su cantidad de vecinos
    if(mat[i][j]==1){                                                           //CéLULAS VIVAS
        if(vecinos<2){
            return 0;      //se muere
        }
        if(vecinos==2 || vecinos==3){
            return 1;      //no hay cambio, esta línea es innecesaria
        }
        if(vecinos>3){
            return 0;      //se muere
        }
    }
    if(mat[i][j]==0){                                                    //CéLULAS MUERTAS
        if(vecinos==3){
            return 1;       //agarra vida
        }
    } /*else
        return 0;*/
    
}
