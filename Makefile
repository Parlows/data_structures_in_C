
# Compiler
CC := gcc
CFLAGS := -Wall -g
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

STACKSUBDIR := stack
ARRAY_STACK := array_stack
ARRAY_STACKFILE := $(STACKSUBDIR)/$(ARRAY_STACK)
LINKED_STACK := linked_stack
LINKED_STACKFILE := $(STACKSUBDIR)/$(LINKED_STACK)

# Macros
MKDIR := mkdir -p

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.PHONY: all

all: strings stacks

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.PHONY: strings

$(BUILDDIR)/$(STRINGSFILE).o: $(SRCDIR)/$(STRINGSFILE).c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c -I$(INCLUDEDIR) -o $@ $<

$(BUILDDIR)/$(EXAMPLEDIR)/$(STRINGSFILE).out: $(BUILDDIR)/$(STRINGSFILE).o $(EXAMPLEDIR)/$(STRINGSSUBDIR)/$(MAIN)
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $@ $^

strings: $(BUILDDIR)/$(EXAMPLEDIR)/$(STRINGSFILE).out

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.PHONY: array_stack

$(BUILDDIR)/$(ARRAY_STACKFILE).o: $(SRCDIR)/$(ARRAY_STACKFILE).c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c -I$(INCLUDEDIR) -o $@ $<

$(BUILDDIR)/$(EXAMPLEDIR)/$(ARRAY_STACKFILE).out: $(BUILDDIR)/$(ARRAY_STACKFILE).o $(EXAMPLEDIR)/$(STACKSUBDIR)/$(ARRAY_STACK)_$(MAIN)
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $@ $^

array_stack: $(BUILDDIR)/$(EXAMPLEDIR)/$(ARRAY_STACKFILE).out

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.PHONY: linked_stack

$(BUILDDIR)/$(LINKED_STACKFILE).o: $(SRCDIR)/$(LINKED_STACKFILE).c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c -I$(INCLUDEDIR) -o $@ $<

$(BUILDDIR)/$(EXAMPLEDIR)/$(LINKED_STACKFILE).out: $(BUILDDIR)/$(LINKED_STACKFILE).o $(EXAMPLEDIR)/$(STACKSUBDIR)/$(LINKED_STACK)_$(MAIN)
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $@ $^

linked_stack: $(BUILDDIR)/$(EXAMPLEDIR)/$(LINKED_STACKFILE).out

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.PHONY: stacks

stacks: array_stack linked_stack

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.PHONY: clean

clean:
	@rm -rfv build/

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
