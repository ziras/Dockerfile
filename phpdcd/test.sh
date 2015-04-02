#!/usr/bin/env bash

docker build --tag foliolin/phpdcd .
docker run --interactive --rm --tty --volume $PWD:/foliolin/phpdcd foliolin/phpdcd
