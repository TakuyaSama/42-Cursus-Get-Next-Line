#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

int		get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s);
char   		*ft_substr(char const *s, unsigned int start, size_t len);
static int	check_read(int i, char **line, char *aux);
static int      set_line(char **line, char *aux);
#endif
