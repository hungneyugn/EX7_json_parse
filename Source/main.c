/*
* File: main.c
* Author: Nguyen Phi Hung
* Date: 30/03/2023
* Description: json parser in C
*/
#include<json.h>

char *json_object = "{\"ten\":\"Nguyen A\", \"tuoi\": 19, \"diachi\": \"HCM\"}";

int main(int argc, char const *argv[])
{
    parse_json(json_object);
    return 0;
}


