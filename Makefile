IMAGE_NAME = roman-kata

default:
	@echo "This makefile is used for running:"
	@echo "... build"
	@echo "... run"
	@echo "... start"
	@echo "... attach (type ctrl-p ctrl-q to detach)"
	@echo "... stop"
	@echo "... clean"
	@echo "... test"
.PHONY : default


build:
	@docker build -t roman_docker .
.PHONY : build


run:
	@docker run -it --name=$(IMAGE_NAME) -d roman_docker
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
	@docker exec $(IMAGE_NAME) rm -rf /home/dev/RomanNumeralKataC
	@docker cp ../RomanNumeralKataC $(IMAGE_NAME):/home/dev/
	@docker exec $(IMAGE_NAME) make -C /home/dev/RomanNumeralKataC/make
.PHONY : test
