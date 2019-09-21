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
	int width= 100;
	int height = 60;
	
	char WATER  = '.';
	char GRASS = 'i';
	char SAND = 'T';
	char MOUNTAIN = 'M';
	char SNOW  = 'N';
	char SHALLOW  = 'R';
	
	
	
	cout<<"map width (standard: 100) (max: 1000):";
	cin>>width;
	cout<<"map height (standard: 60)  (max: 1000):";
	cin>>height;
	char mapa [width][height];
	
	//Filling the map with water
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			mapa[i][j] = WATER;
		}
	}
	
	
	//Generating Initial Land Points
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			int x = rand() % 300;
			if(x < 4 && i>5 && i<width-5 && j>5 && j<height-5){
				mapa[i][j] = '1';
			}
		}
	}
		
	
	//Generating Lands From Initial Points
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j] == '1'){
				for(int a=i-5;a<=i+5;a++){
					for(int b=j-5;b<=j+5;b++){
						if(a == i && b == j){
						}else{
							int x = rand() % 100;
							if(x > 50){
								mapa[a][b]= GRASS;
							}	
						}	
					}
				}
			}
		}
	}
	
	//Removing Initial Land Points
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j] == '1'){
				mapa[i][j]=GRASS;
			}		
		}
	}
	
	
	//Filling Map Edges With Water
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(i < 3 or i>width-3 or j<3 or j>height-3){
				mapa[i][j]=WATER;
			}		
		}
	}
	
	//Filling with Land Water points Btween Land Points
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			//WATER ENTRE DUAS GRASSS
			if(mapa[i][j] == GRASS && mapa[i+1][j] == WATER && mapa[i+2][j] == GRASS){
				mapa[i+1][j] = GRASS;
			}
			if(mapa[i][j] == GRASS && mapa[i-1][j] == WATER && mapa[i-2][j] == GRASS){
				mapa[i-1][j] = GRASS;
			}
			if(mapa[i][j] == GRASS && mapa[i][j+1] == WATER && mapa[i][j+2] == GRASS){
				mapa[i][j+1] = GRASS;
			}
			if(mapa[i][j] == GRASS && mapa[i][j-1] == WATER && mapa[i][j-2] == GRASS){
				mapa[i][j-1] = GRASS;
			}
			//DUAS WATERS ENTRE DUAS GRASSS
			if(mapa[i][j] == GRASS && mapa[i+1][j] == WATER && mapa[i+2][j] == WATER && mapa[i+3][j] == GRASS){
				mapa[i+1][j] = GRASS;
				mapa[i+2][j] = GRASS;
			}if(mapa[i][j] == GRASS && mapa[i-1][j] == WATER && mapa[i-2][j] == WATER && mapa[i-3][j] == GRASS){
				mapa[i-1][j] = GRASS;
				mapa[i-2][j] = GRASS;
			}if(mapa[i][j] == GRASS && mapa[i][j+1] == WATER && mapa[i][j+2] == WATER && mapa[i][j+3] == GRASS){
				mapa[i][j+1] = GRASS;
				mapa[i][j+2] = GRASS;
			}if(mapa[i][j] == GRASS && mapa[i][j-1] == WATER && mapa[i][j-2] == WATER && mapa[i][j-3] == GRASS){
				mapa[i][j+1] = GRASS;
				mapa[i][j+2] = GRASS;
			}
			
			
		}
	}
	
	//Generating beaches
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j] == WATER && mapa[i+1][j] == GRASS && mapa[i+2][j] == GRASS && mapa[i+3][j]==GRASS){
				mapa[i+1][j] = SAND;
				
			}if(mapa[i][j] == WATER && mapa[i-1][j] == GRASS && mapa[i-2][j] == GRASS && mapa[i-3][j]==GRASS){
				mapa[i-1][j] = SAND;
				
			}if(mapa[i][j] == WATER && mapa[i][j+1] == GRASS && mapa[i][j+2] == GRASS && mapa[i][j+3]==GRASS){
				mapa[i][j+1] = SAND;
				
			}if(mapa[i][j] == WATER && mapa[i][j-1] == GRASS && mapa[i][j-2] == GRASS && mapa[i][j-3]==GRASS){
				mapa[i][j-1] = SAND;
				
			}
				
		}
	}
	
	
	
	//Generating shallow
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j] == SAND && mapa[i+1][j] == WATER && mapa[i+2][j] == WATER){
				mapa[i+1][j] = SHALLOW;
				mapa[i+2][j] = SHALLOW;
			}
			if(mapa[i][j] == SAND && mapa[i-1][j] == WATER && mapa[i-2][j] == WATER){
				mapa[i-1][j] = SHALLOW;
				mapa[i-2][j] = SHALLOW;
			}
			if(mapa[i][j] == SAND && mapa[i][j+1] == WATER && mapa[i][j+2] == WATER){
				mapa[i][j+1] = SHALLOW;
				mapa[i][j+2] = SHALLOW;
			}
			if(mapa[i][j] == SAND && mapa[i][j-1] == WATER && mapa[i][j-2] == WATER){
				mapa[i][j-1] = SHALLOW;
				mapa[i][j-2] = SHALLOW;
			}
			
		}
	}
	
	
	
	//Generating Mountains
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j] == GRASS){
				int quant=0;
				int inicio=0;
				for(int y=i;y<width;y++){
					if(mapa[y][j]==GRASS){
						quant++;
						if(mapa[y-1][j]!=GRASS){
							inicio=y;
						}
					}else{
						if(quant>8){
							for(int u =4;u<quant-4;u++){
								mapa[inicio+u][j] = MOUNTAIN;
							}
						}
						quant=0;
					}
				}	
			}
				
		}
	}
	
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j]==SAND && mapa[i][j+1]==MOUNTAIN or mapa[i][j]==SAND && mapa[i][j+2]==MOUNTAIN or mapa[i][j]==SAND && mapa[i][j+3]==MOUNTAIN or mapa[i][j]==SAND && mapa[i][j+4]==MOUNTAIN){
				mapa[i][j+1]=GRASS;
				mapa[i][j+2]=GRASS;
				mapa[i][j+3]=GRASS;
				mapa[i][j+4]=GRASS;
			}
			if(mapa[i][j]==SAND && mapa[i][j-1]==MOUNTAIN or mapa[i][j]==SAND && mapa[i][j-2]==MOUNTAIN or mapa[i][j]==SAND && mapa[i][j-3]==MOUNTAIN or mapa[i][j]==SAND && mapa[i][j-4]==MOUNTAIN){
				mapa[i][j-1]=GRASS;
				mapa[i][j-2]=GRASS;
				mapa[i][j-3]=GRASS;
				mapa[i][j-4]=GRASS;
			}
		}
	}
	
	
	//Generating Snow
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j] == MOUNTAIN){
				int quant=0;
				int inicio=0;
				for(int y=i;y<width;y++){
					if(mapa[y][j]==MOUNTAIN){
						quant++;
						if(mapa[y-1][j]!=MOUNTAIN){
							inicio=y;
						}
					}else{
						if(quant>10){
							for(int u =5;u<quant-5;u++){
								mapa[inicio+u][j] = SNOW;
							}
						}
						quant=0;
					}
				}	
			}
				
		}
	}
	
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			if(mapa[i][j]==GRASS && mapa[i][j+1]==SNOW or mapa[i][j]==GRASS && mapa[i][j+2]==SNOW or mapa[i][j]==GRASS && mapa[i][j+3]==SNOW or mapa[i][j]==GRASS && mapa[i][j+4]==SNOW or mapa[i][j]==GRASS && mapa[i][j+5]==SNOW){
				mapa[i][j+1]=MOUNTAIN;
				mapa[i][j+2]=MOUNTAIN;
				mapa[i][j+3]=MOUNTAIN;
				mapa[i][j+4]=MOUNTAIN;
				mapa[i][j+5]=MOUNTAIN;
			}
			if(mapa[i][j]==GRASS && mapa[i][j-1]==SNOW or mapa[i][j]==GRASS && mapa[i][j-2]==SNOW or mapa[i][j]==GRASS && mapa[i][j-3]==SNOW or mapa[i][j]==GRASS && mapa[i][j-4]==SNOW or mapa[i][j]==GRASS && mapa[i][j-5]==SNOW){
				mapa[i][j-1]=MOUNTAIN;
				mapa[i][j-2]=MOUNTAIN;
				mapa[i][j-3]=MOUNTAIN;
				mapa[i][j-4]=MOUNTAIN;
				mapa[i][j-5]=MOUNTAIN;
			}
		}
	}
	
	
	//Putting The Map In Archive
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
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
  	v1 << width;
  	cout << sizeof(v1.str().c_str());
	map_img.write(v1.str().c_str(),v1.str().length());
	map_img.write(" ",1);
	std::stringstream v2;
  	v2 << height;
	map_img.write(v2.str().c_str(),v1.str().length());
	map_img.write(" ",1);
	map_img.write("255",3);
	map_img.write("\n",1);
	 
	//Generating PPM Image
	for(int j=0;j<height;j++){
		for(int i=0;i<width;i++){
			
			if(mapa[i][j] == GRASS){
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
			}else if(mapa[i][j] == WATER){
				map_img.write("14",3);
				map_img.write(" ",1);
				map_img.write("106",3);
				map_img.write(" ",1);
				map_img.write("131",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == SHALLOW){
				map_img.write("179",3);
				map_img.write(" ",1);
				map_img.write("228",3);
				map_img.write(" ",1);
				map_img.write("207",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == SAND){
				map_img.write("229",3);
				map_img.write(" ",1);
				map_img.write("229",3);
				map_img.write(" ",1);
				map_img.write("179",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == MOUNTAIN){
				map_img.write("61",3);
				map_img.write(" ",1);
				map_img.write("58",3);
				map_img.write(" ",1);
				map_img.write("51",3);
				map_img.write(" ",1);
			}else if(mapa[i][j] == SNOW){
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
