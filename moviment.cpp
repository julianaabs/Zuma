#include <iostream>

void movimento(){
	int x=100,y = 57;
	row = 0;
	while(true){
		if(row == 0){
			x++;
			if(x==570){
				row = 1;
			}
		}
		if(row == 1){
			y++;
			if(y == 315){
				row = 2;
			}
		}
		 if(row == 2){
		 	x--;
		 	if(x == 95){
		 		row = 3;
		 	}
		 }
		 if(row = 3){
		 	y--;
		 	if(y==289){
		 		//game over
		 	}
		 }
		sleep(2000);
	}
}