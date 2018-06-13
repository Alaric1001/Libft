#!/bin/bash

# This utility build each `subdir'/Sources.mk and `subdir'/Rules.mk
# where 'subdir` is given in parameters

for i in $*; do
	SOURCES_OUT="${i}/Sources.mk"
	echo -e "## Auto generated make tool, don't edit manually.\n" > "${SOURCES_OUT}"
	echo -n "OBJ_FILES_${i}  :=  " >> "${SOURCES_OUT}"

	ls "$i"/*.c | # list all the C files in the current subdirectory
	xargs -L1 basename | # just get the basename of these files
	sed -e '$ ! s/$/ &\\/g' | # set a backslash at the end of each lines except the last one
	sed -e 's/\.c/\.o/g' | # *.c -> *.o
	sed -e '2,$ s/^/&               /g' >> "${SOURCES_OUT}" #indent and output

	echo -n 'OBJECTS   += $(patsubst %, ' >> "${SOURCES_OUT}"
	echo -n "$i/" >> "${SOURCES_OUT}"
	echo -n '$(OBJECT_DIR)/%, $(' >> "${SOURCES_OUT}"
	echo "OBJ_FILES_${i}))" >> "${SOURCES_OUT}"

	RULES_OUT="${i}/Rules.mk"
	echo -e "## Auto generated make tool, don't edit manually.\n" > "${RULES_OUT}"
	echo "${i}/\$(OBJECT_DIR)/%.o: ${i}/%.c" >> "${RULES_OUT}"
	echo -e '\t$(COMP) $@ $<' >> "${RULES_OUT}"
	for src in `ls "${i}"/*.c | xargs -L1 basename`; do
	  gcc -E -MT `echo "${i}"'/$(OBJECT_DIR)/'"${src}" | sed -e 's/\.c/\.o/g'` -MMD -MP -MF t.d "${i}"/"${src}" -I. > /dev/null &&
	  cat t.d >> "${RULES_OUT}"
	done
	awk 'NF && (!/:$/ || !seen[$0]++)' ${RULES_OUT} > t.d
	cat t.d > ${RULES_OUT}
	rm -f t.d
done
