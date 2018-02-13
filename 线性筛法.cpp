bool isPri[maxn];//0为素数，1为合数
int Pri[maxn / 10];//记录素数
void getPri(){
    memset(isPri, 0, sizeof(isPri));
    isPri[0] = isPri[1] = 1;
    int cnt = 0;
    for(int i = 2; i < maxn; ++i){
        if(!isPri[i]){
            Pri[cnt++] = i;
        }
        for(int j = 0; j < cnt && Pri[j] * i < maxn; ++j){
            isPri[i * Pri[j]] = 1;
            if(i % Pri[j] == 0){
                break;
            }
        }
    }
}
