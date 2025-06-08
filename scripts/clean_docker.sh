#!/bin/bash

docker rm submodules-build
docker rm saitama-build
docker container prune -f
docker rmi submodules-build:latest
docker rmi saitama-build:latest
docker image prune -f