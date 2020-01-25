#!/bin/bash

python q3.py > t.scm
scheme  < t.scm | grep "=>"
