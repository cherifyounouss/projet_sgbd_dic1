#include <stdio.h>
#include <stdlib.h>
#include "../include/cJSON.h"

void test(cJSON* json, FILE* fp);

/* Cette fonction permet de recuper le contenu du fichier json au niveau d'une chaine de caracteres */
char* chaine_json(char *filename)
{
    FILE *f = NULL;
    long len = 0;
    char *json_data = NULL;

    /* Ouverture du fichier json en mode lecture et binaire */
    f = fopen(filename,"rb");
    /* On place le curseur a la fin et on recupere le nombre de caracteres du fichier, du debut jusqu'a la fin */
    fseek(f, 0, SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);

    /*Creation d'une chaine de len+1 caracteres */
    json_data = (char*)malloc(len + 1);

    /* On lit et on stocke toutes les caracteres au niveau de json_data*/
    fread(json_data, 1, len, f);
    json_data[len] = '\0';
    fclose(f);

    return json_data;
}

void test2(cJSON* json, FILE* fp){
    cJSON *current_element = NULL;
    if(cJSON_IsArray(json)){
        printf("Entite\n");
        fputs("Entite:", fp);
        fputs(json->string, fp);
        fputc(',', fp);
        printf("%s\n", json->string);
        if(json->child)
            test2(json->child, fp);
    }

    if(cJSON_IsString(json)){
        printf("Atrribut: %s\n", json->string);
        fputs(json->string, fp);
        if (cJSON_IsString(json->next)) {
            fputc(',', fp);
        }
        else{
            fputc(';', fp);
        }
        
        if(json->next)
            test2(json->next, fp);
    }

    if(cJSON_IsObject(json)){
        if(json->string){
            fputs("Association:", fp);
            fputs(json->string, fp);
            fputc(',', fp);
            printf("Association\n");
            printf("%s\n", json->string);
        }
        if(json->child)
            test2(json->child, fp);
    }
}

void test(cJSON* json, FILE* fp){
    // printf("Size : %d\n", cJSON_GetArraySize(json));
    cJSON *current_element = NULL;
    char *current_key = NULL;

    cJSON_ArrayForEach(current_element, json)
    {
        // current_key = current_element->string;
        // if (current_key != NULL)
        // {
        //     printf("%s\n", current_key);
        // }
        test2(current_element, fp);
        fputc('\n', fp);
    }
}


int main(int argc, char const *argv[])
{
    FILE *fp;
    fp = fopen("tmp", "w+");

    char* json_data;
    json_data = chaine_json(argv[1]);
    cJSON* json = NULL;
    json = cJSON_Parse(json_data);
    test(json, fp);
    fclose(fp);
    return 0;
}