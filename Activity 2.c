#include <stdio.h>

typedef struct RelationMatrix {
    int size;
    int point[3];
    int array[100][100];
    int isTransitive;
}Matrix;


Matrix input_one_array() {
    Matrix temp;
    scanf("%d",&temp.size);
    for(int i=0;i<temp.size;i++) {
        for(int j=0;j<temp.size;j++){
            scanf("%d",&temp.array[i][j]);
        }
    }
    return temp;
}

void input_n_array(int testCases, Matrix matrices[testCases]){
    for(int i=0;i<testCases;i++){
        matrices[i]=input_one_array();
    }
}

int check_one_relation(Matrix *matrix) {
    for(int i=0;i<matrix->size;i++) {
        for(int j=0;j<matrix->size;j++){
	        if(matrix->array[i][j]==1)
                for(int k=0;k<matrix->size;k++){
                    if(matrix->array[i][j] && matrix->array[j][k])
                        if(! matrix->array[i][k]) {
                            matrix->point[0]=i;
                            matrix->point[1]=j;
                            matrix->point[2]=k;
                            return 0;
                        }
                }
            }
        }
    }
    return 1;
}


void check_n_relation(int testCases, Matrix matrices[testCases]){
    for(int i=0;i<testCases;i++){
        matrices[i].isTransitive=check_one_relation(&matrices[i]);
    }
}

void display_one_output(Matrix matrix){
    if(matrix.isTransitive) printf("Transitive\n");
    else printf("Not Transitive %d %d %d\n",matrix.point[0],matrix.point[1], matrix.point[2]);
}

void display_n_output(int testCases, Matrix matrices[testCases]) {
    for(int i=0;i<testCases;i++){
        display_one_output(matrices[i]);
    }
}

int main() {
    int testCases;
    scanf("%d",&testCases);
    Matrix matrices[testCases];
    input_n_array(testCases, matrices);
    check_n_relation(testCases, matrices);
    display_n_output(testCases, matrices);
    return 0;
}
