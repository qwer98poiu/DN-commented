#include <stdio.h>
#include <stdlib.h>

int x[1000], out[1000];
int main()
{
	int batch = 1, c = 9, w = 6, h = 6, stride = 3, forward = 0;
	freopen("out.txt", "w", stdout);
    int b,i,j,k;
    int out_c = c/(stride*stride);	
	for (i = 0; i < 1000; i++)
		x[i] = i;
    for(b = 0; b < batch; ++b){
        for(k = 0; k < c; ++k){
            for(j = 0; j < h; ++j){
                for(i = 0; i < w; ++i){
                    int in_index  = i + w*(j + h*(k + c*b));
                    int c2 = k % out_c;//输出到第几张图
                    int offset = k / out_c;//
                    int w2 = i*stride + offset % stride;
                    int h2 = j*stride + offset / stride;
                    int out_index = w2 + w*stride*(h2 + h*stride*(c2 + out_c*b));
                    if(forward) out[out_index] = x[in_index];
                    else out[in_index] = x[out_index];
                }
            }
        }
    }
    for (i = 0; i < 1000; i++)
    {
    	printf("%d ", out[i]);
    	if (i % 2 == 1)
    		printf("\n");
    }
    
}
