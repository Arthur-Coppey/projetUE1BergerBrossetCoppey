
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t t1, t2, dt, dtbefore = 0;
int rythme(clock_t t3);

int main(){
	t1 = clock();
	int ok = 0;
	while(ok != 1){
		;
		t2 = clock();
		dt = t2 - t1;
		if(dt != dtbefore){
			dtbefore = dt;
			printf("%d    %d\n", dt, rythme(dt));
			fflush(stdout);
			if(dt == 1200){
				ok = 1;
			}
		}
	}
}


int rythme(clock_t dt){
	if(dt % 1166 == 0){
		return 1;
	}
	else{
		return 0;
	}

}
