image:
	docker build -t foliolin/phalcon:1.3.4 .
bash: image
	docker run --interactive --rm --tty foliolin/phalcon:1.3.4 bash
clean:
	docker rm $(shell docker ps --all --quiet)
	docker rmi $(shell docker images --filter dangling=true --quiet)
