#!/bin/bash
echo "READY"
socat TCP-LISTEN:8080,nodelay,reuseaddr,fork EXEC:"timeout -s KILL 10m /srv/app/run"
