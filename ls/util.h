#if !defined(LS_UTILITIES)
#define LS_UTILITIES

/*
  fill: (string, int, char) -> int
  it takes a string and character, then fill specific lenght of the given string with the given char.
  Returns: 0 if ok.
*/
int fill(char *str, int len, char c);

/*
  is_exists: (char, string) -> int 
  it checks if the given char is exists in the given string.
  Returns: 0 if is not exists, 1 if is exists.
*/
int is_exists(char c, char *str);

/*
  get_options: (char *, int, char **) -> int
  it changes the given string to include the desired options.
  Returns: 0 if ok.
*/
int get_options(char *opt, int argc, char **argv);

#endif // LS_UTILITIES
