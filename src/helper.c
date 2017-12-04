/* 
 * Application: Terminal
 * Script     : helper.c
 * Author     : Fuat Bölük
 * Creation   : 01 Aralık 2017
 * Contact    : <fuat@fuxproject.org>
 * Copyright  : Fux Project
 * License    : GPLv3+
 *
 */


/* UTF-8 Decode */
void utf8_decode(char *dst, const char *src) 
{
    char a, b;
    while(*src) 
    {
        if ((*src == '%') && ((a = src[1]) && (b = src[2])) && (isxdigit(a) && isxdigit(b))) 
        {
            if(a >= 'a') { a -= 'a'-'A'; }
            if(a >= 'A') { a -= ('A'-10); } else { a -= '0'; }
            if(b >= 'a') { b -= 'a'-'A'; }
            if(b >= 'A') { b -= ('A'-10); } else { b -= '0'; }
            *dst++ = 16*a+b;
            src+=3;
        } 
        else if(*src == '+') 
        {
            *dst++ = ' ';
            src++;
        } 
        else 
        {
            *dst++ = *src++;
        }
    }
    *dst++ = '\0';
}
