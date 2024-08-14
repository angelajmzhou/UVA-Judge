#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

/*
 * this hashtable stores the dictionary.  For this purpose you really
 * want to just use a set: "is a word in the dictionary or not", so
 * for storing data the keys should strings that represent valid words
 * and the associated data should also be the same string.
 */
=
/*
 * the MAIN routine.  You can safely print debugging information
 * to standard error (stderr) and it will be ignored in the grading
 * process, in the same way which this does.
 */
int main(int argc, char **argv) {
    dictionary = createHashTable(100,stringHash,stringEquals); //size doesn't matter, hashtable will realloc
    readDictionary(argv[1]);
    processInput();
  /* main in C should always return 0 as a way of telling
     whatever program invoked this that everything went OK.

     You should free the dictionary when done.
     */
  freeTable(dictionary);
  return 0;
}

/*
 * You need to define this function. void *s can be safely casted
 * to a char * (NULL terminated string) which is done for you here for
 * convenience.
 */
unsigned int stringHash(void *s) {
  char *string = (char *)s;
  unsigned int hash = 0;
  int i = 0;
  while((char)string[i]!='\0'){ // segv here, is going past allocated mem due to not being nul???
    hash =hash*31+(string[i]); //horner's method
   // printf("%s: added to hash, iteration %d\n", string, i); //this 
    i++;
  }
  return hash;
}

/*
 * You need to define this function.  It should return a nonzero
 * value if the two strings are identical (case sensitive comparison)
 * and 0 otherwise.
 */
int stringEquals(void *s1, void *s2) {
  char *string1 = (char *)s1;
  char *string2 = (char *)s2;
  if(strcmp(string1,string2)==0){ //heap use after free
    return 1;
  }
  return 0;
}

/*
 * this function should read in every word in the dictionary and
 * store it in the dictionary.  You should first open the file specified,
 * then read the words one at a time and insert them into the dictionary.
 * Once the file is read in completely, exit.  You will need to allocate
 * (using malloc()) space for each word.  As described in the specs, you
 * can initially assume that no word is longer than 60 characters.  However,
 * for the final 20% of your grade, you cannot assumed that words have a bounded
 * length.  You can NOT assume that the specified file exists.  If the file does
 * NOT exist, you should print some message to standard error and call exit(0)
 * to cleanly exit the program.
 *
 * Since the format is one word at a time, with returns in between,
 * you can safely use fscanf() to read in the strings until you want to handle
 * arbitrarily long dictionary chacaters.
 */
void readDictionary(char *filename) {
  FILE *fp;		/* points to input file */
	/*
	 * open the file with read-only access, returning file error if it cannot be opened. 
	 */

	if ((fp = fopen(filename, "rb")) == NULL){
		fprintf(stderr, "cannot open file\n");
    perror(filename);
		exit(0);
  }
    char *word;
    while(1){
    word = malloc(sizeof(char)*61); //not properly freed
    if(!word){
    fprintf(stderr, "mem allocation error\n");
    fclose(fp);
    exit(0);
  }
    int ch, i = 0;
    //read each char from the file individually; while newline char isn't read AND not EOF, keep going
    while ((ch=fgetc(fp))!=EOF && ch != '\n'){
      //place each character read in sequentially
        word[i++] = ch; //heap use after free!!!!
        //resize right before we hit the end, add one due to 1 space needed for string nul "\0"
        if (i>=60 && (i-1)%60==0){
          char *temp = realloc(word, (i+60)*sizeof(char)); //place word into newly re-allocated space
          if(!temp){ //in the case we aren't able to do that
            fprintf(stderr, "mem allocation error\n");
            fclose(fp);
            exit(0); 
          }
          word = temp;
        }
    }
    if(ch==EOF&&i==0){
      free(word);
      break;
      } //in the case we hit the end of the file and nothing is read
    word[i] = '\0'; //add null terminator for that word, then move on to the next
    insertData(dictionary,word, word); //insert info into dictionary, memory issue here + hashtable l44
  }
    fclose(fp); // close file after
}
int checkAllCases (char *word){
  if (findData(dictionary,word)){return 1;} //only get this far
  int i = 1;
  while (word[i] != '\0'){ // not going trhough loop
      word[i] = tolower(word[i]); 
      i++;
  }
  word[i]= '\0'; //not changing the values...
  if (findData(dictionary, word)) {return 1;}
  word[0] = tolower(word[0]);
  if (findData(dictionary, word)) {return 1;}
  return 0;
}


/*
 * This should process standard input and copy it to standard output
 * as specified in the specs.  EG, if a standard dictionary was used
 * and the string "this is a taest of  this-proGram" was given to
 * standard input, the output to standard output (stdout) should be
 * "this is a teast [sic] of  this-proGram".  All words should be checked
 * against the dictionary as they are input, again with all but the first
 * letter converted to lowercase, and finally with all letters converted
 * to lowercase.  Only if all 3 cases are not in the dictionary should it
 * be reported as not being found, by appending " [sic]" after the
 * error.
 *
 * Since we care about preserving whitespace, and pass on all non alphabet
 * characters untouched, and with all non alphabet characters acting as
 * word breaks, scanf() is probably insufficent (since it only considers
 * whitespace as breaking strings), so you will probably have
 * to get characters from standard input one at a time.
 *
 * As stated in the specs, you can initially assume that no word is longer than
 * 60 characters, but you may have strings of non-alphabetic characters (eg,
 * numbers, punctuation) which are longer than 60 characters. For the final 20%
 * of your grade,  you can no longer assume words have a bounded length.
 */
void processInput() {
  int ch;
  int sz = 61;
  int added_sz = 61;
  char *word = calloc(sz, sizeof(char));
  if(!word){ //in the case we aren't able to do that
    fprintf(stderr, "mem allocation error\n");
    exit(0); 
  }
  while(1){
    int i = 0;
    while ((ch=getchar())!=EOF && isalpha(ch)){
      word[i++] = (char) ch;
      if(i >= sz) {
        sz = sz + added_sz;
        char * temp = realloc(word, sz*sizeof(char)); //place word into newly re-allocated space (other pointers to same space not updated)
        if(!temp){ //in the case we aren't able to do that
            fprintf(stderr, "mem allocation error\n");
            exit(0); 
        }
        word = temp;
      }
    }
    if (i > 0) {//adds null terminator to the end if it's a real word and not a poser >:[
        word[i] = '\0';
        printf("%s", word);
        if(!checkAllCases(word)) {
          printf(" [sic]"); //omg fake
        }
    }
    if (ch != EOF) {
      putchar(ch);//can't free char... so whats the prob...
    }
    else {
      break;
    }
  }
  free(word);
  return;
}
