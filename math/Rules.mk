## Auto generated make tool, don't edit manually.
math/$(OBJECT_DIR)/%.o: math/%.c
	$(COMP) $@ $<
math/$(OBJECT_DIR)/ft_getnblen.o: math/ft_getnblen.c math/math.h
math/math.h:
math/$(OBJECT_DIR)/ft_qsort.o: math/ft_qsort.c math/math.h \
  memory/memory.h
memory/memory.h:
math/$(OBJECT_DIR)/safe_mult.o: math/safe_mult.c math/math.h
