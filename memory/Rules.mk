## Auto generated make tool, don't edit manually.
memory/$(OBJECT_DIR)/%.o: memory/%.c
	$(COMP) $@ $<
memory/$(OBJECT_DIR)/ft_bzero.o: memory/ft_bzero.c memory/memory.h
memory/memory.h:
memory/$(OBJECT_DIR)/ft_doublearraydel.o: memory/ft_doublearraydel.c \
  memory/memory.h
memory/$(OBJECT_DIR)/ft_doublearrayndel.o: memory/ft_doublearrayndel.c \
  memory/memory.h
memory/$(OBJECT_DIR)/ft_free_array.o: memory/ft_free_array.c \
  memory/memory.h
memory/$(OBJECT_DIR)/ft_malloc_or_panic.o: memory/ft_malloc_or_panic.c \
  memory/memory.h output/output.h
output/output.h:
memory/$(OBJECT_DIR)/ft_memalloc.o: memory/ft_memalloc.c memory/memory.h
memory/$(OBJECT_DIR)/ft_memccpy.o: memory/ft_memccpy.c memory/memory.h
memory/$(OBJECT_DIR)/ft_memchr.o: memory/ft_memchr.c memory/memory.h
memory/$(OBJECT_DIR)/ft_memcmp.o: memory/ft_memcmp.c memory/memory.h
memory/$(OBJECT_DIR)/ft_memcpy.o: memory/ft_memcpy.c memory/memory.h
memory/$(OBJECT_DIR)/ft_memdel.o: memory/ft_memdel.c memory/memory.h
memory/$(OBJECT_DIR)/ft_memmove.o: memory/ft_memmove.c memory/memory.h
memory/$(OBJECT_DIR)/ft_memset.o: memory/ft_memset.c memory/memory.h
memory/$(OBJECT_DIR)/ft_realloc.o: memory/ft_realloc.c memory/memory.h
