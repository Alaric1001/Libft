#ifndef FT_PATH_H
#define FT_PATH_H


char	*ft_path_append(char const *path, char const *app);
char	**ft_splitfilepath(char const *file);
int		ft_star_match(char const *str, char const *pattern);

#endif 
