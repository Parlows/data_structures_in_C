
# Compiler
CC := gcc
CFLAGS := -Wall
DEBUG := -g

# Common dirs
BUILDDIR := build
EXAMPLEDIR := examples
INCLUDEDIR := include
SRCDIR := structures

# Main file
MAIN := main.c

# Structure subdirs
STRINGS := array_strings
STRINGSSUBDIR := arrays/strings
STRINGSFILE := $(STRINGSSUBDIR)/$(STRINGS)

# Macros
MKDIR := mkdir -p


.PHONY: strings

$(BUILDDIR)/$(STRINGSFILE).o: $(SRCDIR)/$(STRINGSFILE).c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c -I$(INCLUDEDIR) -o $@ $<

$(BUILDDIR)/$(EXAMPLEDIR)/$(STRINGSFILE).out: $(BUILDDIR)/$(STRINGSFILE).o $(EXAMPLEDIR)/$(STRINGSSUBDIR)/$(MAIN)
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $@ $^

strings: $(BUILDDIR)/$(EXAMPLEDIR)/$(STRINGSFILE).out




.PHONY: clean

clean:
	@rm -rfv build/
