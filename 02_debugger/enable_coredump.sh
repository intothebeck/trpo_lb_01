#!/usr/bin/env bash

ls /var/lib/apport/coredump -alh
ulimit -c ulimited
./a.out
ls /var/lib/apport/coredump -alh
