#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(sizeof(char) * (len + 1));
    char* temp = (char*)malloc(sizeof(char) * (len + 1));

    int count = 0;
    int wordBegin = 0;
    for (int i = 0; i <= len; ++i)
    {
        if (s[i] == ' ' || s[i] == '\0') // 공백 또는 문자열 끝 문자가 아닐 때 
        {
            strncpy(temp, s + wordBegin, count); // 중요   
            // null terminator 추가
            temp[count] = '\0';
            for (int j = 0; j < count; ++j) // strlen(temp) 대신 count
            {
                temp[j] = (j % 2 == 0) ? toupper(temp[j]) : tolower(temp[j]);

            }

            // 공백 위치 -> 단어 시작 위치로 변경
            strcpy(answer + wordBegin, temp);

            // 공백 그대로 넣어주기
            if (s[i] == ' ')
            {
                answer[i] = ' ';
            }
            count = 0;
            wordBegin = i + 1;
        }
        else
        {
            ++count;
        }

    }

    // 문자열 종료 문자 추가
    answer[len] = '\0';
    return answer;
}