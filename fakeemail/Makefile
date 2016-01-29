IMAGE=foliolin/fakeemail

container: image
	docker run --interactive --rm --tty -p 3080:8000 ${IMAGE}

image:
	docker build -t ${IMAGE} .
