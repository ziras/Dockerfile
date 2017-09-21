.PHONY: all image run stop clean

all: image run

image:
	docker build -t event-hub .

run:
	docker run -it --rm --name event-hub event-hub

stop:
	docker rm -f event-hub

clean:
	docker rm -f event-hub
	docker rmi -f event-hub
