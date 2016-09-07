CURRENT_DIR = $(shell basename $(CURDIR))
IMAGE_NAME = roman-kata
CONTAINER_NAME = ubuntu-c

default:
	@echo "This makefile is used for building and running the project in Ubuntu-14.04 in a Docker container:"
	@echo "... build"
	@echo "... run"
	@echo "... start"
	@echo "... attach (type ctrl-p ctrl-q to detach)"
	@echo "... stop"
	@echo "... clean"
	@echo "... test"
.PHONY : default


build:
	@docker build -t $(CONTAINER_NAME) .
.PHONY : build


run:
	@docker run -it --name=$(IMAGE_NAME) -d $(CONTAINER_NAME)
.PHONY : run


start:
	@docker start $(IMAGE_NAME)
.PHONY : start


attach:
	@docker attach $(IMAGE_NAME)
.PHONY : attach


stop:
	@docker stop $(IMAGE_NAME)
.PHONY : stop


clean: stop
	@docker rm $(IMAGE_NAME)
.PHONY : clean


test:
	@docker exec $(IMAGE_NAME) rm -rf /home/dev/$(CURRENT_DIR)
	@docker cp ../$(CURRENT_DIR) $(IMAGE_NAME):/home/dev/
	@docker exec $(IMAGE_NAME) make -C /home/dev/$(CURRENT_DIR)/make
.PHONY : test
