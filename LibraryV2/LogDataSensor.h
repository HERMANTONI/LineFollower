int dataSensor[]={0,0,0,0,0,0,0,0,0,0};
int logDataSens(int data){
    for (int a = 10; a>0; a--){
        dataSensor[a] = dataSensor[a-1];
    }
    dataSensor[0] = data;
}
