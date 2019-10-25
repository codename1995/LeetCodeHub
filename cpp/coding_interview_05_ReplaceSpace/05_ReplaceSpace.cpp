class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == nullptr) return;
        int cntSpace = 0, oriLength = 0;
        for (int i=0;str[i]!='\0';i++){
            oriLength++;
            if (str[i] == ' ') cntSpace++;
        }
        
        int newLength = oriLength + cntSpace * 2;
        if (newLength+1>length) return;
        char* str1 = str + oriLength;
        char* str2 = str + newLength;
        while (str1 < str2)
        {
            if (*str1==' '){
                *str2-- = '0';
                *str2-- = '2';
                *str2-- = '%';
            }
            else{
                *str2-- = *str1;
            }
            str1--;
        }
    }
};