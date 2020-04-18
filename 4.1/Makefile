all: build run clean
NAME_PART = 4.1
EXTENSION = c
COMPILER = c89

build:
	cd $(CURDIR)
	gcc -std=$(COMPILER) -c "$(NAME_PART).$(EXTENSION)" -o "$(NAME_PART).o"
	gcc -std=$(COMPILER) "$(NAME_PART).o" -o "$(NAME_PART).exe"

run:
	$(NAME_PART).exe

clean:
	git clean -x -n