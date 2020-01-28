# cs213-ngram-generator

### Assignment for cs-213 Operating Systems at Grinnell College. 
The task is to implement a c program which generates all possible substrings of length n from user input.

### Example usage: 
```$ echo "Some String" | ./ngram N```
Note that on some systems the echo command will add a newline character to the end of the string, which will be counted as a character for the purposes of ngrams. To avoid this newline character, run the command as such:
```$ echo -e "Some string\c" | ./ngram N```
