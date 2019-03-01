#include "points_segments.h"

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

void print_array_2D(int **arr, int rows, int cols){
	for (int i=0; i<rows; i++){
		printf("[");
		for (int j=0; j<cols; j++)
			printf("%d ",arr[i][j]);
		printf("] ");
	}
	printf("\n");
}

int are_same(int *ans1, int *ans2, int size){
	int comp=0;
	for (int i=0;i<size;i++){
		if (ans1[i]==ans2[i])
			comp++;
	}
	if (comp==size)
		return 0;
	return 1;
}
void simple_test(int **segs, int *pts, int s, int p){
	int *ans1, *ans2;
	qsort(pts, p, sizeof(int), sort_points);
	printf("sorted points: ");
	print_array(pts, p);
	/*for (int i=0;i<s;i++){
		for (int j=0;j<2;j++){
			printf("%d ",segs[i][j]); //print segs 
		}
	}*/
	ans1=naive(segs, s, pts, p);
	ans2=fast(segs, s, pts, p);
	if (are_same(ans1, ans2, p)==0)
		printf("OK\n");
	printf("naive: ");
	print_array(ans1, p);
	printf("fast: ");
	print_array(ans2, p);

}
void input_test(){
	const char * files[] = {"input1.txt", "input2.txt", "input3.txt"};   

	for (int f=0; f < 3; f++){
		FILE *pfile = fopen(files[f], "r");
		if(pfile == NULL)  {
			printf("Error opening file %s\n", files[f]);
			exit(1);
		}
		
		int s, p;
		while(fscanf(pfile, "%d %d", &s, &p)!=EOF){		
		
			//allocate 2D array to hold s segments
			int ** segments = malloc(s*sizeof(int *));
			for (int i=0; i < s; i++){
				segments[i] = malloc(2*sizeof(int));
			}
		
			//scan all segment lines and populate the segments
			for (int i=0; i < s; i++){
				fscanf(pfile, "%d %d", &segments[i][0], &segments[i][1]);
			}		
		
			//allocate a single array to hold p points
			int * points = malloc(p*sizeof(int));
		
			//scan all point coordinates into points array
			for (int i=0; i < p; i++){
				fscanf(pfile, "%d", &points[i]);
			}
			
			printf("There are total %d segments, and %d points\n", s, p);
			print_array_2D(segments, s, 2);
			print_array(points, p);
			qsort(points, p, sizeof(int), sort_points);
			printf("sorted points: ");
			print_array(points, p);
			int *ans1, *ans2;
			ans1=naive(segments, s, points, p);
			ans2=fast(segments, s, points, p);
			if (are_same(ans1, ans2, p)==0){
				printf("OK\noutput: ");
				print_array(ans1, p);
			}
			else{
				printf("naive: ");
				print_array(ans1, p);
				printf("fast: ");
				print_array(ans2, p);
				exit(1);
			}
			//TODO: pass s, p, segments, and points to your two algorithms
			//the output should be an array of size p containing 
			//-for each point- the number of covering segments 
			
			//TODO: implement - compare these outputs from 2 algorithms
			
		}
		fclose(pfile);
	}
}

int main(int argc, char **argv) {
	if (atoi(argv[1])==1 && argc==2)
		input_test();
	else if (atoi(argv[1])==0 && argc==6){
		int p=atoi(argv[5]);
		int s=atoi(argv[4]);
		int **segs = malloc(s*sizeof(int *));
			for (int i=0; i < s; i++){
				segs[i] = malloc(2*sizeof(int));
			}
		int *pts=malloc(p*sizeof(int));//strlen(argv[2])%5+1 is number of arrays
		int count=0, seg_pt=0;
		for (int i=0;i<strlen(argv[2]);i++){
			//printf("char: %c %d %d\n",argv[2][i], count,seg_pt);
			if (isdigit(argv[2][i])){
				//printf("%d %d,",count, seg_pt);
				segs[count][seg_pt]=argv[2][i]-'0';
				seg_pt++;
				if (seg_pt>seg_pt%2)
					count++;
				seg_pt=seg_pt%2;//so seg_pt is 0 or 1
			}
		}
        count=0;
        char* token = strtok(argv[3], ","); 
        while (token != NULL) { 
          pts[count]=atoi(token); 
          count++;
          token = strtok(NULL, ","); 
        }
		simple_test(segs, pts, s, p);
	} else{
		printf("input test: test <1>\nsimple test: test <0> <Segment array> <Point array> <s> <p>\nSeg array= [1,2],[3,4]\nPt array=1,2,3,4\nNO SPACE IN BETWEEN\n");
	}
	return 0;
}