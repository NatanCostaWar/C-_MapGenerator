#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
int main(){
	srand(time(NULL));
	
	
	
	//Creating Map File
	std::fstream map;
	map.open ("map.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	
	//Creating the Map
	int LARGURA= 100;
	int ALTURA = 60;
	
	char AGUA  = '.';
	char TERRA = 'i';
	char AREIA = 'T';
	char MONTE = 'M';
	char NEVE  = 'N';
	char RAZO  = 'R';
	
	
	
	cout<<"LARGURA DO MAPA (PADRAO 100) (VALOR MAX 1000):";
	cin>>LARGURA;
	cout<<"ALTURA  DO MAPA (PADRAO 60)  (VALOR MAX 1000):";
	cin>>ALTURA;
	char mapa [LARGURA][ALTURA];
	
	//Filling the map with water
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			mapa[i][j] = AGUA;
		}
	}
	
	
	//Generating Initial Land Points
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			int x = rand() % 300;
			if(x < 4 && i>5 && i<LARGURA-5 && j>5 && j<ALTURA-5){
				mapa[i][j] = '1';
			}
		}
	}
		
	
	//Generating Lands From Initial Points
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j] == '1'){
				for(int a=i-5;a<=i+5;a++){
					for(int b=j-5;b<=j+5;b++){
						if(a == i && b == j){
						}else{
							int x = rand() % 100;
							if(x > 50){
								mapa[a][b]= TERRA;
							}	
						}	
					}
				}
			}
		}
	}
	
	//Removing Initial Land Points
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j] == '1'){
				mapa[i][j]=TERRA;
			}		
		}
	}
	
	
	//Filling Map Edges With Water
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(i < 3 or i>LARGURA-3 or j<3 or j>ALTURA-3){
				mapa[i][j]=AGUA;
			}		
		}
	}
	
	//Filling with Land Water points Btween Land Points
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			//AGUA ENTRE DUAS TERRAS
			if(mapa[i][j] == TERRA && mapa[i+1][j] == AGUA && mapa[i+2][j] == TERRA){
				mapa[i+1][j] = TERRA;
			}
			if(mapa[i][j] == TERRA && mapa[i-1][j] == AGUA && mapa[i-2][j] == TERRA){
				mapa[i-1][j] = TERRA;
			}
			if(mapa[i][j] == TERRA && mapa[i][j+1] == AGUA && mapa[i][j+2] == TERRA){
				mapa[i][j+1] = TERRA;
			}
			if(mapa[i][j] == TERRA && mapa[i][j-1] == AGUA && mapa[i][j-2] == TERRA){
				mapa[i][j-1] = TERRA;
			}
			//DUAS AGUAS ENTRE DUAS TERRAS
			if(mapa[i][j] == TERRA && mapa[i+1][j] == AGUA && mapa[i+2][j] == AGUA && mapa[i+3][j] == TERRA){
				mapa[i+1][j] = TERRA;
				mapa[i+2][j] = TERRA;
			}if(mapa[i][j] == TERRA && mapa[i-1][j] == AGUA && mapa[i-2][j] == AGUA && mapa[i-3][j] == TERRA){
				mapa[i-1][j] = TERRA;
				mapa[i-2][j] = TERRA;
			}if(mapa[i][j] == TERRA && mapa[i][j+1] == AGUA && mapa[i][j+2] == AGUA && mapa[i][j+3] == TERRA){
				mapa[i][j+1] = TERRA;
				mapa[i][j+2] = TERRA;
			}if(mapa[i][j] == TERRA && mapa[i][j-1] == AGUA && mapa[i][j-2] == AGUA && mapa[i][j-3] == TERRA){
				mapa[i][j+1] = TERRA;
				mapa[i][j+2] = TERRA;
			}
			
			
		}
	}
	
	//Generating beaches
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j] == AGUA && mapa[i+1][j] == TERRA && mapa[i+2][j] == TERRA && mapa[i+3][j]==TERRA){
				mapa[i+1][j] = AREIA;
				
			}if(mapa[i][j] == AGUA && mapa[i-1][j] == TERRA && mapa[i-2][j] == TERRA && mapa[i-3][j]==TERRA){
				mapa[i-1][j] = AREIA;
				
			}if(mapa[i][j] == AGUA && mapa[i][j+1] == TERRA && mapa[i][j+2] == TERRA && mapa[i][j+3]==TERRA){
				mapa[i][j+1] = AREIA;
				
			}if(mapa[i][j] == AGUA && mapa[i][j-1] == TERRA && mapa[i][j-2] == TERRA && mapa[i][j-3]==TERRA){
				mapa[i][j-1] = AREIA;
				
			}
				
		}
	}
	
	
	
	//Generating shallow
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j] == AREIA && mapa[i+1][j] == AGUA && mapa[i+2][j] == AGUA){
				mapa[i+1][j] = RAZO;
				mapa[i+2][j] = RAZO;
			}
			if(mapa[i][j] == AREIA && mapa[i-1][j] == AGUA && mapa[i-2][j] == AGUA){
				mapa[i-1][j] = RAZO;
				mapa[i-2][j] = RAZO;
			}
			if(mapa[i][j] == AREIA && mapa[i][j+1] == AGUA && mapa[i][j+2] == AGUA){
				mapa[i][j+1] = RAZO;
				mapa[i][j+2] = RAZO;
			}
			if(mapa[i][j] == AREIA && mapa[i][j-1] == AGUA && mapa[i][j-2] == AGUA){
				mapa[i][j-1] = RAZO;
				mapa[i][j-2] = RAZO;
			}
			
		}
	}
	
	
	
	//Generating Mountains
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j] == TERRA){
				int quant=0;
				int inicio=0;
				for(int y=i;y<LARGURA;y++){
					if(mapa[y][j]==TERRA){
						quant++;
						if(mapa[y-1][j]!=TERRA){
							inicio=y;
						}
					}else{
						if(quant>8){
							for(int u =4;u<quant-4;u++){
								mapa[inicio+u][j] = MONTE;
							}
						}
						quant=0;
					}
				}	
			}
				
		}
	}
	
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j]==AREIA && mapa[i][j+1]==MONTE or mapa[i][j]==AREIA && mapa[i][j+2]==MONTE or mapa[i][j]==AREIA && mapa[i][j+3]==MONTE or mapa[i][j]==AREIA && mapa[i][j+4]==MONTE){
				mapa[i][j+1]=TERRA;
				mapa[i][j+2]=TERRA;
				mapa[i][j+3]=TERRA;
				mapa[i][j+4]=TERRA;
			}
			if(mapa[i][j]==AREIA && mapa[i][j-1]==MONTE or mapa[i][j]==AREIA && mapa[i][j-2]==MONTE or mapa[i][j]==AREIA && mapa[i][j-3]==MONTE or mapa[i][j]==AREIA && mapa[i][j-4]==MONTE){
				mapa[i][j-1]=TERRA;
				mapa[i][j-2]=TERRA;
				mapa[i][j-3]=TERRA;
				mapa[i][j-4]=TERRA;
			}
		}
	}
	
	
	//Generating Snow
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j] == MONTE){
				int quant=0;
				int inicio=0;
				for(int y=i;y<LARGURA;y++){
					if(mapa[y][j]==MONTE){
						quant++;
						if(mapa[y-1][j]!=MONTE){
							inicio=y;
						}
					}else{
						if(quant>10){
							for(int u =5;u<quant-5;u++){
								mapa[inicio+u][j] = NEVE;
							}
						}
						quant=0;
					}
				}	
			}
				
		}
	}
	
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			if(mapa[i][j]==TERRA && mapa[i][j+1]==NEVE or mapa[i][j]==TERRA && mapa[i][j+2]==NEVE or mapa[i][j]==TERRA && mapa[i][j+3]==NEVE or mapa[i][j]==TERRA && mapa[i][j+4]==NEVE or mapa[i][j]==TERRA && mapa[i][j+5]==NEVE){
				mapa[i][j+1]=MONTE;
				mapa[i][j+2]=MONTE;
				mapa[i][j+3]=MONTE;
				mapa[i][j+4]=MONTE;
				mapa[i][j+5]=MONTE;
			}
			if(mapa[i][j]==TERRA && mapa[i][j-1]==NEVE or mapa[i][j]==TERRA && mapa[i][j-2]==NEVE or mapa[i][j]==TERRA && mapa[i][j-3]==NEVE or mapa[i][j]==TERRA && mapa[i][j-4]==NEVE or mapa[i][j]==TERRA && mapa[i][j-5]==NEVE){
				mapa[i][j-1]=MONTE;
				mapa[i][j-2]=MONTE;
				mapa[i][j-3]=MONTE;
				mapa[i][j-4]=MONTE;
				mapa[i][j-5]=MONTE;
			}
		}
	}
	
	
	//Putting The Map In Archive
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			map << mapa[i][j];
		}
		map << "\n";
	}
		
  	//Creating PPM image of map
  	std::fstream map_img;
	map_img.open ("map_img.ppm", ios::out);
	//PPM Head Config
	map_img.write("P3",2);
	map_img.write(" ",1);
	std::stringstream v1;
  	v1 << LARGURA;
  	cout << sizeof(v1.str().c_str());
	map_img.write(v1.str().c_str(),v1.str().length());
	map_img.write(" ",1);
	std::stringstream v2;
  	v2 << ALTURA;
	map_img.write(v2.str().c_str(),v1.str().length());
	map_img.write(" ",1);
	map_img.write("255",3);
	map_img.write("\n",1);
	
	//Generating PPM Image
	for(int j=0;j<ALTURA;j++){
		for(int i=0;i<LARGURA;i++){
			
			if(mapa[i][j] == TERRA){
				int x = rand() % 100;
				if(x>50){
					map_img.write("86",3);
					map_img.write(" ",1);
					map_img.write("150",3);
					map_img.write(" ",1);
					map_img.write("116",3);
					map_img.write(" ",1);
				}else{
					map_img.write("173",3);
					map_img.write(" ",1);
					map_img.write("220",3);
					map_img.write(" ",1);
					map_img.write("176",3);
					map_img.write(" ",1);
				}
			}else if(mapa[i][j] == AGUA){
				map_img.write("14",3);
				map_img.write(" ",1);
				map_img.write("106",3);
				map_img.write(" ",1);
				map_img.write("131",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == RAZO){
				map_img.write("179",3);
				map_img.write(" ",1);
				map_img.write("228",3);
				map_img.write(" ",1);
				map_img.write("207",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == AREIA){
				map_img.write("229",3);
				map_img.write(" ",1);
				map_img.write("229",3);
				map_img.write(" ",1);
				map_img.write("179",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == MONTE){
				map_img.write("61",3);
				map_img.write(" ",1);
				map_img.write("58",3);
				map_img.write(" ",1);
				map_img.write("51",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == NEVE){
				map_img.write("207",3);
				map_img.write(" ",1);
				map_img.write("207",3);
				map_img.write(" ",1);
				map_img.write("207",3);
				map_img.write(" ",1);
			}else{
				map_img.write("230",3);
				map_img.write(" ",1);
				map_img.write("226",3);
				map_img.write(" ",1);
				map_img.write("214",3);
				map_img.write(" ",1);
			}
			
		}
		map_img.write("\n",1);
	}



map_img.close();
map.close();

return 0;
}
