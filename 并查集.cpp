int par[MAX_N];//fathers
int rak[MAX_N];//height of trees

//initialize n elements
void init(int n)
{
    for(int i = 0; i < n; i++){
        par[i] = i;
        rak[i] = 0;
    }
}

//root search
int findroot(int x)
{
    if( par[x] == x ){
        return x;
    }else {//ÓÅ»¯
        return par[x] = findroot(par[x]);
    }
}

//make sets together
void unite(int x, int y){
    x = findroot(x);
    y = findroot(y);

    if(x == y)
        return;

    if(rak[x] < rak[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rak[x] == rak[y])
            rak[x]++;
    }
}

//findout whether x and y have the same sett
bool issame(){
    return findroot(x) == findroot(y);
}
