class Queens {
public:
    bool valid(int arr[],int row,int col){
        for(int row2=0;row2<row;row2++){
            int col2 = arr[row2];
            if(col2==col) return false;
            if(abs(col2-col)==(row-row2)) return false;
        }
        return true;
    }
    void place(int arr[],int row,int n,int& count){
        if(row == n) {
            count++;
            return ;
        }
        for(int i=0;i<n;i++){
            if(valid(arr,row,i)){
                arr[row] = i;
                place(arr,row+1,n,count);
            }
        }
    }
    int nQueens(int n) {
        int* arr = new int[n];
        int count = 0;
        place(arr,0,n,count);
        return count;
    }
};
