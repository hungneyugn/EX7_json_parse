/*
* File: json.c
* Author: Nguyen Phi Hung
* Date: 30/03/2023
* Description: define functions which were declarated in header file
*/

#include<json.h>

/*
* Function: type_string
* Description: This function get key or value type string
* Input:
*   json_object - an pointer to pointer, point to the address of poiter which point to the json string
* Output:
*   returns value type string
*/
char* type_string(char **json_object)
{
    int i =0;
    char* value = (char*)malloc(sizeof(char));
    while(**json_object == ' ')(*json_object)++;
    if(**json_object == '\"') (*json_object)++;
    while (**json_object != '\"')
    {
        value[i] = *((*json_object)++);
        i++;  
        value = (char*)realloc(value,(i+1)*sizeof(char));
    }
    if(**json_object == '\"') (*json_object)++;
    if(**json_object == ':')(*json_object)++;
    else if(**json_object == ',')(*json_object)++;
    while(**json_object == ' ')(*json_object)++;
    return value;
}
/*
* Function: type_number
* Description: This function get key or value type number
* Input:
*   json_object - an pointer to pointer, point to the address of poiter which point to the json string
* Output:
*   returns value type number
*/
char* type_number(char **json_object)
{
    int i =0;
    char* value = (char*)malloc(sizeof(char));
    while(**json_object == ' ')(*json_object)++;
    while (((int)**json_object)>=48 && ((int)**json_object)<=57)
    {
        value[i] = *((*json_object)++);
        i++;  
        value = (char*)realloc(value,(i+1)*sizeof(char));
    }
    if(**json_object == ',')(*json_object)++;
    return value;
}
/*
* Function: parse_json
* Description: This function check and print json format 
* Input:
*   json_object - an pointer pointing to the json string
*Output:
*  json format
*/
int parse_json(char *json_object){

    char key[10];
    char value[20];
    int index = 0;
    int i = 0;
    while (1)
    {
        if(*json_object == '{') json_object++;
        strcpy(key,type_string(&json_object));
        if(*json_object == '\"')strcpy(value,type_string(&json_object));
        else strcpy(value,type_number(&json_object));
        printf("Key: %s, value: %s\n", key,value);
        if(*json_object == '}') return -1;
    }
}