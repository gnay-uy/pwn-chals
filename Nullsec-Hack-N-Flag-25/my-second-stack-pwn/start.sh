#!/bin/sh
docker run -p 5000:5000 -d --privileged $(docker build -q .)
