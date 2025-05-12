// 通过 next 数组求 nextval 数组
// 当某一个字符与其 next 数组所指的对应序号的模式串字符相等时
// 将 next 数组序号改为其对应模式串字符的 next 数组的序号

nextval[1] = 0;
for(j = 2; j <= T.length; j++){
    if(T.ch[j] == T.ch[next[j]]){
        nextval[j] = nextval[next[j]];
    }
    else{
        nextval[j] = next[j];
    }
}