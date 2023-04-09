/*
* File: json.h
* Author: Nguyen Phi Hung
* Date: 30/03/2023
* Description: File header for json parser in C
*/
#ifndef __JSON_H
#define __JSON_H

#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>
#include<string.h>
/*Enum save type of json*/
typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

/*Struct save value in a object*/
typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            struct JsonValue *values;
            size_t count;
        } array;
        struct {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;

/*Function get key or value type string*/
char* type_string(char **json_object);

/*function get key or value type number*/
char* type_number(char **json_object);

/*Function check and print json format*/
int parse_json(char *json_object);

#endif