## Auto generated make tool, don't edit manually.

OBJ_FILES_output/printf  :=  itoa_base.o \
               len_utils.o \
               parse_utils.o \
               parser.o \
               printf.o \
               spec_binary.o \
               spec_char.o \
               spec_decimal.o \
               spec_default.o \
               spec_hex.o \
               spec_mod.o \
               spec_oct.o \
               spec_ptr.o \
               spec_string.o \
               spec_wchar.o \
               write_handle.o
OBJECTS   += $(patsubst %, output/printf/$(OBJECT_DIR)/%, $(OBJ_FILES_output/printf))
