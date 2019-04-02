#define MAX_STR_LEN 50
#define MAX 50

char *strassign(char dest[], const char src[],  int dest_len){
	
	int new_len;
	int len = strlen(src); 
 

	if (len < dest_len) 
		new_len = len; 
	else
		new_len = dest_len - 1;
 
	memmove(dest, src, new_len); 
 

	dest[new_len] = '\0'; 
 
	return(dest); 
}

char *concat(char dest[], const char str1[], const char str2[], int dest_len){
	
	char result[MAX_STR_LEN];

	if ( dest_len > MAX_STR_LEN && strlen(str1) + strlen(str2) >= MAX_STR_LEN )
		printf("\nInsufficent local storage causing loss of data!\n");
		 
	strassign(result, str1, MAX_STR_LEN); 
	strncat(result, str2, MAX_STR_LEN - strlen(result) - 1);
	strassign(dest, result, dest_len); 
 
	return(dest);  
}

char *substr(char dest[], char src[], int start, int end, int dest_len){

	int sub_len;
	int len = strlen(src);
 

	if (end > len - 1)
		end = len - 1; 
 
	if (start < 0) 
		start = 0; 
 
 
	if (start > end)
		dest[0] = '\0';
	
	else{
		
		sub_len = end - start + 1; 
		
		if (sub_len >= dest_len) 
			sub_len = dest_len - 1;
 
		memmove(dest, src + start, sub_len); 
		dest[sub_len] = '\0'; 
	} 
 
	return(dest); 
 
}

char *scanline(char dest[], int dest_len){
	
	if (fgets(dest, dest_len, stdin) == 0)
		dest[0] = '\0';
 	else if (dest[strlen(dest) - 1] == '\n')
		dest[strlen(dest) - 1] = '\0';
 
	return(dest);

}
