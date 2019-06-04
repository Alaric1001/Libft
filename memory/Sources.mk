## Auto generated make tool, don't edit manually.

OBJ_FILES_memory := ft_bzero.o \
                    ft_doublearraydel.o \
                    ft_doublearrayndel.o \
                    ft_free_array.o \
                    ft_malloc_or_panic.o \
                    ft_map_file.o \
                    ft_memalloc.o \
                    ft_memccpy.o \
                    ft_memchr.o \
                    ft_memcmp.o \
                    ft_memcpy.o \
                    ft_memdel.o \
                    ft_memmove.o \
                    ft_memset.o \
                    ft_realloc.o \
                    ft_swap_bytes.o

OBJECTS += $(patsubst %, memory/$(OBJECT_DIR)/%, $(OBJ_FILES_memory))